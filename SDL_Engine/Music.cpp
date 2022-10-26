#include <algorithm>
#include <iostream>
#include <assert.h>
#include "Music.h"

bool Music::Initialize(int frequency, int chunkSize)
{
	if (Mix_OpenAudio(frequency, AUDIO_S16SYS, 2, chunkSize) == -1)
	{
		std::cout << "Error initializing audio." << std::endl;
		return false;
	}

	return true;
}

bool Music::Load(const std::string& filename)
{
	m_music = Mix_LoadMUS(filename.c_str());

	if (!m_music)
	{
		std::cout << "Error loading audio." << std::endl;
		return false;
	}

	return true;
}

void Music::Unload()
{
	Mix_FreeMusic(m_music);
}

void Music::Shutdown()
{
	Mix_CloseAudio();
}

Music::Music()
{
	m_music = nullptr;
}

void Music::SetVolume(float volume)
{
	volume = std::clamp(volume, 0.0f, 1.0f);
	Mix_VolumeMusic(static_cast<int>(volume * 128.0f));
}

bool Music::Play(Loop loop)
{
	if (!Mix_PlayingMusic())
	{
		if (Mix_PlayMusic(m_music, static_cast<int>(loop)) == -1)
		{
			std::cout << "Error playing audio." << std::endl;
			return false;
		}
	}
	return true;
}

void Music::Pause()
{
	if (!Mix_PausedMusic())
	{
		Mix_PauseMusic();
	}
}

void Music::Resume()
{
	if (Mix_PausedMusic())
	{
		Mix_ResumeMusic();
	}	
}

void Music::Stop()
{
	if (Mix_PlayingMusic())
	{
		Mix_HaltMusic();
	}
}