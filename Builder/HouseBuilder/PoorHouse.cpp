#include "PoorHouse.h"
#include <iostream>

PoorHouse::PoorHouse()
{
}


PoorHouse::~PoorHouse()
{
}

void PoorHouse::draw() 
{
	std::cout << "This is poor house\n";
	roof->draw();
	for (const auto& floor : floors)
	{
		floor->draw();
	}
	for (const auto& statue : statues)
	{
		statue->draw();
		std::cout << "                ";
	}
	std::cout << "\n";
	grass->draw();
	basement->draw();
}