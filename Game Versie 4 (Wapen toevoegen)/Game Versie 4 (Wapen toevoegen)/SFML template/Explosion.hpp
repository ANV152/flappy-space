#pragma once
#include <SFML/Graphics.HPP>
#include "Game.hpp"
#include "Asteroids.hpp"
namespace Flappy {
	class Explosion
	{
	public:
		Explosion(GameDataRef _data);

	private:
		GameDataRef _data;

		sf::Sprite _birdSprite;

		std::vector<sf::Texture> _animationFrames;

		unsigned int _animationIterator;
		sf::Clock _clock;

		sf::Clock _movementClock;

		int _birdState;

		//Physics
		float distance_y;
		float acceleration_y;
		float acceleration_x;
		sf::Vector2f vel;
	};
}

