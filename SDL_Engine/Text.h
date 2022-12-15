#pragma once

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Screen.h"
#include "GameClass.h"

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
	bool mainMenuText = true; //Camel case!
	
	std::string m_string;
	SDL_Point textSize;

	TTF_Font* font;
	SDL_Color color;
	SDL_Texture* texture;
};