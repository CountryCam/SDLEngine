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
	m_font = TTF_OpenFont(filename.c_str(), 300);

	if (!m_font)
	{
		std::cout << "Error loading font." << std::endl;
		return false;
	}
	
	return true;
}

void Text::Unload()
{
	TTF_CloseFont(m_font);
}

void Text::Shutdown()
{
	TTF_Quit();
}

Text::Text()
{
	m_font = nullptr;
	m_texture = nullptr;
	m_textSize = { 0, 0 };
	m_color = { 255, 255, 255 };
}

Text::~Text()
{
	SDL_DestroyTexture(m_texture);
}

void Text::SetSize(int width, int height)
{
	m_textSize.x = width;
	m_textSize.y = height;
}

void Text::SetColor(Uint8 r, Uint8 g, Uint8 b)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;

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
	dst.w = m_textSize.x;
	dst.h = m_textSize.y;

	CreateText(screen);
	SDL_RenderCopy(screen.GetRenderer(), m_texture, nullptr, &dst);
}

void Text::CreateText(Screen& screen)
{
	SDL_Surface* textSurface = TTF_RenderText_Blended(m_font, m_string.c_str(), m_color);

	SDL_DestroyTexture(m_texture);
	m_texture = SDL_CreateTextureFromSurface(screen.GetRenderer(), textSurface);

	SDL_FreeSurface(textSurface);
}
