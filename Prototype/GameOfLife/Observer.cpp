#include "Observer.h"

Observer::Observer(std::shared_ptr<sf::RenderWindow> window)
    :window(window)
{
}


Observer::~Observer()
{
}

void Observer::handleEvent(sf::Event& event, State& state, Action& action_info)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Escape:
            window->close();
            break;
        case sf::Keyboard::Return:
            state = (state == UPDATE) ? PAUSE : UPDATE;
            break;
        case sf::Keyboard::Right:
            state = UPDATE;
            break;
        case sf::Keyboard::Left:
            state = COME_BACK;
            break;
        }
    }

    if (event.type == sf::Event::KeyReleased)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Right:
        {
            state = PAUSE;
            break;
        }
        case sf::Keyboard::Left:
        {
            state = PAUSE;
            break;
        }
        default:
            break;
        }
    }


    if (event.type == sf::Event::MouseButtonPressed) {

        if ((event.mouseButton.button == sf::Mouse::Left) && (state == PAUSE))
        {
            action_info.updateInfo(sf::Mouse::getPosition(*window).x,
                sf::Mouse::getPosition(*window).y, "UpdateBooth");
            state = MODIFY;
        }
    }

    if (event.type == sf::Event::MouseMoved) {

        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (state == PAUSE))
        {
            action_info.updateInfo(sf::Mouse::getPosition(*window).x,
                sf::Mouse::getPosition(*window).y, "UpdateBooth");
            state = MODIFY;
        }
    }
}
