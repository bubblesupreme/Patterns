#ifndef RICH_HOUSE_CREATOR_H
#define RICH_HOUSE_CREATOR_H

#include "HouseCreator.h"

class RichHouseCreator :public HouseCreator
{
public:
	RichHouseCreator();
	~RichHouseCreator();
	virtual void createHouse() override;
	virtual void buildRoof() override;
	virtual void buildFloor() override;
	virtual void buildBasement() override;
	virtual void buildGrass() override;
	virtual void buildStatue() override;
};

#endif