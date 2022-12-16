#pragma once

#include "Texture.h"
#include "Vector.h"
#include "GameClass.h"

class Enemy
{
public:
	Enemy(); //Screen& screen
	~Enemy();

	void Update(); //Screen& screen
	void Render(GameClass& background); // Screen& screen
	void RespwanEnemy(); //Screen& screen
	void Collider();

	Vector<int> GetPostion();
private:
	bool IsEnemyDead = true;

	Texture image;
	
	Vector<int> position;
	Vector<int> enemyPos;
	Vector<int> playerWidth;
	Vector<int> playerHeight;
	Vector<int> imageWidth;
	Vector<int> imageHeight;
};