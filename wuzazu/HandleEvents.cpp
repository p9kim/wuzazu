#include "HandleEvents.hpp"

//////////////////////////// Clicking Cells/Players ////////////////////////////
void EventHandler_::clickCell(Cell* clickedCell)
{
	if (clickedCell->hasPlayer())
	{
		if (activePlayer == clickedCell->player())   //clicked on itself
		{
			deactivatePlayer(clickedCell->player());
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
	deque<Cell*> cellQueue;
	lastCell = clickedCell;
	int speed = clickedCell->player()->speed();
	Cell* currCell = clickedCell;

	cellQueue.push_back(currCell);

	while (!cellQueue.empty())
	{
		highlightedCells.push_back(currCell->N());
		highlightedCells.push_back(currCell->E());
		highlightedCells.push_back(currCell->S());
		highlightedCells.push_back(currCell->W());

		highlightedCells.push_back(cellQueue.front());

	}

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
	if (std::find(highlightedCells.begin(), highlightedCells.end(), clickedCell) 
		!= highlightedCells.end())
	{
		activePlayer->setCanMove(true);
	}
	if (activePlayer->getCanMove() == true) //move player
	{
		lastCell->setPlayer(nullptr);
		clickedCell->setPlayer(activePlayer);
		activePlayer->setCanMove(false);
		activePlayer->done(true);
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
