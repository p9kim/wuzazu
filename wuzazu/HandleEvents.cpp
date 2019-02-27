#include "HandleEvents.hpp"

void EventHandler_::clickCell(Cell* clickedCell)
{
	static Player* activePlayer = nullptr;
	static Cell* lastCell = nullptr;
	static vector<Cell*> highlightedCells;

	if (clickedCell->hasPlayer() && !activePlayer)
	{
		activePlayer = clickedCell->player();
		clickedCell->player()->highlight();
		lastCell = clickedCell;
		highlightedCells.push_back(clickedCell->N());
		highlightedCells.push_back(clickedCell->E());
		highlightedCells.push_back(clickedCell->S());
		highlightedCells.push_back(clickedCell->W());
		for (Cell* c : highlightedCells)
			if(c != 0)
				c->selected = true;

	}
	else if (activePlayer)
	{
		if (clickedCell->player())
			return;
		if (clickedCell == lastCell->N() || clickedCell == lastCell->E()
			|| clickedCell == lastCell->S() || clickedCell == lastCell->W())
		{
			activePlayer->setCanMove(true);
		}
		if (activePlayer->getCanMove() == true)
		{
			lastCell->setPlayer(nullptr);
			clickedCell->setPlayer(activePlayer);
			clickedCell->player()->unhighlight();
			activePlayer->setCanMove(false);
			activePlayer = nullptr;
			lastCell = nullptr;
			for (Cell* c : highlightedCells)
				if (c != 0)
					c->selected = false;
			highlightedCells.clear();
		}
		
	}
}
void EventHandler_::hoverCell(Cell* cell)
{}