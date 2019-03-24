#ifndef HOUSE_CREATOR_H
#define HOUSE_CREATOR_H

#include "House.h"

class HouseCreator
{
public:
	HouseCreator();
	~HouseCreator();
	virtual void createHouse() = 0;
	virtual void buildRoof();
	virtual void buildFloor();
	virtual void buildBasement();
	virtual void buildGrass();
	virtual void buildStatue();
	std::unique_ptr<House> getHouse();

protected:
	std::unique_ptr<House> house;
};

#endif
