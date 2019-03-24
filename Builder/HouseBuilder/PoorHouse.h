#ifndef POOR_HOUSE_H
#define POOR_HOUSE_H

#include "House.h"

class PoorHouse : public House
{
public:
	PoorHouse();
	~PoorHouse();
	virtual void draw() override;
};

#endif
