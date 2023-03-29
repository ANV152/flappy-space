#pragma once


#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"
namespace Flappy
{
	class Asteroid
	{
	public:
		Asteroid(GameDataRef data);
		void MoveAsteroids(float dt, float land);
		void DrawAsteroids();
		void RandomiseAsteroidOffset();
		int returnHealth();
		void lowerHealth();
		sf::Sprite & GetSprite() ;
		sf::Sprite& Get_FireSprite();
		sf::Sprite& Get_Explosion_Sprite();
		//std::vector<sf::Sprite>& GetScoringSprites();
		int _asteroid_state;
		
	protected: // Protected gemaakt omdat anders moet je voor elke waarden een aparte get maken en heeft niet zoveel nut want alleen de asteroid versions gebruikt deze.
		// Verschillende asteroid versie erven over van asteroid dus protected om deze waardes voor verschillende asteroids aan te kunnen passen.
		sf::Sprite asteroid_Sprite;
		/*std::vector<sf::Sprite> scoringPipes;*/
		sf::Sprite fire_Sprite;
		sf::Sprite explosion_Sprite;
		
		float acceleration_y;
		sf::Vector2f vel;
		int _landHeight;
		int _asteroidSpawnXoffset;

		int health;

	private:
		GameDataRef _data;
	};
}
