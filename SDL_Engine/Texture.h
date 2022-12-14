#pragma once

#include <string>
#include <SDL_Image.h>
#include "Screen.h"
#include "Vector.h"

class Texture
{
public:
	enum class Flip
	{
		None = SDL_FLIP_NONE,
		Vertical = SDL_FLIP_VERTICAL,
		Horizontal = SDL_FLIP_HORIZONTAL
	};

	Texture(int width = 0, int height = 0);

	bool Load(const std::string& filename, Screen& screen);
	void Unload();

	void IsAnimated(bool flag);
	void IsAnimationLooping(bool flag);

	void SetTextureDimension(int width, int height);
	void SetSourceDimension(int columns, int rows, int width, int height);
	void SetAnimationSpeed(float animationSpeed);

	void Update();
	void Render(Screen& screen, int x = 0, int y = 0, Flip flip = Flip::None);

private:
	int cell;
	float animationSpeed;
	float animationRunningTime;

	bool isAnimated;
	bool isAnimationDead;
	bool isAnimationLooping;
	bool isAnimationLoopFinal;
	
	SDL_Texture* texture;
	SDL_Texture* background;
	Vector<int> celDimension;
	Vector<int> sourceDimension;
	Vector<int> textureDimension;
};