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
		color = red;
	}
} Red;
static class BlueTeam : public Team
{
public:
	BlueTeam()
	{
		name = "Blue Team";
		color = blue;
	}
} Red;
static class YellowTeam : public Team
{
public:
	YellowTeam()
	{
		name = "Yellow Team";
		color = yellow;
	}
} Red;