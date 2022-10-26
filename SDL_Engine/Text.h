#pragma once

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Screen.h"
#include "Background.h"

class Text
{

public:

	bool Initiliaze();
	bool Load(const std::string& filename);
	void Unload();
	void Shutdown();

	Text();
	~Text();

	void SetSize(int width, int height);
	void SetColor(Uint8 r, Uint8 g, Uint8 b);
	void SetString(const std::string& string);

	void Render(Screen& screen, int x = 0, int y = 0);

private:

	void CreateText(Screen& screen);
	bool m_MainMenuText = true;
	
	std::string m_string;
	SDL_Point m_textSize;

	TTF_Font* m_font;
	SDL_Color m_color;
	SDL_Texture* m_texture;
};