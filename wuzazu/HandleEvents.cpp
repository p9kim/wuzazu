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
	Cell* currCell = nullptr;
	if (game->currentTeam() != clickedCell->player()->team() || clickedCell->player()->done())
		return;

	cellQueue.push_back(clickedCell);
	weights[clickedCell] = *(new Int(speed));

	while (!cellQueue.empty())
	{
		currCell = cellQueue.front();
		cellQueue.pop_front();

		if (currCell->N() && (int)weights[currCell->N()].val() < (int)(weights[currCell].val() - currCell->N()->terrain().weight())) //check if N cost is less than curCell-N.weight (-1 to 4 or 3 to 4)
		{
			weights[currCell->N()] = weights[currCell].val() - currCell->N()->terrain().weight(); //update it with the new weight
			if ((int)weights[currCell->N()].val() > -1)		//if we're not done (still movements left)
			{
				highlightedCells.push_back(currCell->N());	//add the new cell to the highlight list
				cellQueue.push_back(currCell->N());			//add it to the queue to traverse
			}
		}
		if (currCell->S() && (int)weights[currCell->S()].val() < (int)(weights[currCell].val() - currCell->S()->terrain().weight())) 
		{
			weights[currCell->S()] = weights[currCell].val() - currCell->S()->terrain().weight();
			if ((int)weights[currCell->S()].val() > -1)
			{
				highlightedCells.push_back(currCell->S());
				cellQueue.push_back(currCell->S());
			}
		}
		if (currCell->E() && (int)weights[currCell->E()].val() < (int)(weights[currCell].val() - currCell->E()->terrain().weight())) 
		{
			weights[currCell->E()] = weights[currCell].val() - currCell->E()->terrain().weight();
			if ((int)weights[currCell->E()].val() > -1)
			{
				highlightedCells.push_back(currCell->E());
				cellQueue.push_back(currCell->E());
			}
		}
		if (currCell->W() && (int)weights[currCell->W()].val() < (int)(weights[currCell].val() - currCell->W()->terrain().weight()))
		{
			weights[currCell->W()] = weights[currCell].val() - currCell->W()->terrain().weight();
			if ((int)weights[currCell->W()].val() > -1)
			{
				highlightedCells.push_back(currCell->W());
				cellQueue.push_back(currCell->W());
			}
		}
	}
	weights.clear();
	activatePlayer(clickedCell->player());
}
void EventHandler_::moveableCells(Cell* from)
{
	for (int i = 0; i < from->terrain().weight(); i++)
	{
		//from->N()->terrain()->weight() = activePlayer->speed();
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

void EventHandler_::setGame(Game* game)
{
	this->game = game;
}
