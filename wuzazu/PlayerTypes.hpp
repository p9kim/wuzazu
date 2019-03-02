#pragma once
#include "Player.hpp"

class Paper : public Player
{ 
public:
	Paper();
	Paper(const char*);
	Paper(const char*, int, int);
	~Paper();
};