#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Actions.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"
#include "Gravity.hpp"
#include "Falling_Asteroids.hpp"
#include "set_of_gas.hpp"
#include "Wapen.hpp"
namespace Flappy
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		


	private:
		

		GameDataRef _data;
	
		sf::Sprite _background;
		Pipe *pipe;
		Land* land;
		Bird* bird;
		Collision collision;
		Flash* flash;
		HUD* hud;
		Falling_Asteroids* asteroids;
		Falling_Asteroids* asteroids_2;

		Gasoline *gasoline;
		Wapen *wapen;

		sf::Clock clock_1;
		sf::Clock clock_2;

		int _gameState;
		sf::RectangleShape _gameOverFlash;
		bool _flashOn;

		int _score;

		sf::SoundBuffer _Hit_sound_buffer;
		sf::SoundBuffer _Point_sound_buffer;
	
		sf::SoundBuffer _Hit_bird_sound_buffer;
		sf::Sound _Hit_bird_sound;
		
		sf::Sound _Hit_sound;
		sf::Sound _Point_Sound;
	};
}