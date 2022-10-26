#pragma once

#include "Texture.h"
#include "Vector.h"
#include "Background.h"

class Player
{
public:

	Player(Screen& screen);
	~Player();

	void Update(Screen& screen);
	void Render(Background& background, Screen& screen);

	void SetHealth();
	void SetPoints();

	void RespwanEnemy(Screen& screen);
	void Collider();

	Vector<int> GetPostion();
private:

	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 480;
	const int SPRITE_SIZE = 108;

	bool IsEnemyDead = true;
	
	Texture image;
	
	
	Vector<int> position;
	Vector<int> enemyPos;
	Vector<int> playerWidth;
	Vector<int> playerHeight;
	Vector<int> imageWidth;
	Vector<int> imageHeight;
	

};

