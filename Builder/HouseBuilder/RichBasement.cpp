#include "RichBasement.h"
#include <iostream>

RichBasement::RichBasement()
{
}

RichBasement::~RichBasement()
{
}

void RichBasement::draw()
{
	std::cout << "    |     $     |" << std::endl;
	std::cout << "    -------------" << std::endl;
}