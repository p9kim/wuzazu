#include "readBMP.hpp"
using namespace std;
Pixel::Pixel(unsigned int R, unsigned int G, unsigned int B)
{
	this->R = R;
	this->G = G;
	this->B = B;
}

deque<vector<Pixel*>> Pixel::readBMP(const char* filename)
{
	int i;
	FILE* f = fopen(filename, "rb");

	if (f == NULL)
		throw "Argument Exception";

	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

	// extract image height and width from header
	const int width = *(int*)&info[18];
	const int height = *(int*)&info[22];

	cout << endl;
	cout << "  Name: " << filename << endl;
	cout << " Width: " << width << endl;
	cout << "Height: " << height << endl;

	int row_padded = (width * 3 + 3) & (~3);
	unsigned char* data = new unsigned char[row_padded];
	unsigned char tmp;

	deque<vector<Pixel*>> pixels;
	vector<Pixel*>* row = new vector<Pixel*>();
	for (int i = 0; i < height; i++)
	{
		fread(data, sizeof(unsigned char), row_padded, f);
		for (int j = 0; j < width * 3; j += 3)
		{
			// Convert (B, G, R) to (R, G, B)
			tmp = data[j];
			data[j] = data[j + 2];
			data[j + 2] = tmp;

			//cout <<i<<","<<j<<" " << "R: " << (int)data[j] << " G: " << (int)data[j + 1] << " B: " << (int)data[j + 2] << endl;

			row->push_back(new Pixel((unsigned int)data[j], (unsigned int)data[j + 1], (unsigned int)data[j + 2]));
		}
		pixels.push_front(*row);
		row->clear();
	}
	delete(row);
	fclose(f);
	return pixels;
}