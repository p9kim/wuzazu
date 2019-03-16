#include "Pixel.hpp"
#include <string>
#include <vector>
using namespace std;

class Team
{
protected:
	string name_;
	Pixel color_;
	static vector<Team>* teams_;
public:
	string name() { return name_; };
	Pixel color() { return color_; };
	static void setTeams(vector<Team>* t) { teams_ = t; };
	static vector<Team>* teams() { return teams_; };
	bool operator ==(Team other) { return name_ == other.name(); };
	bool operator !=(Team other) { return name_ != other.name(); };
};

static class TeamRed : public Team
{
public:
	TeamRed()
	{
		name_ = "Red Team";
		color_ = red;
	}
} RedTeam;
static class TeamBlue : public Team
{
public:
	TeamBlue()
	{
		name_ = "Blue Team";
		color_ = blue;
	}
} BlueTeam;
static class TeamYellow : public Team
{
public:
	TeamYellow()
	{
		name_ = "Yellow Team";
		color_ = yellow;
	}
} YellowTeam;