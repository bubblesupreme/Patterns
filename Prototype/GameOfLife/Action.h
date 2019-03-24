#ifndef ACTION_H
#define ACTION_H

#include "Global.h"
#include <string>

class Action
{
public:
    Action(float x_window, float y_window, std::string action_name);
    Action();
    ~Action();
    void updateInfo(float x_window, float y_window, std::string action_name);
    std::string getActionName() const;
    Position getPosition() const;
    void clear();
private:
    Position position;
    std::string action_name;
};

#endif