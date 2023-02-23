#pragma once
#include "Asteroids.hpp"
#include <iostream>
namespace Flappy
{
	Asteroid::Asteroid(GameDataRef data): _data(data)
	{
		vel = sf::Vector2f{ 3.0,0.0 };
		_asteroidSpawnXoffset = 0;

		asteroid_Sprite.setTexture(_data->assets.GetTexture("Asteroid"));
		asteroid_Sprite.setScale(0.25, 0.25);

		fire_Sprite.setTexture(_data->assets.GetTexture("Asteroid Fire"));
		fire_Sprite.setScale(0.25, 0.25);

		explosion_Sprite.setTexture(_data->assets.GetTexture("Explosion"));
		explosion_Sprite.setScale(0.25, 0.25);

		_asteroid_state = ASTEROID_STATE_NORMAL;
		
		
	}


	void Asteroid::MoveAsteroids(float dt, float land)
	{	
		if (_asteroid_state == ASTEROID_STATE_NORMAL)
		{
			float distance_y = 10.0 + land - asteroid_Sprite.getPosition().y;

			asteroid_Sprite;
			acceleration_y = distance_y * GRAVITY * dt * 0.03;

			vel.y += acceleration_y;
			fire_Sprite.move(-vel.x, vel.y);
			asteroid_Sprite.move(-vel.x, vel.y);
		}
		if (_asteroid_state == ASTEROID_STATE_EXPLOSION)
		{
			
			acceleration_y = 0.0;
			asteroid_Sprite.move(-vel.x, 0.0);
		}
	}
	
	void Asteroid::DrawAsteroids()
	{
		if (_asteroid_state == ASTEROID_STATE_EXPLOSION)
		{
			
			this->_data->window.draw(explosion_Sprite);
		}
		if (_asteroid_state == ASTEROID_STATE_NORMAL)
		{

			
			this->_data->window.draw(fire_Sprite);
			this->_data->window.draw(asteroid_Sprite);
		}
		
	}
	void Asteroid::RandomiseAsteroidOffset()
	{
		_asteroidSpawnXoffset = rand() % (_data->window.getSize().x + 1);
	}
	sf::Sprite & Asteroid::GetSprite() 
	{
		return asteroid_Sprite;
	}
	sf::Sprite& Asteroid::Get_FireSprite()
	{
		return fire_Sprite;
	}
	sf::Sprite& Asteroid::Get_Explosion_Sprite()
	{
		return explosion_Sprite;
	}
}