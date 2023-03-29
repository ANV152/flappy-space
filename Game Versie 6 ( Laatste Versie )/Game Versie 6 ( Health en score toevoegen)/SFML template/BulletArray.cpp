#include "BulletArray.hpp"
#include <iostream>
#include <random>
namespace Flappy
{
	Bullet_Array::Bullet_Array( GameDataRef data ) : 
	_data(data)
	{
	}

	void Bullet_Array::SpawnBullet( Wapen *weapon )
	{
		if( weapon->Get_wapen_state() ) {
			if( bullets.size() < magazineSize && clock.getElapsedTime().asSeconds() > reloadSpeed ) {
				Bullet bullet( _data );
				bullet.calculateBulletVel( weapon );
				//std::cout << _asteroidSpawnXoffset << std::endl;

				bullet.GetSprite().setPosition( weapon->getWapenPosition() );
			
				bullets.push_back( bullet );
				clock.restart();
			}
		}
	}

	void Bullet_Array::DestroyBullet( int index ) {
		bullets.erase( bullets.begin() + index );
	}

	void Bullet_Array::MoveBullets()
	{
		for( Bullet &bullet : bullets ) { // Reference nodig anders update hij de positie niet.
			bullet.MoveBullet();
		}
	}

	void Bullet_Array::Draw_Bullets()
	{
		for( Bullet &bullet : bullets ) { // Reference nodig anders drawed hij wel maar niet het object die in de lijst staat maar een kopie daarvan dus daar kan je niet zo veel mee.
			bullet.DrawBullet();
		}
	}

	void Bullet_Array::checkOffScreen() {
		for( unsigned int i = 0; i < bullets.size(); i++ ) { // Reference nodig anders drawed hij wel maar niet het object die in de lijst staat maar een kopie daarvan dus daar kan je niet zo veel mee.
			if( bullets.at(i).GetSprite().getPosition().x < 0 || bullets.at(i).GetSprite().getPosition().x > _data->window.getSize().x ) {
				bullets.erase( bullets.begin() + i );
			}
			else if( bullets.at(i).GetSprite().getPosition().y < 0 || bullets.at(i).GetSprite().getPosition().y > _data->window.getSize().y ) {
				bullets.erase( bullets.begin() + i );
			}
		}
	}

	std::vector<Bullet> Bullet_Array::Get_Sprites()
	{
		return bullets;
	}

}