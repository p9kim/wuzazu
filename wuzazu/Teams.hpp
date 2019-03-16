#include <string>
#include "Pixel.hpp"
using namespace std;

class Team
{
protected:
	string name;
	Pixel color;
public:
	void getTeam(string);
};

static class RedTeam : public Team
{
public:
	RedTeam()
	{
		name = "Red Team";
	}
} Red;