#include "Input.h"
#include "Screen.h"
#include "Background.h"
#include <iostream>

Background::Background(Screen& screen)
{
	m_background.Load("Images/BackGround.png", screen);
	m_background.SetTextureDimension(1280, 720);
	m_background.SetSourceDimension(1, 1, 1280, 720);

	m_backgroundMain.Load("Images/RockyBackground.png", screen);
	m_backgroundMain.SetTextureDimension(1280, 720);
	m_backgroundMain.SetSourceDimension(1, 1, 1280, 720);

	
}

void Background::Update()
{
	
	if (Input::Instance()->IsMouseClicked(HM_MOUSE_LEFT) == true)
	{
		std::cout << "Mouse Left Clicked" << std::endl;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_P) == true)
	{
		m_altBackGround = true;
	}

	if (Input::Instance()->IsKeyPressed(HM_KEY_O) == true)
	{
		m_altBackGround = false;
	}
}

void Background::Render(Screen& screen)
{
	if (m_altBackGround)
	{
		m_backgroundMain.Render(screen);
	}

	else
	{
		m_background.Render(screen);
	}
}

void Background::Unload()
{
	m_background.Unload();
	m_backgroundMain.Unload();
}


