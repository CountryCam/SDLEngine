#include "Player.h"
#include "Texture.h"
#include <iostream>
#include "Input.h"
#include "Screen.h"
#include "Enemy.h"

Player::Player() //Screen& screen
{
	velocity = 2; 
	
	portal.Load("Images/GreenPortal.png"); //screen
	portal.SetTextureDimension(240, 192);
	portal.SetSourceDimension(8, 3, 512, 192);

	playerRun.Load("Images/SpriteSheet0001Run.png"); //screen
	playerRun.SetTextureDimension(140, 171); //130, 161
	playerRun.SetSourceDimension(9, 1, 1380, 161); //9, 1, 1380, 161
			
	playerIdle.Load("Images/IdleSpriteSheet.png"); //screen
	playerIdle.SetTextureDimension(140, 171);
	playerIdle.SetSourceDimension(7, 1, 1540, 221);
}


Player::~Player()
{
	portal.Unload();
	playerRun.Unload();
	playerIdle.Unload();
}

void Player::Update(Vector<int> playerPosition)
{
	positionPortal.x = playerPosition.x +80;
	positionPortal.y = playerPosition.y;

	positionPlayer.x = playerPosition.x; 
	positionPlayer.y = playerPosition.y +65;

	if (Input::Instance()->IsMouseClicked(HM_MOUSE_LEFT) == true)
	{
		std::cout << "Mouse Left Clicked" << std::endl;
		portalActive = true;
	}
	else 
	{
		portalActive = false;
	}

	if ((Input::Instance()->IsKeyPressed(HM_KEY_LEFT)) || (Input::Instance()->IsKeyPressed(HM_KEY_A)))
	{
		directionStand = directionWalk = Vector<int>::Left;
		playerMoveRight = true;
		playerActive = false;
	}
	else if ((Input::Instance()->IsKeyPressed(HM_KEY_RIGHT)) || (Input::Instance()->IsKeyPressed(HM_KEY_D)))
	{
		directionStand = directionWalk = Vector<int>::Right;
		playerMoveRight = true;
		playerActive = false;
	}
	else
	{
		directionWalk = Vector<int>::Zero;
		playerMoveRight = false;
	}
}

void Player::Render(GameClass& background) //Screen& screen,
{
	if ((!background.GetBackground()))
	{
		return;
	}

	if (directionWalk.x == 0 && directionWalk.y == 0 )
	{
		directionStand.x < 0.0f ? playerIdle.Render(positionPlayer.x, positionPlayer.y, Texture::Flip::Horizontal) //screen
			: playerIdle.Render(positionPlayer.x, positionPlayer.y); //screen,
	}
	else
	{
		directionWalk.x < 0.0f ?  playerRun.Render(positionPlayer.x, positionPlayer.y, Texture::Flip::Horizontal) //screen,
			:  playerRun.Render(positionPlayer.x, positionPlayer.y); //screen,
	}

	if (portalActive == true)
	{
		portal.IsAnimated(true);
		portal.IsAnimationLooping(true);
		portal.SetAnimationSpeed(0.09f);
		portal.Update();
		portal.Render(positionPortal.x, positionPortal.y); //screen,
	}
	if (playerActive == true)
	{
		playerIdle.IsAnimated(true);
		playerIdle.IsAnimationLooping(true);
		playerIdle.SetAnimationSpeed(0.1f);
		playerIdle.Update();
	}
	if (playerActive == false)
	{
		playerIdle.IsAnimated(false);
		playerIdle.IsAnimationLooping(false);
		playerIdle.SetAnimationSpeed(0.1f);
		playerIdle.Update();

	}
	if (playerMoveRight == true)
	{
		playerRun.IsAnimated(true);
		playerRun.IsAnimationLooping(true);
		playerRun.SetAnimationSpeed(0.1f);
		playerRun.Update();
		playerActive = false;
	}
	if (playerMoveRight == false)
	{
		playerRun.IsAnimated(false);
		playerRun.IsAnimationLooping(false);
		playerRun.SetAnimationSpeed(0.1f);
		playerRun.Update();
		playerActive = true;
	}
}

void Player::Unload()
{
	portal.Unload();
	playerRun.Unload();
	playerIdle.Unload();
}

Vector<int> Player::GetPostionPlayer()
{
	return positionPlayer;
}
