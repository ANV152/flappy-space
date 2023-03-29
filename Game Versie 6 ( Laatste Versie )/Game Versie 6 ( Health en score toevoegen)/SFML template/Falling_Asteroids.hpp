#pragma once
#include "AsteroidVersions.hpp"
#include <vector>
#include <iostream>
namespace Flappy
{
	class Falling_Asteroids 
	{
	private:
		
		GameDataRef _data;
		std::vector<Asteroid> asteroids;
		std::vector<std::string> asteroidNames;
		int _asteroidSpawnXoffset;
		int Screen_section;

		sf::Clock clock;

		
		
	public:

		Falling_Asteroids(GameDataRef data, int Screen_section );
		int  asteroidSpawnXoffset();
		void SpawnAsteroids();
		void DestroyAsteroid( int index );
		void Throw_Asteroid(float dt, float land);
		void updateAsteroidHealth( int i );
		std::vector<Asteroid> Get_Sprites();
		void Draw_Asteroids();
		Asteroid asteroidFactory( std::string asteroidName );

		
	};
}