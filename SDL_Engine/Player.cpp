#include "Player.h"
#include "Input.h"
#include "Screen.h"
#include "Animations.h"


Player::Player(Screen& screen)
{

	m_image.Load("Images/BurlyMan1.png", screen);
	m_image.SetTextureDimension(140, 240);
	m_image.SetSourceDimension(1, 1, 140, 240);

	m_position.x = 5;
	m_position.y = 350;
	m_PlayerWidth = 140;
	m_PlayerHeight = 171;

	m_EnemyPos.x = 400;
	m_EnemyPos.y = 350;

	
}

Player::~Player()
{
	//m_image.Unload();
}

void Player::Update(Screen& screen)
{
	

	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE))
	{
		SDL_Quit();
	}

	if ((Input::Instance()->IsKeyPressed(HM_KEY_W) || (Input::Instance()->IsKeyPressed(HM_KEY_UP) == true)))
	{
		m_position.y -= 0;
	}

	if ((Input::Instance()->IsKeyPressed(HM_KEY_S) || (Input::Instance()->IsKeyPressed(HM_KEY_DOWN) == true)))
	{
		m_position.y += 0;
	}

	if ((Input::Instance()->IsKeyPressed(HM_KEY_LEFT) || (Input::Instance()->IsKeyPressed(HM_KEY_A) == true)))
	{
		m_position.x -= 1;
	}

	if ((Input::Instance()->IsKeyPressed(HM_KEY_RIGHT) || (Input::Instance()->IsKeyPressed(HM_KEY_D) == true)))
	{
		m_position.x += 1;
	}

	if (m_position.x < 0)
	{
		m_position.x = 0;
	}
	else if (m_position.x > SCREEN_WIDTH - SPRITE_SIZE)
	{
		m_position.x = SCREEN_WIDTH - SPRITE_SIZE;
	}
	if (m_position.y < 0)
	{
		m_position.y = 0;
	}
	else if (m_position.y > SCREEN_HEIGHT - SPRITE_SIZE)
	{
		m_position.y = SCREEN_HEIGHT - SPRITE_SIZE;
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
	m_image.Render(screen, m_EnemyPos.x, m_EnemyPos.y);
	
	

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
		m_image.Render(screen, m_EnemyPos.x + 45, m_EnemyPos.y);
		IsEnemyDead = false;
	}
	
}

void Player::Collider()
{

	Vector<int> PlayerCol, EnemyCol;
	PlayerCol.x = m_position.x + m_PlayerWidth.x;
	PlayerCol.y = m_position.y + m_PlayerHeight.y;

	EnemyCol.x = m_EnemyPos.x + m_imageWidth.x;
	EnemyCol.y = m_EnemyPos.y + m_imageHeight.y;

	if (PlayerCol.x >= EnemyCol.x && PlayerCol.y >= EnemyCol.y)
	{
		m_image.Unload();
		IsEnemyDead = true;
	}
}

Vector<int> Player::GetPostion()
{
	return m_position;
}
