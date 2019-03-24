#include "Grid.h"
#include "GeneBooth.h"
#include "SimpleBooth.h"

Grid::Grid(const size_t width, const size_t height, bool gene)
    :width(width), height(height)
{
    boothes = std::vector<std::shared_ptr<Booth>>(width*height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (gene)
            {
                std::vector<char> booth_gene(9);
                for (int i = 0; i < 9; i++)
                {
                    booth_gene [i] = rand() % 2;
                }
                boothes [i*width + j] = std::make_unique<GeneBooth>(i, j, false, booth_gene);
            }
            else
            {
                boothes [i*width + j] = std::make_unique<SimpleBooth>(i, j, false);
            }
        }
    }

}

Grid::~Grid()
{}

void Grid::setBoothAt(bool alive, int x, int y)
{
    boothes.at(x*width + y)->setAlive(alive);
}

bool Grid::isboolAliveAt(int x, int y) const
{
    return boothes.at(x*width + y)->isAlive();
}

void Grid::draw(sf::RenderWindow &window) const
{
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            boothes.at(x*width + y)->updateColor();
            boothes.at(x*width + y)->draw(window);
        }
    }
}

Grid::Grid(const Grid& clonable)
{
    width = clonable.width;
    height = clonable.height;
    boothes = std::vector<std::shared_ptr<Booth>>(width*height);
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            boothes [x*width + y] = clonable.boothes.at(x*width + y)->clone();
        }
    }
}

bool Grid::aliveCount() const
{
    int count = 0;
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            if (boothes.at(x*width + y)->isAlive())
            {
                count++;
            }
        }
    }
    return count;
}

void Grid::clear()
{
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            boothes.at(x*width + y)->setAlive(false);
        }
    }
}

const Size Grid::getSize() const
{
    return Size(width, height);
}

std::unique_ptr<Grid> Grid::clone()
{
    return std::make_unique<Grid>(*this);
}

void check_neighbour(int& counter, std::shared_ptr<Booth> neighbour)
{
    counter = (neighbour->isAlive()) ? counter + 1 : counter;
};

void Grid::update()
{
    std::vector<char> boothesToDie(width*height);
    std::vector<char>  boothesToGetLive(width*height);

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {

            int neighbours = 0;

            if ((x == 0) && (y == 0)) {
                check_neighbour(neighbours, boothes.at((x + 1)*width + y));
                check_neighbour(neighbours, boothes.at((x + 1)*width + y + 1));
                check_neighbour(neighbours, boothes.at(x*width + y + 1));
            }

            else if ((x == height - 1) && (y == 0)) {
                check_neighbour(neighbours, boothes.at((x - 1)*width + y));
                check_neighbour(neighbours, boothes.at((x - 1)*width + y + 1));
                check_neighbour(neighbours, boothes.at(x*width + y + 1));
            }

            else if ((x == 0) && (y == width - 1)) {
                check_neighbour(neighbours, boothes.at((x + 1)*width + y));
                check_neighbour(neighbours, boothes.at((x + 1)*width + y - 1));
                check_neighbour(neighbours, boothes.at(x*width + y - 1));
            }

            else if ((x == height - 1) && (y == width - 1)) {
                check_neighbour(neighbours, boothes.at((x - 1)*width + y));
                check_neighbour(neighbours, boothes.at((x - 1)*width + y - 1));
                check_neighbour(neighbours, boothes.at(x*width + y - 1));
            }

            else if (x == 0) {
                check_neighbour(neighbours, boothes.at((x + 1)*width + y - 1));
                check_neighbour(neighbours, boothes.at((x + 1)*width + y));
                check_neighbour(neighbours, boothes.at((x + 1)*width + y + 1));

                check_neighbour(neighbours, boothes.at(x*width + y - 1));
                check_neighbour(neighbours, boothes.at(x*width + y + 1));
            }

            else if (x == height - 1) {
                check_neighbour(neighbours, boothes.at((x - 1)*width + y - 1));
                check_neighbour(neighbours, boothes.at((x - 1)*width + y));
                check_neighbour(neighbours, boothes.at((x - 1)*width + y + 1));

                check_neighbour(neighbours, boothes.at(x*width + y - 1));
                check_neighbour(neighbours, boothes.at(x*width + y + 1));
            }

            else if (y == 0)
            {
                check_neighbour(neighbours, boothes.at((x - 1)*width + y + 1));
                check_neighbour(neighbours, boothes.at(x*width + y + 1));
                check_neighbour(neighbours, boothes.at((x + 1)*width + y + 1));

                check_neighbour(neighbours, boothes.at((x - 1)*width + y));
                check_neighbour(neighbours, boothes.at((x + 1)*width + y));
            }

            else if (y == width - 1) {
                check_neighbour(neighbours, boothes.at((x - 1)*width + y - 1));
                check_neighbour(neighbours, boothes.at(x*width + y - 1));
                check_neighbour(neighbours, boothes.at((x + 1)*width + y - 1));

                check_neighbour(neighbours, boothes.at((x - 1)*width + y));
                check_neighbour(neighbours, boothes.at((x + 1)*width + y));
            }

            else {
                check_neighbour(neighbours, boothes.at((x - 1)*width + y - 1));
                check_neighbour(neighbours, boothes.at((x - 1)*width + y));
                check_neighbour(neighbours, boothes.at((x - 1)*width + y + 1));

                check_neighbour(neighbours, boothes.at(x*width + y - 1));
                check_neighbour(neighbours, boothes.at(x*width + y + 1));

                check_neighbour(neighbours, boothes.at((x + 1)*width + y - 1));
                check_neighbour(neighbours, boothes.at((x + 1)*width + y));
                check_neighbour(neighbours, boothes.at((x + 1)*width + y + 1));
            }

            if (boothes.at(x*width + y)->isAlive()) {
                if ((neighbours != 2) && (neighbours != 3)) {
                    boothesToDie [x*width + y] = true;
                }
            }

            else {
                if (neighbours == 3) {
                    boothesToGetLive [x*width + y] = true;
                }
            }
        }
    }

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            if (boothesToDie [x*width + y]) {
                boothes.at(x*width + y)->setAlive(false);
            }
            if (boothesToGetLive [x*width + y]) {
                boothes.at(x*width + y)->setAlive(true);
            }
        }
    }
    if (aliveCount() == 0)
    {
        throw std::exception("Died!\n0 cells is alive");
    }
}

const std::vector<std::shared_ptr<Booth>>& Grid::getBoothes() const
{
    return boothes;
}

bool operator==(const Grid& lhs, const Grid& rhs)
{
    if (lhs.getSize() == rhs.getSize())
    {
        size_t width = lhs.getSize().first;
        size_t height = lhs.getSize().second;
        for (int x = 0; x < height; x++)
        {
            for (int y = 0; y < width; y++)
            {
                if (!(*lhs.getBoothes().at(x*width + y) ==
                    *rhs.getBoothes().at(x*width + y)))
                {
                    return false;
                }
            }
        }
    }
    return true;
}