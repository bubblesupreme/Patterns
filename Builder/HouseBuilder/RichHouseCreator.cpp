#include "RichHouseCreator.h"
#include "RichHouse.h"
#include "RichBasement.h"

RichHouseCreator::RichHouseCreator()
{
}

RichHouseCreator::~RichHouseCreator()
{
}

void RichHouseCreator::createHouse()
{
	this->house = std::make_unique<RichHouse>();
}

void RichHouseCreator::buildRoof()
{
	this->house->addRoof(std::make_unique<Roof>());
}

void RichHouseCreator::buildFloor()
{
	for (int i = 0; i < 3; i++)
	{
		this->house->addFloor(std::make_unique<Floor>());
	}
}

void RichHouseCreator::buildBasement()
{
	this->house->addBasement(std::make_unique<RichBasement>());
	this->house->addDollar(std::make_unique<Dollar>());
}

void RichHouseCreator::buildGrass()
{
	this->house->addGrass(std::make_unique<Grass>());
}

void RichHouseCreator::buildStatue()
{
	for (int i = 0; i < 2; i++)
	{
		this->house->addStatue(std::make_unique<Statue>());
	}
}