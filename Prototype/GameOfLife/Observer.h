#ifndef OBSERVER_H
#define OBSERVER_H

#include "Grid.h"
#include "Global.h"
#include <vector>
#include "Action.h"

class Observer
{
public:
    Observer(std::shared_ptr<sf::RenderWindow> window);
    ~Observer();
    void handleEvent(sf::Event& event, State& state, Action& action_info);
private:
    std::shared_ptr<sf::RenderWindow> window;
};

#endif