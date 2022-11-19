#include "Animations.h"
#include "Texture.h"
#include <iostream>
#include "Input.h"
#include "Screen.h"
#include "Player.h"

Animations::Animations(Screen& screen)
{
	m_velocity = 2; 
	
	m_portal.Load("Images/GreenPortal.png", screen);
	m_portal.SetTextureDimension(240, 192);
	m_portal.SetSourceDimension(8, 3, 512, 192);

	m_playerRun.Load("Images/SpriteSheet0001Run.png", screen);
	m_playerRun.SetTextureDimension(140, 171); //130, 161
	m_playerRun.SetSourceDimension(9, 1, 1380, 161); //9, 1, 1380, 161
			
	m_playerIdle.Load("Images/IdleSpriteSheet.png", screen);
	m_playerIdle.SetTextureDimension(140, 171);
	m_playerIdle.SetSourceDimension(7, 1, 1540, 221);
}


Animations::~Animations()
{
	m_portal.Unload();
	m_playerRun.Unload();
	m_playerIdle.Unload();
}

void Animations::Update(Vector<int> playerPosition)
{
	m_positionPortal.x = playerPosition.x +80;
	m_positionPortal.y = playerPosition.y;

	m_positionPlayer.x = playerPosition.x; 
	m_positionPlayer.y = playerPosition.y +65;

	if (Input::Instance()->IsMouseClicked(HM_MOUSE_LEFT) == true)
	{
		std::cout << "Mouse Left Clicked" << std::endl;
		m_portalActive = true;
	}
	else 
	{
		m_portalActive = false;
	}

	if ((Input::Instance()->IsKeyPressed(HM_KEY_LEFT)) || (Input::Instance()->IsKeyPressed(HM_KEY_A)))
	{
		m_directionStand = m_directionWalk = Vector<int>::Left;
		m_playerMoveRight = true;
		m_playerActive = false;
	}
	else if ((Input::Instance()->IsKeyPressed(HM_KEY_RIGHT)) || (Input::Instance()->IsKeyPressed(HM_KEY_D)))
	{
		m_directionStand = m_directionWalk = Vector<int>::Right;
		m_playerMoveRight = true;
		m_playerActive = false;
	}
	else
	{
		m_directionWalk = Vector<int>::Zero;
		m_playerMoveRight = false;
	}
}

void Animations::Render(Screen& screen, Background& background)
{
	if ((!background.GetBackground()))
	{
		return;
	}

	if (m_directionWalk.x == 0 && m_directionWalk.y == 0 )
	{
		m_directionStand.x < 0.0f ? m_playerIdle.Render(screen, m_positionPlayer.x, m_positionPlayer.y, Texture::Flip::Horizontal)
			: m_playerIdle.Render(screen, m_positionPlayer.x, m_positionPlayer.y);
	}
	else
	{
		m_directionWalk.x < 0.0f ? m_playerRun.Render(screen, m_positionPlayer.x, m_positionPlayer.y, Texture::Flip::Horizontal)
			: m_playerRun.Render(screen, m_positionPlayer.x, m_positionPlayer.y);
	}
	
	

	if (m_portalActive == true)
	{
		m_portal.IsAnimated(true);
		m_portal.IsAnimationLooping(true);
		m_portal.SetAnimationSpeed(0.09f);
		m_portal.Update();
		m_portal.Render(screen, m_positionPortal.x, m_positionPortal.y);
	}
	if (m_playerActive == true)
	{
		m_playerIdle.IsAnimated(true);
		m_playerIdle.IsAnimationLooping(true);
		m_playerIdle.SetAnimationSpeed(0.1f);
		m_playerIdle.Update();
	}
	if (m_playerActive == false)
	{
		m_playerIdle.IsAnimated(false);
		m_playerIdle.IsAnimationLooping(false);
		m_playerIdle.SetAnimationSpeed(0.1f);
		m_playerIdle.Update();

	}

	if (m_playerMoveRight == true)
	{
		m_playerRun.IsAnimated(true);
		m_playerRun.IsAnimationLooping(true);
		m_playerRun.SetAnimationSpeed(0.1f);
		m_playerRun.Update();
		m_playerActive = false;
	}
	if (m_playerMoveRight == false)
	{
		m_playerRun.IsAnimated(false);
		m_playerRun.IsAnimationLooping(false);
		m_playerRun.SetAnimationSpeed(0.1f);
		m_playerRun.Update();
		m_playerActive = true;
	}
}

void Animations::Unload()
{
	m_portal.Unload();
	m_playerRun.Unload();
	m_playerIdle.Unload();
}

Vector<int> Animations::GetPostion()
{
	return m_positionPlayer;
}
