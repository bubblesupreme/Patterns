#include "Direction.h"


Direction::Direction()
{
}


Direction::~Direction()
{
}

std::unique_ptr<House> Direction::createHouse(HouseCreator& creator)
{
	creator.createHouse();
	creator.buildRoof();
	creator.buildFloor();
	creator.buildGrass();
	creator.buildBasement();
	creator.buildStatue();
	return creator.getHouse();
}