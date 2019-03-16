#pragma once
#include <vector>
using namespace std;

class Cell;

class Region
{
private:
	vector<Cell*> cells;
	char owner;
public:
	void addCell(Cell*);
	vector<Cell*> getCells();
	void setOwner(char);
	char getOwner();
};