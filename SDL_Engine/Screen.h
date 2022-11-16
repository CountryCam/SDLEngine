#pragma once
#include <SDL.h>
#include <SDL_image.h>

//TODO - Make this a Singleton

class Screen
{

public:

	Screen();
	~Screen();

	SDL_Renderer* GetRenderer();

	bool Initialize();
	void Refresh();
	void Present();
	void Copy(); //Bad name!!
	void Shutdown();

private:
	SDL_Window* window; //Coding standards have changed from m_window -> window 
	SDL_Renderer* renderer; //Coding standards have changed from m_renderer -> renderer
};

