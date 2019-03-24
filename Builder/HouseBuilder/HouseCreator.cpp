#include "HouseCreator.h"


HouseCreator::HouseCreator()
{
}


HouseCreator::~HouseCreator()
{
}

void HouseCreator::buildRoof()
{
}

void HouseCreator::buildFloor()
{
}

void HouseCreator::buildBasement()
{
}

void HouseCreator::buildGrass()
{
}

void HouseCreator::buildStatue()
{
}

std::unique_ptr<House> HouseCreator::getHouse()
{ 
	return std::move(this->house);
}