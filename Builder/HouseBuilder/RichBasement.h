#ifndef RICH_BASEMENT_H
#define RICH_BASEMENT_H

#include "Basement.h"

class RichBasement: public Basement
{
public:
	RichBasement();
	~RichBasement();
	virtual void draw() override;
};

#endif
