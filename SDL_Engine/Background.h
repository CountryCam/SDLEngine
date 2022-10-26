#pragma once

#include "Texture.h"
#include "Vector.h"

class Background
{
public:
	Background(Screen& screen);
	void Update();
	void Render(Screen& screen);
	void Unload();

	bool GetBackground() { return altBackground; };

private:
	Texture background;
	Texture backgroundMain;
	
	Vector<int> position;
	bool altBackground = false;
};