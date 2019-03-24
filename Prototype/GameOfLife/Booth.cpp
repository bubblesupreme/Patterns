#include "Booth.h"


Booth::Booth(int x, int y, bool alive, sf::Color alive_color, sf::Color dead_color)
    :alive(alive), alive_color(alive_color), dead_color(dead_color)
{
    shape = sf::RectangleShape(sf::Vector2f(BOOTH_SIZE, BOOTH_SIZE));
    shape.setPosition(sf::Vector2f(y*BOOTH_SIZE, x*BOOTH_SIZE));
    updateColor();
}

Booth::Booth(const Booth& clonable) {
    shape = clonable.shape;
    alive = clonable.alive;
    alive_color = clonable.alive_color;
    dead_color = clonable.dead_color;
}

Booth::~Booth()
{
}

bool Booth::isAlive() const
{
    return alive;
}

void Booth::setAlive(bool alive)
{
    this->alive = alive;
    updateColor();

}

void Booth::updateColor()
{
    if (isAlive())
    {
        shape.setFillColor(alive_color);
        return;
    }
    shape.setFillColor(dead_color);
}

void Booth::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}
