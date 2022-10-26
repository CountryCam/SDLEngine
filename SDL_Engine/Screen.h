#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Screen
{

public:

	Screen();
	~Screen();

	SDL_Renderer* GetRenderer();

	bool Initialize();
	void Refresh();
	void Present();
	void Copy();
	void Shutdown();

private:
	SDL_Window* window; //Coding standards have changed from m_window -> window 
	SDL_Renderer* renderer; //Coding standards have changed from m_renderer -> renderer
};

