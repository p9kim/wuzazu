#include "Player.hpp"

Rock::Rock(char team)
{
	Player();

	if (team == 'y')
		this->playerTex = textureManager.LoadTexture("assets/rock_y.png");
	else if (team = 'b')
		this->playerTex = textureManager.LoadTexture("assets/rock_b.png");
	else
		cerr << "ERROR: Unknown team to texture correspondance.";
	team_ = team;
}
Paper::Paper(char team)
{
	Player();

	if(team == 'y')
		playerTex = textureManager.LoadTexture("assets/paper_y.png");
	else if(team = 'b')
		playerTex = textureManager.LoadTexture("assets/paper_b.png");
	else
		cerr << "ERROR: Unknown team to texture correspondance.";
	team_ = team;
}
Scissors::Scissors(char team)
{
	Player();

	if (team == 'y')
		playerTex = textureManager.LoadTexture("assets/scissors_y.png");
	else if (team = 'b')
		playerTex = textureManager.LoadTexture("assets/scissors_b.png");
	else
		cerr << "ERROR: Unknown team to texture correspondance.";
	team_ = team;
}