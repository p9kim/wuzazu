#include <string>
#include "Pixel.hpp"
using namespace std;

class Team
{
protected:
	string name_;
	Pixel color;
public:
	string name() {
		return name_;
	};
	bool operator ==(Team other) { return name_ == other.name(); };
	bool operator !=(Team other) { return name_ != other.name(); };
};

static class TeamRed : public Team
{
public:
	TeamRed()
	{
		name_ = "Red Team";
		color = red;
	}
} RedTeam;
static class TeamBlue : public Team
{
public:
	TeamBlue()
	{
		name_ = "Blue Team";
		color = blue;
	}
} BlueTeam;
static class TeamYellow : public Team
{
public:
	TeamYellow()
	{
		name_ = "Yellow Team";
		color = yellow;
	}
} YellowTeam;