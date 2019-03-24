#define  _CRT_SECURE_NO_WARNINGS

#include "Game.h"
#include <cstring>
#include<iostream>


Game::Game(std::shared_ptr<sf::RenderWindow> window)
    :window(window), state(PAUSE), observer(Observer(window))
{}


Game::~Game()
{
}

void Game::play()
{
    bool exceptionActiv = false;
    std::exception exception;
    sf::Event event;
    Action action_info;
    while (window->isOpen()) {

        while (window->pollEvent(event)) {

            observer.handleEvent(event, state, action_info);
            if (event.type == sf::Event::Closed)
            {
                window->close();
                return;
            }
        }
        switch (state)
        {
        case UPDATE:
            try
            {
                grid_manager.update();
            }
            catch (std::exception ex)
            {
                std::cout << ex.what() << std::endl;
                state = PAUSE;
            }
            break;
        case COME_BACK:
            grid_manager.comeBack();
            break;
        case MODIFY:
            try
            {
                grid_manager.modify(action_info);
            }
            catch (std::exception ex)
            {
                std::cout << ex.what() << std::endl;
            }
            state = PAUSE;
            break;
        case PAUSE:
            break;
        }
        window->clear();
        grid_manager.draw(*window);

        window->display();

        if (state == UPDATE && grid_manager.checkFigure())
        {
            state = PAUSE;
        }

    }
}
