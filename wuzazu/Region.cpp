#include "Region.hpp"

void Region::addCell(Cell* cell)
{
	cells.push_back(cell);
}
std::vector<Cell*> Region::getCells()
{
	return cells;
}
void Region::setOwner(Team* t)
{
	owner = t;
}
Team* Region::getOwner()
{
	return owner;
}