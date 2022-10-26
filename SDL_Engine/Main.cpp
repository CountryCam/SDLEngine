#include <iostream>
#include <string>
#include "Texture.h"
#include "Input.h"
#include "Screen.h"
#include "Vector.h"
#include "Music.h"
#include "Text.h"
#include "Player.h"
#include "Background.h"
#include "Animations.h"

bool isGameRunning = true;
bool altBackGround = false;

int main(int arge, char* argv[])
{
	Screen screen;
	screen.Initialize();

	Player player(screen);
	Background backGround(screen);
	Animations animation(screen);

	Music music;
	music.Initialize();
	music.Load("Music/FirstFrost.wav");
	music.SetVolume(0.5f);
	music.Play(Music::Loop::Ongoing);

	Text title;
	title.Initiliaze();
	title.Load("Fonts/BeyondWonderland.ttf");
	title.SetSize(650, 150);
	title.SetColor(10, 20, 50);
	title.SetString("The Mist: Press P to play");

	
	Text score;
	score.Initiliaze();
	score.Load("Fonts/BeyondWonderland.ttf");
	score.SetSize(250, 150);
	score.SetColor(10, 20, 50);
	score.SetString("Time: 0");

	
	int totalTime = 0;
	const auto interval = 1;

	//Main Code for Game Loop
	while (isGameRunning)
	{
		auto timeStart = SDL_GetTicks();

		//Refresh Screen
		screen.Refresh();
		backGround.Update();
		backGround.Render(screen);
		
		//PLAYER MOVEMENT AND RESTRICTIONS
		player.Update(screen);
		player.Render(backGround, screen);

		animation.Update(player.GetPostion());
		animation.Render(screen, backGround);

		//returns pointer to Class
		Input::Instance()->Update();

		//Closes window
		isGameRunning = !(Input::Instance()->IsWindowClosed());

		//Title Render
		title.Render(screen, 450, 10);
		

		//Display Score Timer
		static int scorePoints = 0;
		if (totalTime >= interval * 1000)
		{
			scorePoints += 1;
			std::string text = std::to_string(scorePoints);
			score.SetString("Time: " + text);
			totalTime = 0;
		}
		score.Render(screen, 10, 10);
		
	
		screen.Present();

		//Get End of Ticks - Start of Tick for TotalTime
		auto timeEnd = SDL_GetTicks() - timeStart;
		totalTime += timeEnd;
	}
	
	music.Unload();
	music.Shutdown();

	score.Unload();
	score.Shutdown();
	title.Unload();
	

	backGround.Unload();
	screen.Shutdown();

	player.~Player();
	animation.Unload();

	
	return 0;
}