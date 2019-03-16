#include "Region.hpp"

void Region::addCell(Cell* cell)
{
	cells.push_back(cell);
}
vector<Cell*> Region::getCells()
{
	return cells;
}
void Region::setOwner(char o)
{
	owner = o;
}
char Region::getOwner()
{
	return owner;
}