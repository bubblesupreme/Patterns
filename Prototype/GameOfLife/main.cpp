#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Game.h"

int main ()
{
    auto window = std::make_shared<sf::RenderWindow> 
        (sf::VideoMode (GRID_SIZE.first*BOOTH_SIZE, GRID_SIZE.second*BOOTH_SIZE, 32),
         "Conways Game Of Life", 
         sf::Style::Close);
    Game game (window);
    game.play ();
    return 0;
}

