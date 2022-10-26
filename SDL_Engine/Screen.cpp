#include <iostream>
#include "Screen.h"

SDL_Texture* playerTex;

Screen::Screen()
{
	m_window = nullptr;
	m_renderer = nullptr;
}

Screen::~Screen()
{

}

SDL_Renderer* Screen::GetRenderer()
{
	return m_renderer;
}

bool Screen::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL did not initialize!" << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow("Cameron's Game Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280, 720,
		0);

	SDL_Surface* tmpSurface = IMG_Load("Assets/idle0001.png");
	playerTex = SDL_CreateTextureFromSurface(m_renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	if (!m_window)
	{
		std::cout << "Game window could not be created!" << std::endl;
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	if (!m_window)
	{
		std::cout << "Renderer could not be created!" << std::endl;
		return false;
	}
	return true;
}

void Screen::Refresh()
{
	//Clear to SCreen
	SDL_RenderClear(m_renderer);
}

void Screen::Present()
{
	//Swap the frame buffers
	SDL_RenderPresent(m_renderer);
}

void Screen::Copy()
{
	//Copying the Render Images
	SDL_RenderCopy(m_renderer, playerTex, NULL, NULL);
}

void Screen::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
