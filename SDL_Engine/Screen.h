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
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};

