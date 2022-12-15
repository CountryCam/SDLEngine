#pragma once

#include "Texture.h"
#include "Vector.h"
#include "Enemy.h"

class Player
{
public:
	Player(Screen& screen);
	~Player();

	void Update(Vector<int> playerPosition);
	void Render(Screen& screen, GameClass& background);
	void Unload();

	Vector<int> GetPostionPlayer();
private:
	int velocity;
	//TODO - You could create a Portal class? (Cameron) "Once I manage to get my animation working properly again i will for sure"
	Texture portal;
	Texture playerRun;
	Texture playerIdle;

	Vector<int> positionPortal;
	Vector<int> positionPlayer;
	Vector<int> directionWalk;
	Vector<int> directionStand;

	bool portalActive = false;
	bool playerActive = true;
	bool playerMoveRight = false;
};
