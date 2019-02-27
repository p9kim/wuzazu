#pragma once
#include "Cell.hpp"
#include "Player.hpp"
#include <vector>

static class EventHandler_
{
private:
	Player* activePlayer = 0;
	Cell* lastCell = 0;
	vector<Cell*> highlightedCells;
public:
	void clickCell(Cell*);
	void activePlayerClickCell(Cell*);
	void clickInactivePlayer(Cell*);
	void activatePlayer(Player*);
	void deactivatePlayer(Player*);
	void hoverCell(Cell*);
} EventHandler;