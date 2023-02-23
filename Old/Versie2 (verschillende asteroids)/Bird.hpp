#pragma once

#include <SFML/Graphics.hpp>
#include "Gravity.hpp"
#include "Actions.hpp"
#include "Land.hpp"
#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include <vector>

namespace Flappy
{
	class Bird
	{
	public:
		Bird(GameDataRef data, sf::Vector2f vel);
		~Bird();

		void Draw();
		void Animate(float dt);
		void change_y_acceleration(float force);
		void Boost();
		void Update(float dt, float land);
		void Tap();
		sf::Sprite _boostSprite;
		const sf::Sprite& GetSprite() const;
		
	private:
		GameDataRef _data;

		sf::Sprite _birdSprite;
		
		std::vector<sf::Texture> _animationFrames;
	
		unsigned int _animationIterator;
		sf::Clock _clock;

		sf::Clock _movementClock;

		int _birdState;

		//Physics
		float jet_force;

		float distance_y;
		float acceleration_y;
		float acceleration_x;
		sf::Vector2f vel;

		

		

	};
}