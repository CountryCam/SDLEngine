#pragma once

#include <string>
#include <SDL_image.h>
#include "Screen.h"
#include "Vector.h"


class Image
{

public:

	Image(int width = 0, int height = 0);

	bool Load(const std::string& filename, Screen& screen);
	void Unload();

	void SetDimension(int width, int height);
	void Render(Screen& screen, int x = 0, int y = 0);

private:

	SDL_Texture* m_texture;
	Vector<int> m_dimension;
};