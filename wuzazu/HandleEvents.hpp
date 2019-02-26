#pragma once
#include "Cell.hpp"
#include "Player.hpp"
#include <vector>

static class EventHandler_
{
public:
	void clickCell(Cell*);
	void hoverCell(Cell*);
} EventHandler;