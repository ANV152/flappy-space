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
		void SpawnAsteroid();
		
		void MoveAsteroids(float dt, float land);
		void DrawAsteroids();
		void RandomiseAsteroidOffset();
		sf::Sprite & GetSprite() ;
		sf::Sprite& Get_FireSprite();
		sf::Sprite& Get_Explosion_Sprite();
		//std::vector<sf::Sprite>& GetScoringSprites();
		int _asteroid_state;
	private:
		GameDataRef _data;
		sf::Sprite asteroid_Sprite;
		/*std::vector<sf::Sprite> scoringPipes;*/

		sf::Sprite fire_Sprite;
		sf::Sprite explosion_Sprite;


	
		
		float acceleration_y;
		sf::Vector2f vel;
		int _landHeight;
		int _asteroidSpawnXoffset;
	};
}
