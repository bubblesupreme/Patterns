#include "GeneBooth.h"

sf::Color calculateColor(const std::vector<char>& gene)
{
    int r = 10;
    int g = 10;
    int b = 10;
    std::vector<int> rgb(3);
    for (int i = 0; i < gene.size(); i++)
    {
        if (gene [i])
        {
            rgb [i % 3] += 80;
        }
    }
    return sf::Color(rgb [0], rgb [1], rgb [2]);
}

sf::Color calculateColor()
{
    return sf::Color(90, 90, 90);
}

GeneBooth::GeneBooth(int x, int y, bool alive, std::vector<char> gene)
    :Booth(x, y, alive, calculateColor(gene), sf::Color(242, 240, 240)), gene(gene)
{
    updateColor();
}

GeneBooth::GeneBooth(int x, int y, bool alive)
    : Booth(x, y, alive, sf::Color(90, 86, 209), sf::Color(242, 240, 240))
{
    gene = std::vector<char>(9);
}

GeneBooth::~GeneBooth()
{
}

GeneBooth::GeneBooth(const GeneBooth& clonable)
    :Booth(clonable)
{
    gene = clonable.gene;
}

std::vector<char> GeneBooth::getGene() const
{
    return gene;
}

std::unique_ptr<Booth> GeneBooth::clone()
{
    return std::make_unique<GeneBooth>(*this);
}

bool GeneBooth::operator==(const Booth& booth)
{
    auto gene_booth = dynamic_cast<const GeneBooth*>(&booth);
    if (gene_booth == nullptr)
        return false;
    return (isAlive() == gene_booth->isAlive() && gene == gene_booth->gene);
}