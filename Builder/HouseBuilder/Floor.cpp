#include "Floor.h"
#include <iostream>

Floor::Floor()
{
}


Floor::~Floor()
{
}

void Floor::draw()
{
	std::cout << "    |     _     |" << std::endl;
	std::cout << "    |    |_|    |" << std::endl;
	std::cout << "    |           |" << std::endl;
	std::cout << "    -------------" << std::endl;
}