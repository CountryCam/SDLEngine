#pragma once

#include "Texture.h"
#include "Vector.h"

class GameClass
{
public:
	GameClass(); //Screen& screen
	void Update();
	void Render(); //Screen& screen
	void Unload();

	//TODO -(Karsten) Why is the function definition not in the .cpp file? == (Cameron) I'm checking background then if altBackground is true. Spawn enemy
	bool GetBackground() { return altBackground; };

private:
	Texture background;
	Texture backgroundMain;
	
	Vector<int> position;
	bool altBackground = false;
};