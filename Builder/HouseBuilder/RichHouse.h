#ifndef RICH_HOUSE_H
#define RICH_HOUSE_H

#include "House.h"

class RichHouse: public House
{
public:
	RichHouse();
	~RichHouse();
	virtual void draw() override;
};

#endif
