#include "Action.h"

Action::Action(float x_window, float y_window, std::string action_name)
    :action_name(action_name)
{
    position = Position(x_window / BOOTH_SIZE, y_window / BOOTH_SIZE);
}

Action::Action()
{
}

void Action::updateInfo(float x_window, float y_window, std::string action_name)
{
    this->action_name = action_name;
    position = Position(x_window / BOOTH_SIZE, y_window / BOOTH_SIZE);
}

Action::~Action()
{
}

std::string Action::getActionName() const
{
    return action_name;
}

Position Action::getPosition() const
{
    return position;
}

void Action::clear()
{
    action_name = "";
    position = Position(0, 0);
}
