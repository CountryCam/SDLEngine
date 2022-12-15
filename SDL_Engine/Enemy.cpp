#include "Enemy.h"
#include "Input.h"
#include "Screen.h"
#include "Player.h"


Enemy::Enemy(Screen& screen)
{
	image.Load("Images/BurlyMan1.png", screen);
	image.SetTextureDimension(140, 240);
	image.SetSourceDimension(1, 1, 140, 240);

	position.x = 5;
	position.y = 350;
	playerWidth = 140;
	playerHeight = 171;

	enemyPos.x = 400;
	enemyPos.y = 350;
}

Enemy::~Enemy()
{
	image.Unload();
}

void Enemy::Update(Screen& screen)
{
	

	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE))
	{
		SDL_Quit();
	}

	if ((Input::Instance()->IsKeyPressed(HM_KEY_W) || (Input::Instance()->IsKeyPressed(HM_KEY_UP) == true)))
	{
		position.y -= 0;
	}

	if ((Input::Instance()->IsKeyPressed(HM_KEY_S) || (Input::Instance()->IsKeyPressed(HM_KEY_DOWN) == true)))
	{
		position.y += 0;
	}

	if ((Input::Instance()->IsKeyPressed(HM_KEY_LEFT) || (Input::Instance()->IsKeyPressed(HM_KEY_A) == true)))
	{
		position.x -= 1;
	}

	if ((Input::Instance()->IsKeyPressed(HM_KEY_RIGHT) || (Input::Instance()->IsKeyPressed(HM_KEY_D) == true)))
	{
		position.x += 1;
	}

	if (position.x < 0)
	{
		position.x = 0;
	}

	if (IsEnemyDead == false)
	{
		Collider();
	}
	else if (IsEnemyDead == true)
	{
		RespwanEnemy(screen);
	}
	
}

void Enemy::Render(GameClass& background, Screen& screen)
{
	if (!background.GetBackground())
	{
		
		return;
	}
	image.Render(screen, enemyPos.x, enemyPos.y);
}




void Enemy::RespwanEnemy(Screen& screen)
{
	if (IsEnemyDead == true)
	{
		//Respawn the Enemy Character && Set back to IsEnemyDead to false
		image.Render(screen, enemyPos.x + 45, enemyPos.y);
		IsEnemyDead = false;
	}
	
}

void Enemy::Collider()
{

	Vector<int> PlayerCol, EnemyCol;
	PlayerCol.x = position.x + playerWidth.x;
	PlayerCol.y = position.y + playerHeight.y;

	EnemyCol.x = enemyPos.x + imageWidth.x;
	EnemyCol.y = enemyPos.y + imageHeight.y;

	if (PlayerCol.x >= EnemyCol.x && PlayerCol.y >= EnemyCol.y)
	{
		image.Unload();
		IsEnemyDead = true;
	}
}

Vector<int> Enemy::GetPostion()
{
	return position;
}
