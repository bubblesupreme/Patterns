#include "PoorHouseCreator.h"
#include "PoorHouse.h"

PoorHouseCreator::PoorHouseCreator()
{
}

PoorHouseCreator::~PoorHouseCreator()
{
}

void PoorHouseCreator::createHouse()
{
	this->house = std::make_unique<PoorHouse>();
}

void PoorHouseCreator::buildRoof()
{
	this->house->addRoof(std::make_unique<Roof>());
};

void PoorHouseCreator::buildFloor()
{
	for (int i = 0; i < 1; i++)
	{
		this->house->addFloor(std::make_unique<Floor>());
	}
};

void PoorHouseCreator::buildBasement()
{
	this->house->addBasement(std::make_unique<Basement>());
};

void PoorHouseCreator::buildGrass()
{
	this->house->addGrass(std::make_unique<Grass>());
};

void PoorHouseCreator::buildStatue()
{
	for (int i = 0; i < 1; i++)
	{
		this->house->addStatue(std::make_unique<Statue>());
	}
};