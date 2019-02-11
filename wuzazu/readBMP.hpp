#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iterator>

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

	/*std::vector<std::vector<Pixel>>*/std::vector<char> readBMP(const std::string &file);

private:

};