#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "DEFINITIONS.hpp"

namespace Flappy
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
		sf::Music _Soundtrack;
	};


	typedef std::shared_ptr<GameData> GameDataRef;

	template<typename f>
	float getTurnDownFreq_(f freq, f speed)
	{
		return speed * freq * freq;
	}
	
	template<typename T>
	void turnVolume(T _data,float dt, bool up, float target, float speed = 0.05) 
	{
			switch (up)
			{
			case true:
				if (_data->_Soundtrack.getVolume() > target)
				{
					_data->_Soundtrack.setVolume(target);
				}
				else
				{
					
					_data->_Soundtrack.setVolume(_data->_Soundtrack.getVolume() + getTurnDownFreq_(dt, speed));
					
				}
				break;
			case false:
				if (_data->_Soundtrack.getVolume() < target)
				{
					_data->_Soundtrack.setVolume(target);
				}
				else
				{
					
					_data->_Soundtrack.setVolume(_data->_Soundtrack.getVolume() - getTurnDownFreq_(dt,speed));
					
				}
				break;
			}

				
	}


	class Game
	{
	public:
		Game(int width, int height, std::string title);
		
		

	private:
		// Updates run at 60 per second.
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};
}