#pragma once
#include<Windows.h>
#include <SDL.h>
#include <SDL_image.h>

//TODO - Make this a Singleton

class Screen
{
public:
	static Screen* Instance();

	SDL_Renderer* GetRenderer();

	bool Initialize(int width = 1280, int height = 720);
	void Refresh();
	void Present();
	void Shutdown();

private:
	Screen() {}
	Screen(const Screen&);
	Screen& operator=(const Screen&);

	SDL_Window* window{ nullptr };
	SDL_Renderer* renderer{ nullptr };
};

