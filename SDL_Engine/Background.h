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

	bool GetBackground() { return m_altBackGround; };

private:
	Texture m_background;
	Texture m_backgroundMain;
	
	Vector<int> m_position;
	bool m_altBackGround = false;
};