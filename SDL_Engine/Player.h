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
	
	Texture m_image;
	
	
	Vector<int> m_position;
	Vector<int> m_EnemyPos;
	Vector<int> m_PlayerWidth;
	Vector<int> m_PlayerHeight;
	Vector<int> m_imageWidth;
	Vector<int> m_imageHeight;
	

};

