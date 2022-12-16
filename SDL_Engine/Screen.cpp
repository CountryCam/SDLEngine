#include <iostream>
#include "Screen.h"

Screen* Screen::Instance()
{
	static Screen* screenObject = new Screen();
	return screenObject;
}


SDL_Renderer* Screen::GetRenderer()
{
	return renderer;
}

bool Screen::Initialize(int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL did not initialize!" << std::endl;
		return false;
	}

	window = SDL_CreateWindow("Cameron's Game Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width, height,
		0); //Flags

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
	//Clear to Screen
	SDL_RenderClear(renderer);
}

void Screen::Present()
{
	//Swap the frame buffers
	SDL_RenderPresent(renderer);
}

void Screen::Shutdown()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
