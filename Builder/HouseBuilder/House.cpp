#include "House.h"


House::House() 
{
}


House::~House()
{
}

void House::addRoof(std::unique_ptr<Roof> roof)
{
	this->roof = std::move(roof);
}

void House::addFloor(std::unique_ptr<Floor> floor)
{
	this->floors.push_back(std::move(floor));
}

void House::addBasement(std::unique_ptr<Basement> basement)
{
	this->basement = std::move(basement);
}

void House::addGrass(std::unique_ptr<Grass> grass)
{
	this->grass = std::move(grass);
}

void House::addStatue(std::unique_ptr<Statue> statue)
{
	this->statues.push_back(std::move(statue));
}

void House::addDollar(std::unique_ptr<Dollar> dollar)
{
	this->dollar = std::move(dollar);
}
