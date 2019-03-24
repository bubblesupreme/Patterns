#include "Direction.h"
#include "PoorHouseCreator.h"
#include "RichHouseCreator.h"
#include <iostream>

void main()
{
	Direction direction;
	RichHouseCreator rich_creator;
	PoorHouseCreator poor_creator;
	std::unique_ptr<House> rich_house = direction.createHouse(rich_creator);
	std::unique_ptr<House> poor_house = direction.createHouse(poor_creator);
	rich_house->draw();
	std::cout << "\n\n";
	poor_house->draw();
}