#include "Falling_Asteroids.hpp"
#include <iostream>
#include <random>
namespace Flappy
{
	Falling_Asteroids::Falling_Asteroids( GameDataRef data, int Screen_section ) : 
	_data(data), 
	Screen_section(Screen_section)
	{
	}
	int  Falling_Asteroids::asteroidSpawnXoffset()
	{
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(Screen_section, _data->window.getSize().x); // define the range

		return distr(gen);
	}

	void Falling_Asteroids::SpawnAsteroids()
	{
		float _asteroidSpawnXoffset;
		float _asteroidSpawnYoffset;
		Asteroid asteroid = asteroidFactory( _data->asteroidNames[ rand() % _data->asteroidNames.size() ]);
		
		_asteroidSpawnXoffset = asteroidSpawnXoffset();
		_asteroidSpawnYoffset = rand() %_data->window.getSize().y/8 ;

		//std::cout << _asteroidSpawnXoffset << std::endl;

		asteroid.GetSprite().setPosition(_data->window.getSize().x /2+ _data->window.getSize().x - _asteroidSpawnXoffset ,
			 -_asteroidSpawnYoffset - asteroid.GetSprite().getGlobalBounds().height);
		asteroid.Get_FireSprite().setPosition(_data->window.getSize().x /2 + _data->window.getSize().x - _asteroidSpawnXoffset ,
			-_asteroidSpawnYoffset - (asteroid.GetSprite().getGlobalBounds().height * 2));
		
		asteroids.push_back(asteroid);
	}

	void Falling_Asteroids::Throw_Asteroid(float dt, float land)
	{
		
		for (unsigned short int i = 0; i < asteroids.size(); i++)
		{
			
			asteroids.at(i).MoveAsteroids(dt, land);
			if (asteroids.at(i).GetSprite().getPosition().y > land)
			{
				
				
				clock.restart();
				if (clock.getElapsedTime().asSeconds() > EXPLOSION_DURATION)
				{
					asteroids.erase(asteroids.begin() + i);
					clock.restart();
				}
				else
				{
					
					asteroids.at(i)._asteroid_state = ASTEROID_STATE_EXPLOSION;
					asteroids.at(i).Get_Explosion_Sprite().setPosition(asteroids.at(i).GetSprite().getPosition().x,
						asteroids.at(i).GetSprite().getPosition().y);
					
				}
				
			}
			

		}
	}

	std::vector<Asteroid> Falling_Asteroids::Get_Sprites()
	{
		return asteroids;
	}

	void Falling_Asteroids::Draw_Asteroids()
	{
		for (unsigned short int i = 0; i < asteroids.size(); i++) // For( Asteroid ast : asteroids ).
		{
			asteroids.at(i).DrawAsteroids();
		}
	}

	Asteroid Falling_Asteroids::asteroidFactory( std::string asteroidName ) { // Returned nu een soort asteroid.
		if( asteroidName == "Asteroid1" ) {
			std::cout << "Spawned Asteroid1.";
			return Asteroid1( _data );
		}
		else if ( asteroidName == "Asteroid2" ){
			std::cout << "Spawned Asteroid2.";
			return Asteroid2( _data );
		}
		std::cout << "Geen geldig object gevonden.";
	}

}