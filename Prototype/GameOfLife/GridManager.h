#ifndef GRID_MANAGER_H
#define GRID_MANAGER_H

#include "Grid.h"
#include "Action.h"

class GridManager
{
public:
    GridManager();
    ~GridManager();
    void update();
    void comeBack();
    void draw(sf::RenderWindow& window);
    bool checkFigure();
    void modify(Action& action_info);
    std::vector<std::shared_ptr<Grid>>& getGrids();
private:
    std::vector<std::shared_ptr<Grid>> grids;
};

#endif