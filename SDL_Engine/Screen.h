#pragma once
#include<Windows.h>
#include <SDL.h>
#include <SDL_image.h>

//TODO - Make this a Singleton

class Screen
{

public:

	Screen();

	SDL_Renderer* GetRenderer();

	bool Initialize(int width = 1280, int height = 720);
	void Refresh();
	void Present();
	void Shutdown();

private:
	SDL_Window* window; 
	SDL_Renderer* renderer;
};

