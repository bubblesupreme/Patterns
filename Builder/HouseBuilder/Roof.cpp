#include "Roof.h"
#include <iostream>

Roof::Roof()
{
}


Roof::~Roof()
{
}

void Roof::draw()
{
	std::cout << "         /\\" << std::endl;
	std::cout << "       /    \\" << std::endl;
	std::cout << "     /        \\" << std::endl;
	std::cout << "    -------------" << std::endl;
}