#include "Input.h"
#include "Screen.h"
#include "GameClass.h"
#include <iostream>

GameClass::GameClass(Screen& screen)
{
	background.Load("Images/BackGround.png", screen);
	background.SetTextureDimension(1280, 720);
	background.SetSourceDimension(1, 1, 1280, 720);

	backgroundMain.Load("Images/RockyBackground.png", screen);
	backgroundMain.SetTextureDimension(1280, 720);
	backgroundMain.SetSourceDimension(1, 1, 1280, 720);
}

void GameClass::Update()
{
	
	if (Input::Instance()->IsMouseClicked(HM_MOUSE_LEFT) == true)
	{
		std::cout << "Mouse Left Clicked" << std::endl;
		return;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_P) == true)
	{
		altBackground = true;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_O) == true)
	{
		altBackground = false;
	}
}

void GameClass::Render(Screen& screen)
{
	
	if (altBackground)
	{
		backgroundMain.Render(screen);
	}
	else
	{
		background.Render(screen);
	}
}

void GameClass::Unload()
{
	background.Unload();
	backgroundMain.Unload();
}