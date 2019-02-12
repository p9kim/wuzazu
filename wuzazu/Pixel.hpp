#pragma once
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

