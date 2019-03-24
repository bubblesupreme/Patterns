#include "RichHouse.h"
#include <iostream>

RichHouse::RichHouse()
{
}

RichHouse::~RichHouse()
{
}

void RichHouse::draw() 
{
	std::cout << "This is rich house\n";
	dollar->draw();
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