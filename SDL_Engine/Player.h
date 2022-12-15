#pragma once

#include "Texture.h"
#include "Vector.h"
#include "Enemy.h"
//TODO - Does this class have much use, as most of the code refers to player?
class Animations
{
public:
	Animations(Screen& screen);
	~Animations();

	void Update(Vector<int> playerPosition);
	void Render(Screen& screen, Background& background);
	void Unload();

	Vector<int> GetPostion();
private:
	int velocity;
	//TODO - You could create a Portal class?
	//TODO - Move this to the Player class===============
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
	//===================================================
};
