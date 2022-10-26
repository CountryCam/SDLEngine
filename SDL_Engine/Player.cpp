#include "Player.h"
#include "Input.h"
#include "Screen.h"
#include "Animations.h"


Player::Player(Screen& screen)
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

Player::~Player()
{
	//image.Unload();
}

void Player::Update(Screen& screen)
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
	else if (position.x > SCREEN_WIDTH - SPRITE_SIZE)
	{
		position.x = SCREEN_WIDTH - SPRITE_SIZE;
	}
	if (position.y < 0)
	{
		position.y = 0;
	}
	else if (position.y > SCREEN_HEIGHT - SPRITE_SIZE)
	{
		position.y = SCREEN_HEIGHT - SPRITE_SIZE;
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

void Player::Render(Background& background, Screen& screen)
{
	if (!background.GetBackground())
	{
		
		return;
	}
	image.Render(screen, enemyPos.x, enemyPos.y);
	
	

}

void Player::SetHealth()
{

}

void Player::SetPoints()
{

}

void Player::RespwanEnemy(Screen& screen)
{
	if (IsEnemyDead == true)
	{
		//Respawn the Enemy Character && Set back to IsEnemyDead to false
		image.Render(screen, enemyPos.x + 45, enemyPos.y);
		IsEnemyDead = false;
	}
	
}

void Player::Collider()
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

Vector<int> Player::GetPostion()
{
	return position;
}
