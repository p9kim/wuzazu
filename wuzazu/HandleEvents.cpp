#include "HandleEvents.hpp"

void EventHandler_::clickCell(Cell* clickedCell)
{
	static Player* activePlayer = nullptr;
	static Cell* lastCell = nullptr;
	clickedCell->drawSelected();
	if (clickedCell->hasPlayer() && !activePlayer)
	{
		activePlayer = clickedCell->player();
		clickedCell->player()->highlight();
		lastCell = clickedCell;
	}
	else if (activePlayer)
	{
		if (clickedCell->player())
			return;
		lastCell->setPlayer(nullptr);
		clickedCell->setPlayer(activePlayer);
		clickedCell->player()->unhighlight();
		activePlayer = nullptr;
		lastCell = nullptr;
	}
}
void EventHandler_::hoverCell(Cell* cell)
{}