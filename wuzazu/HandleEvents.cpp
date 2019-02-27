#include "HandleEvents.hpp"

//////////////////////////// Clicking Cells/Players ////////////////////////////
void EventHandler_::clickCell(Cell* clickedCell)
{
	if (clickedCell->hasPlayer())
	{
		if (activePlayer == clickedCell->player())   //clicked on itself
		{
			deactivatePlayer(clickedCell->player());
			return;
		}
		else if (activePlayer != nullptr && activePlayer != clickedCell->player()) //clicked on another player
		{
			deactivatePlayer(activePlayer);
			clickInactivePlayer(clickedCell);
		}
		else  //click on inactive player w nothing selected
		{
			clickInactivePlayer(clickedCell);
		}
	}
	else //clicked empty cell
	{
		if (activePlayer != 0) //active player clicks empty cell
		{
			activePlayerClickCell(clickedCell);
		}
		else //clicked empty cell while nothing active
		{}
	}
}
void EventHandler_::clickInactivePlayer(Cell* clickedCell)
{
	lastCell = clickedCell;
	highlightedCells.push_back(clickedCell->N());
	highlightedCells.push_back(clickedCell->E());
	highlightedCells.push_back(clickedCell->S());
	highlightedCells.push_back(clickedCell->W());
	activatePlayer(clickedCell->player());

}
void EventHandler_::moveableCells(Cell* from)
{
	from->weight = activePlayer->speed();
	for (int i = 0; i < from->weight; i++)
	{
		//from->N()->weight = activePlayer->speed();
	}
}
void EventHandler_::activePlayerClickCell(Cell* clickedCell)
{
	if (clickedCell == lastCell->N() || clickedCell == lastCell->E()
		|| clickedCell == lastCell->S() || clickedCell == lastCell->W())
	{
		activePlayer->setCanMove(true);
	}
	if (activePlayer->getCanMove() == true) //move player
	{
		lastCell->setPlayer(nullptr);
		clickedCell->setPlayer(activePlayer);
		activePlayer->setCanMove(false);
		lastCell = nullptr;
		deactivatePlayer(activePlayer);
	}
}
void EventHandler_::activatePlayer(Player* player)
{
	activePlayer = player;
	player->active(true);
	player->highlight();
	for (Cell* c : highlightedCells)
		if (c != 0)
			c->selected = true;
}
void EventHandler_::deactivatePlayer(Player* player)
{
	player->active(false);
	player->unhighlight();
	for (Cell* c : highlightedCells)
		if (c != 0)
			c->selected = false;
	activePlayer = nullptr;
	highlightedCells.clear();
}
////////////////////////////////////////////////////////


void EventHandler_::hoverCell(Cell* cell)
{}
