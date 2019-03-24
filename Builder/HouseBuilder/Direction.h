#ifndef DIRECTION_H
#define DIRECTION_H

#include "House.h"
#include "HouseCreator.h"

class Direction
{
public:
	Direction();
	~Direction();
	std::unique_ptr<House> createHouse(HouseCreator& creater);
};

#endif
