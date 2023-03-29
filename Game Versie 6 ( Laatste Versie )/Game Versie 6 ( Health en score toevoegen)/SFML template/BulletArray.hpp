#pragma once
#include "Bullet.hpp"
#include "Wapen.hpp"
#include <vector>
#include <iostream>
namespace Flappy
{
	class Bullet_Array
	{
	private:
		GameDataRef _data;
		std::vector<Bullet> bullets;
		sf::Clock clock;
		int magazineSize = 8;
		float reloadSpeed = 0.1;
		
	public:

		Bullet_Array(GameDataRef data );
		void SpawnBullet( Wapen *weapon );
		void DestroyBullet( int index );
		void MoveBullets();
		void Draw_Bullets();
		void checkOffScreen();
		std::vector<Bullet> Get_Sprites();
		// Asteroid bulletFactory( std::string asteroidName );

		
	};
}