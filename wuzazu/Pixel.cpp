#pragma once
#include "Pixel.hpp"

using namespace std;
Pixel::Pixel(unsigned int R, unsigned int G, unsigned int B)
{
	this->r = R;
	this->g = G;
	this->b = B;
}

unsigned int Pixel::R()
{
	return this->r;
}
unsigned int Pixel::G()
{
	return this->g;
}
unsigned int Pixel::B()
{
	return this->b;
}