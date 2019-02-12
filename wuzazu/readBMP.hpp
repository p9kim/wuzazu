#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
#include <array>
#include <deque>
#include "Map.hpp"

using namespace std;

class Pixel
{
protected:
	unsigned int R;
	unsigned int G;
	unsigned int B;

public:
	Pixel() : R(0), G(0), B(0) { }
	Pixel(unsigned int, unsigned int, unsigned int);
	unsigned int R();
	unsigned int G();
	unsigned int B();
	~Pixel();

private:

};

deque<vector<Pixel*>> readBMP(Map map, const char* filename);