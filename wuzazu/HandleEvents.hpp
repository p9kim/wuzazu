#pragma once
#include "Cell.hpp"
#include "Player.hpp"
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_map>

class Int
{
	int i = -1;
public:
	Int() { i = -1; };
	Int(int i) { this->i = i; };
	int val() { return i; };
	void val(int i) { this->i = i; };
};

static class EventHandler_
{
private:
	Player* activePlayer = 0;
	Cell* lastCell = 0;
	vector<Cell*> highlightedCells;
	unordered_map<Cell*, Int> weights;
	Game* game;
public:
	void clickCell(Cell*);
	void activePlayerClickCell(Cell*);
	void clickInactivePlayer(Cell*);
	void activatePlayer(Player*);
	void deactivatePlayer(Player*);
	void hoverCell(Cell*);
	void setGame(Game*);
} EventHandler;