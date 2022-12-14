#include <iostream>
#include "Screen.h"

SDL_Texture* playerTex;

Screen::Screen()
{
	window = nullptr;
	renderer = nullptr;
}

Screen::~Screen()
{

}

SDL_Renderer* Screen::GetRenderer()
{
	return renderer;
}

bool Screen::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL did not initialize!" << std::endl;
		return false;
	}

	window = SDL_CreateWindow("Cameron's Game Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280, 720,
		0);

	SDL_Surface* tmpSurface = IMG_Load("Assets/idle0001.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	if (!window)
	{
		std::cout << "Game window could not be created!" << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!window)
	{
		std::cout << "Renderer could not be created!" << std::endl;
		return false;
	}
	return true;
}

void Screen::Refresh()
{
	//Clear to SCreen
	SDL_RenderClear(renderer);
}

void Screen::Present()
{
	//Swap the frame buffers
	SDL_RenderPresent(renderer);
}

void Screen::Copy()
{
	//Copying the Render Images
	SDL_RenderCopy(renderer, playerTex, NULL, NULL);
}

void Screen::Shutdown()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
