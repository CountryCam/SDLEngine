#include <iostream>
#include "Texture.h"


Texture::Texture(int width, int height)
{
	m_texture = nullptr;
	m_background = nullptr;

	m_textureDimension.x = width;
	m_textureDimension.y = height;

	m_celDimension.x = 0;
	m_celDimension.y = 0;

	m_sourceDimension.x = 0;
	m_sourceDimension.y = 0;

	m_cell = 0;
	m_animationSpeed = 0.0f;
	m_animationRunningTime = 0.0f;

	m_isAnimated = false;
	m_isAnimationDead = false;	
	m_isAnimationLooping = false;
	m_isAnimationLoopFinal = false;
}

bool Texture::Load(const std::string& filename, Screen& screen)
{
	SDL_Surface* TextureData = IMG_Load(filename.c_str());

	if (!TextureData)
	{
		std::cout << "Error loading Texture." << std::endl;
		return false;
	}

	m_texture = SDL_CreateTextureFromSurface(screen.GetRenderer(), TextureData);
	return true;
}

void Texture::Unload()
{
	SDL_DestroyTexture(m_texture);
	SDL_DestroyTexture(m_background);
}

void Texture::IsAnimated(bool flag)
{
	m_isAnimated = flag;
}

void Texture::IsAnimationLooping(bool flag)
{
	m_isAnimationLooping = flag;
}

void Texture::SetTextureDimension(int width, int height)
{
	m_textureDimension.x = width;
	m_textureDimension.y = height;
}

void Texture::SetSourceDimension(int columns, int rows, int width, int height)
{
	m_sourceDimension.x = columns;
	m_sourceDimension.y = rows;

	m_celDimension.x = width / columns;
	m_celDimension.y = height / rows;
}

void Texture::SetAnimationSpeed(float animationSpeed)
{
	m_animationSpeed = animationSpeed;
}

void Texture::Update()
{
	if (m_isAnimated)
	{
		m_animationRunningTime += 0.1f;

		m_cell = static_cast<int>((m_animationRunningTime * m_animationSpeed)) %
			static_cast<int>(m_sourceDimension.x * m_sourceDimension.y);
	}
}

void Texture::Render(Screen& screen, int x, int y, Flip flip)
{
	if (!m_isAnimationDead)
	{
		SDL_Rect src;
		SDL_Rect dst;

		src.x = (m_cell % m_sourceDimension.x) * m_celDimension.x;
		src.y = (m_cell / m_sourceDimension.x) * m_celDimension.y;
		src.w = m_celDimension.x;
		src.h = m_celDimension.y;

		dst.x = x;
		dst.y = y;
		dst.w = m_textureDimension.x;
		dst.h = m_textureDimension.y;

		SDL_Point centrePoint;
		centrePoint.x = m_textureDimension.x / 2;
		centrePoint.y = m_textureDimension.y / 2;

		SDL_RenderCopyEx(screen.GetRenderer(), m_texture, &src, &dst, 0.0, &centrePoint, static_cast<SDL_RendererFlip>(flip));
	}
}
