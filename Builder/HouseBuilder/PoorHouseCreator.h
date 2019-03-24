#ifndef POOR_HOUSE_CREATOR_H
#define POOR_HOUSE_CREATOR_H

#include "HouseCreator.h"

class PoorHouseCreator :public HouseCreator
{
public:
	PoorHouseCreator();
	~PoorHouseCreator();
	virtual void createHouse() override;
	virtual void buildRoof() override;
	virtual void buildFloor() override;
	virtual void buildBasement() override;
	virtual void buildGrass() override;
	virtual void buildStatue() override;
};

#endif
