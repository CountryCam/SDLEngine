#pragma once

#include "Texture.h"
#include "Vector.h"
#include "Player.h"

class Animations
{
public:
	Animations(Screen& screen);
	~Animations();

	void Update(Vector<int> playerPosition);
	void Render(Screen& screen, Background& background);
	void Unload();

	Vector<int> GetPostion();
	

private:

	int m_velocity;

	Texture m_portal;
	Texture m_playerRun;
	Texture m_playerIdle;

	Vector<int> m_positionPortal;

	Vector<int> m_positionPlayer;
	Vector<int> m_directionWalk;
	Vector<int> m_directionStand;

	bool m_portalActive = false;
	bool m_playerActive = true;
	bool m_playerMoveRight = false;
};
