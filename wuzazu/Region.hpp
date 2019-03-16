#pragma once
#include <vector>

class Cell;
class Team;

class Region
{
private:
	std::vector<Cell*> cells;
	Team* owner;
public:
	void addCell(Cell*);
	std::vector<Cell*> getCells();
	void setOwner(Team*);
	Team* getOwner();
};