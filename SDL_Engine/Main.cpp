#include <iostream>
#include "Image.h"
#include "Input.h"
#include "Screen.h"

bool isGameRunning = true;
int x = 300;
int y = 300;
bool altBackGround = false;

int main(int arge, char* argv[])
{
	Screen screen;
	screen.Initialize();
	//Adding Background Images
	Image background( 1280, 720);
	background.Load("C:/Users/Engine/Pictures/BackDrop.png", screen); //C:/Users/Engine/Pictures/BackDrop.png

	Image Player(200, 301);
	Player.Load("C:/Users/Engine/Pictures/BurlyMan.png", screen);

	Image backgroundTwo(1280, 720);
	backgroundTwo.Load("C:/Users/Engine/Pictures/RockyBackground.png", screen);

	//Main Code for Game Loop
	while (isGameRunning)
	{
		//Refresh Screen
		screen.Refresh();
		//returns pointer to Class
		Input::Instance()->Update();
		//Closes window
		isGameRunning = !(Input::Instance()->IsWindowClosed());

		//alternate way I made as a test to close the game.
		if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) == true)
		{
			screen.Shutdown();
			isGameRunning = false;
		}

		auto mousePosition = Input::Instance()->GetMousePosition();
		auto mouseMotion = Input::Instance()->GetMouseMotion();
		auto mouseWheel = Input::Instance()->GetMouseWheel();
		
		if (Input::Instance()->IsMouseClicked(HM_MOUSE_LEFT) == true)
		{
			std::cout << "Mouse Left Clicked" << std::endl;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_P) == true)
		{
			altBackGround = true;
		}

		if (Input::Instance()->IsKeyPressed(HM_KEY_O) == true)
		{
			altBackGround = false;
		}

		if (altBackGround == true)
		{
			//screen.Refresh();
			background.Unload();
			//New Backdrop
			backgroundTwo.Render(screen, 0, 0);
			Player.Render(screen, x, y);
			screen.Present();
		}
		else if (altBackGround == false)
		{
			//screen.Refresh();
			//backgroundTwo.Unload();
			//base bg
			background.Render(screen, 0, 0);
			//Player.Render(screen, x, y);
			screen.Present();
		}
		screen.Present();
	}
	
	screen.Shutdown();
	return 0;
}