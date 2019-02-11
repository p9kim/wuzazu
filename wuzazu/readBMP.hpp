#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iterator>

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
	~Pixel();

	vector<vector<Pixel*>> readBMP(const char* filename);

private:

};