#include <iostream>
#include "Texture.h"


Texture::Texture(int width, int height)
{
	texture = nullptr;
	background = nullptr;

	textureDimension.x = width;
	textureDimension.y = height;

	celDimension.x = 0;
	celDimension.y = 0;

	sourceDimension.x = 0;
	sourceDimension.y = 0;

	cell = 0;
	animationSpeed = 0.0f;
	animationRunningTime = 0.0f;

	isAnimated = false;
	isAnimationDead = false;	
	isAnimationLooping = false;
	isAnimationLoopFinal = false;
}

bool Texture::Load(const std::string& filename) // Screen& screen
{
	SDL_Surface* TextureData = IMG_Load(filename.c_str());

	if (!TextureData)
	{
		std::cout << "Error loading Texture." << std::endl;
		return false;
	}

	texture = SDL_CreateTextureFromSurface(Screen::Instance()->GetRenderer(), TextureData);
	return true;
}

void Texture::Unload()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(background);
}

void Texture::IsAnimated(bool flag)
{
	isAnimated = flag;
}

void Texture::IsAnimationLooping(bool flag)
{
	isAnimationLooping = flag;
}

void Texture::SetTextureDimension(int width, int height)
{
	textureDimension.x = width;
	textureDimension.y = height;
}

void Texture::SetSourceDimension(int columns, int rows, int width, int height)
{
	sourceDimension.x = columns;
	sourceDimension.y = rows;

	celDimension.x = width / columns;
	celDimension.y = height / rows;
}

void Texture::SetAnimationSpeed(float animationSpeed)
{
	animationSpeed = animationSpeed;
}

void Texture::Update()
{
	if (isAnimated)
	{
		animationRunningTime += 0.1f;

		cell = static_cast<int>((animationRunningTime * animationSpeed)) %
			static_cast<int>(sourceDimension.x * sourceDimension.y);
	}
}

void Texture::Render(int x, int y, Flip flip) // Screen& screen
{
	if (!isAnimationDead)
	{
		SDL_Rect src;
		SDL_Rect dst;

		src.x = (cell % sourceDimension.x) * celDimension.x;
		src.y = (cell / sourceDimension.x) * celDimension.y;
		src.w = celDimension.x;
		src.h = celDimension.y;

		dst.x = x;
		dst.y = y;
		dst.w = textureDimension.x;
		dst.h = textureDimension.y;

		SDL_Point centrePoint;
		centrePoint.x = textureDimension.x / 2;
		centrePoint.y = textureDimension.y / 2;

		SDL_RenderCopyEx(Screen::Instance()->GetRenderer(), texture, &src, &dst, 0.0, &centrePoint, static_cast<SDL_RendererFlip>(flip));
	}
}
