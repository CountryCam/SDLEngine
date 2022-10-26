#include <assert.h>
#include <iostream>
#include "Screen.h"
#include "Text.h"

bool Text::Initiliaze()
{
	if (TTF_Init() == -1)
	{
		std::cout << "Error initializing font system" << std::endl;
		return false;
	}
	
	return true;
}

bool Text::Load(const std::string& filename)
{
	font = TTF_OpenFont(filename.c_str(), 300);

	if (!font)
	{
		std::cout << "Error loading font." << std::endl;
		return false;
	}
	
	return true;
}

void Text::Unload()
{
	TTF_CloseFont(font);
}

void Text::Shutdown()
{
	TTF_Quit();
}

Text::Text()
{
	font = nullptr;
	texture = nullptr;
	textSize = { 0, 0 };
	color = { 255, 255, 255 };
}

Text::~Text()
{
	SDL_DestroyTexture(texture);
}

void Text::SetSize(int width, int height)
{
	textSize.x = width;
	textSize.y = height;
}

void Text::SetColor(Uint8 r, Uint8 g, Uint8 b)
{
	color.r = r;
	color.g = g;
	color.b = b;

}

void Text::SetString(const std::string& string)
{
	m_string = string;

}

void Text::Render(Screen& screen, int x, int y)
{
	
	SDL_Rect dst;

	dst.x = x;
	dst.y = y;
	dst.w = textSize.x;
	dst.h = textSize.y;

	CreateText(screen);
	SDL_RenderCopy(screen.GetRenderer(), texture, nullptr, &dst);
}

void Text::CreateText(Screen& screen)
{
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, m_string.c_str(), color);

	SDL_DestroyTexture(texture);
	texture = SDL_CreateTextureFromSurface(screen.GetRenderer(), textSurface);

	SDL_FreeSurface(textSurface);
}
