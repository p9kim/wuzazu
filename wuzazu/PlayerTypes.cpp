#include "Player.hpp"

Rock::Rock(Team team)
{
	Player();
	team_ = &team;
	if (team.name() == "Yellow Team")
		this->playerTex = textureManager.LoadTexture("assets/rock_y.png");
	else if (team.name() == "Blue Team")
		this->playerTex = textureManager.LoadTexture("assets/rock_b.png");
	else
		cerr << "ERROR: Unknown team to texture correspondance.";
}
Paper::Paper(Team team)
{
	Player();
	team_ = &team;
	if (team.name() == "Yellow Team")
		this->playerTex = textureManager.LoadTexture("assets/paper_y.png");
	else if (team.name() == "Blue Team")
		this->playerTex = textureManager.LoadTexture("assets/paper_b.png");
	else
		cerr << "ERROR: Unknown team to texture correspondance.";
}
Scissors::Scissors(Team team)
{
	Player();
	team_ = &team;
	if (team.name() == "Yellow Team")
		this->playerTex = textureManager.LoadTexture("assets/scissors_y.png");
	else if (team.name() == "Blue Team")
		this->playerTex = textureManager.LoadTexture("assets/scissors_b.png");
	else
		cerr << "ERROR: Unknown team to texture correspondance.";
}