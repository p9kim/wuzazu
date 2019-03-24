#include "HandleEvents.hpp"
#include "Render.hpp"

//////////////////////////// Clicking Cells/Players ////////////////////////////
void EventHandler_::clickCell(Cell* clickedCell)
{
	if (clickedCell->hasPlayer())
	{
		if (activePlayer == clickedCell->player())   //clicked on itself
		{
			deactivatePlayer();
		}
		else if (activePlayer != nullptr && activePlayer != clickedCell->player()) //clicked on another player
		{
			deactivatePlayer();
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
		{
		}
	}
}
void EventHandler_::clickInactivePlayer(Cell* clickedCell)
{
	deque<Cell*> cellQueue;
	lastCell = clickedCell;
	int speed = clickedCell->player()->speed();
	Cell* currCell = nullptr;
	if (game->currentTeam() != *clickedCell->player()->team() || clickedCell->player()->done())
		return;

	cellQueue.push_back(clickedCell);
	weights[clickedCell] = *(new Int(speed));

	auto buildSubTree = [&](Cell* cell)
	{
		if (cell && (int)weights[cell].val() < (int)(weights[currCell].val() - cell->terrain().weight()))
		{
			weights[cell] = weights[currCell].val() - cell->terrain().weight(); //update it with the new weight
			if ((int)weights[cell].val() > -1)		//if we're not done (still movements left)
			{
				highlightedCells.push_back(cell);	//add the new cell to the highlight list
				cellQueue.push_back(cell);			//add it to the queue to traverse
			}
		}
	};

	while (!cellQueue.empty())
	{
		currCell = cellQueue.front();
		cellQueue.pop_front();

		buildSubTree(currCell->N());
		buildSubTree(currCell->E());
		buildSubTree(currCell->S());
		buildSubTree(currCell->W());
	}
	weights.clear();
	activatePlayer(clickedCell->player());
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
		activePlayer->cell(clickedCell);
		activePlayer->setCanMove(false);
		activePlayer->done(true);
		lastCell = nullptr;
		deactivatePlayer();
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
void EventHandler_::deactivatePlayer()
{
	if (activePlayer == 0)
		return;
	activePlayer->active(false);
	activePlayer->unhighlight();
	for (Cell* c : highlightedCells)
		if (c != 0)
			c->selected = false;
	activePlayer = nullptr;
	highlightedCells.clear();
}
////////////////////////////////////////////////////////

void EventHandler_::hoverCell(Cell* cell)
{
	SDL_Rect outlineRect = { (int)cell->x()*42 +1 - renderer->getCamera().x, (int)cell->y()*42 +1 - renderer->getCamera().y, 41, 41 };
	SDL_SetRenderDrawColor(renderer->getRenderer(), 255, 255, 255, 100);
	SDL_RenderDrawRect(renderer->getRenderer(), &outlineRect);
	renderer->RenderPresent();
}

Player* EventHandler_::getActivePlayer()
{
	return activePlayer;
}

void EventHandler_::setGame(Game* game)
{
	this->game = game;
}