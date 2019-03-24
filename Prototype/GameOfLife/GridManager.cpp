#include "GridManager.h"
#include <iostream>

GridManager::GridManager()
{
    grids.push_back(std::make_unique<Grid>(GRID_SIZE.first, GRID_SIZE.second,
        GAME_WITH_GENE));
}


GridManager::~GridManager()
{
}

void GridManager::update()
{
    std::exception exception;
    grids.push_back(grids.back()->clone());
    try
    {
        grids.back()->update();
    }
    catch (std::exception ex)
    {
        throw ex;
    }
}

void GridManager::comeBack()
{
    if (grids.size() > 1)
    {
        grids.pop_back();
    }
}

std::vector<std::shared_ptr<Grid>>& GridManager::getGrids()
{
    return grids;
}

void GridManager::draw(sf::RenderWindow& window)
{
    grids.back()->draw(window);
}

bool GridManager::checkFigure()
{
    if (grids.size() > 1)
    {
        for (int i = 0; i < grids.size() - 1; i++)
        {
            if (*grids.back() == *grids [i])
            {
                std::string str_ex = "Periodic figure\n";
                str_ex += std::to_string(grids.size() - 1 - i) + " period";

                std::cout << str_ex << std::endl;
                return true;
            }
        }
    }
    return false;
}

void GridManager::modify(Action& action_info)
{

    if (action_info.getActionName() == "UpdateBooth")
    {
        int x = action_info.getPosition().first;
        int y = action_info.getPosition().second;
        if ((x >= 0) && (y >= 0) && (x < grids.back()->getSize().first)
            && (y < grids.back()->getSize().second))
        {
            grids.back()->setBoothAt(!grids.back()->isboolAliveAt(y, x), y, x);
        }
    }
    else
    {
        throw  std::exception(("Unknown action " + action_info.getActionName()).c_str());
    }
}