#ifndef GRID_H
#define GRID_H

#include "Booth.h"
#include <memory>

class Grid
{
public:
    Grid(const size_t width, const size_t height, bool gene);
    Grid(const Grid& clonable);
    ~Grid();
    void setBoothAt(bool alive, int x, int y);
    bool isboolAliveAt(int x, int y) const;
    void update();
    void draw(sf::RenderWindow &window) const;
    bool aliveCount() const;
    std::unique_ptr<Grid> clone();
    void clear();
    const Size getSize() const;
    const std::vector<std::shared_ptr<Booth>>& getBoothes() const;
private:
    size_t width;
    size_t height;
    std::vector<std::shared_ptr<Booth>> boothes;
};

bool operator==(const Grid& lhs, const Grid& rhs);

#endif