#ifndef Game_H
#define Game_H

#include "Observer.h"
#include "GridManager.h"

class Game
{
public:
    Game(std::shared_ptr<sf::RenderWindow> window);
    ~Game();
    void play();
private:
    std::shared_ptr<sf::RenderWindow> window;
    State state;
    GridManager grid_manager;
    Observer observer;
};

#endif