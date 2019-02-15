#pragma once
#include <iostream>
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
	bool operator ==(Pixel other) const
	{
		return other.r == r && other.g == g && other.b == b;
	}
};

class Red : public Pixel
{
public:
	Red() {r = 255;}
};
class Green : public Pixel
{
public:
	Green() { g = 255; }
};
class Blue : public Pixel
{
public:
	Blue() { b = 255; }
};
class Yellow : public Pixel
{
public:
	Yellow() { r = 255; g = 255; }
};