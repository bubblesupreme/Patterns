#ifndef HOUSE_H
#define HOUSE_H

#include "Basement.h"
#include "Floor.h"
#include "Grass.h"
#include "Roof.h"
#include "Statue.h"
#include "Dollar.h"
#include <vector>
#include <memory>

class House
{
public:
	House();
	~House();
	virtual void draw() = 0;
	void addRoof(std::unique_ptr<Roof> roof);
	void addFloor(std::unique_ptr<Floor> floor);
	void addBasement(std::unique_ptr<Basement> basement);
	void addGrass(std::unique_ptr<Grass> grass);
	void addStatue(std::unique_ptr<Statue> statue);
	void addDollar(std::unique_ptr<Dollar> dollar);
protected:
	std::unique_ptr<Roof> roof;
	std::vector<std::unique_ptr<Floor>> floors;
	std::unique_ptr<Basement> basement;
	std::unique_ptr<Grass> grass;
	std::vector<std::unique_ptr<Statue>> statues;
	std::unique_ptr<Dollar> dollar;
};

#endif
