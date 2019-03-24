#ifndef BOOTH_H
#define BOOTH_H

#include<SFML\Graphics.hpp>
#include "Global.h"
#include <memory>

class Booth
{
public:
    Booth(int x, int y, bool alive, sf::Color alive_color, sf::Color dead_color);
    Booth(const Booth& clonable);
    virtual ~Booth();
    bool isAlive() const;
    void setAlive(bool alive);
    void draw(sf::RenderWindow& window) const;
    void updateColor();
    virtual std::unique_ptr<Booth> clone() = 0;
    virtual bool operator==(const Booth& booth) = 0;
protected:
    bool alive;
    sf::RectangleShape shape;
    sf::Color alive_color;
    sf::Color dead_color;
};

#endif