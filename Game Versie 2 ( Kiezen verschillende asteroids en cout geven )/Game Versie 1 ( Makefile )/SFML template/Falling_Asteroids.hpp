#pragma once
#include "Asteroids.hpp"
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
		void Throw_Asteroid(float dt, float land);
		std::vector<Asteroid> Get_Sprites();
		void Draw_Asteroids();
		Asteroid asteroidFactory( std::string asteroidName );

		
	};
}