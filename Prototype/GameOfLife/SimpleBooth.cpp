#include "SimpleBooth.h"

SimpleBooth::SimpleBooth(int x, int y, bool alive)
    :Booth(x, y, alive, sf::Color(90, 86, 209), sf::Color(242, 240, 240))
{
    updateColor();
}


SimpleBooth::~SimpleBooth()
{
}

SimpleBooth::SimpleBooth(const SimpleBooth& clonable)
    :Booth(clonable)
{
}

std::unique_ptr<Booth> SimpleBooth::clone()
{
    return std::make_unique<SimpleBooth>(*this);
}

bool SimpleBooth::operator==(const Booth& booth)
{
    auto simple_booth = dynamic_cast<const SimpleBooth*>(&booth);
    if (simple_booth == nullptr)
        return false;
    return isAlive() == simple_booth->isAlive();
}