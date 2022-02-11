#include <SDL.h>
#include "Input.h"

//======================================================================================================
Input* Input::Instance()
{
	static Input* inputObject = new Input();
	return inputObject;
}
//======================================================================================================
Input::Input()
{
	m_key = ' ';
	m_mouseWheel = 0;

	m_isKeyPressed = false;
	m_isMouseClicked = false;
	m_isWindowClosed = false;

	m_modifier = HM_MOD_NONE;
	m_mouseButton = HM_MOUSE_NONE;
}
//======================================================================================================
char Input::GetKey() const
{
	return m_key;
}
//======================================================================================================
int Input::GetMouseWheel() const
{
	return m_mouseWheel;
}
//======================================================================================================
const Vector<int>& Input::GetMouseMotion() const
{
	return m_mouseMotion;
}
//======================================================================================================
const Vector<int>& Input::GetMousePosition() const
{
	return m_mousePosition;
}
//======================================================================================================
void Input::SetCursorState(bool isCursorEnabled, bool isCursorVisible)
{
	SDL_ShowCursor(static_cast<int>(isCursorVisible));
	SDL_SetRelativeMouseMode(static_cast<SDL_bool>(isCursorEnabled));
}
//======================================================================================================
bool Input::IsWindowClosed() const
{
	return m_isWindowClosed;
}
//======================================================================================================
bool Input::IsKeyPressed() const
{
	return m_isKeyPressed;
}
//======================================================================================================
bool Input::IsKeyPressed(int keyCode) const
{
	const Uint8* m_keyStates = SDL_GetKeyboardState(nullptr);
	return m_keyStates[keyCode];
}
//======================================================================================================
bool Input::IsModifierPressed(int modifier_1, int modifier_2) const
{
	return m_modifier == (modifier_1 | modifier_2);
}
//======================================================================================================
bool Input::IsMouseClicked() const
{
	return m_isMouseClicked;
}
//======================================================================================================
bool Input::IsMouseClicked(int mouseButton_1, int mouseButton_2) const
{
	return m_mouseButton == (mouseButton_1 | mouseButton_2);
}
//======================================================================================================
void Input::Update()
{
	SDL_Event events;

	m_mouseWheel = 0;
	m_mouseMotion.x = 0;
	m_mouseMotion.y = 0;
	m_isWindowClosed = false;

	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{

		case SDL_QUIT:
		{
			m_isWindowClosed = true;
			break;
		}

		case SDL_KEYUP:
		{
			m_isKeyPressed = false;
			m_key = SDLK_UNKNOWN;
			m_modifier = events.key.keysym.mod;
			break;
		}

		case SDL_KEYDOWN:
		{
			m_isKeyPressed = true;
			m_key = events.key.keysym.sym;
			m_modifier |= events.key.keysym.mod;
			break;
		}

		case SDL_MOUSEMOTION:
		{
			m_mousePosition.x = events.motion.x;
			m_mousePosition.y = events.motion.y;

			m_mouseMotion.x = events.motion.xrel;
			m_mouseMotion.y = events.motion.yrel;
			break;
		}

		case SDL_MOUSEWHEEL:
		{
			m_mouseWheel = events.wheel.y;
			break;
		}

		case SDL_MOUSEBUTTONUP:
		{
			m_isMouseClicked = false;
			m_mousePosition.x = events.motion.x;
			m_mousePosition.y = events.motion.y;

			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT: { m_mouseButton ^= HM_MOUSE_LEFT; break;   }
			case SDL_BUTTON_MIDDLE: { m_mouseButton ^= HM_MOUSE_MIDDLE; break; }
			case SDL_BUTTON_RIGHT: { m_mouseButton ^= HM_MOUSE_RIGHT; break;  }
			}

			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			m_isMouseClicked = true;
			m_mousePosition.x = events.motion.x;
			m_mousePosition.y = events.motion.y;

			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT: { m_mouseButton |= HM_MOUSE_LEFT; break;   }
			case SDL_BUTTON_MIDDLE: { m_mouseButton |= HM_MOUSE_MIDDLE; break; }
			case SDL_BUTTON_RIGHT: { m_mouseButton |= HM_MOUSE_RIGHT; break;  }
			}

			break;
		}

		}
	}
}