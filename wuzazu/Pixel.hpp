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

using namespace std;

class Pixel
{
protected:
	unsigned int r;
	unsigned int g;
	unsigned int b;

public:
	Pixel() : r(0), g(0), b(0) { }
	Pixel(unsigned int, unsigned int, unsigned int);
	unsigned int R();
	unsigned int G();
	unsigned int B();
	~Pixel();

private:

};

