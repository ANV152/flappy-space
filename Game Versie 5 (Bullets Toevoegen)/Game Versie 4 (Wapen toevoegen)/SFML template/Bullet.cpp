#pragma once
#include "Bullet.hpp"
#include "math.h"
#include <iostream>
namespace Flappy
{
	Bullet::Bullet(GameDataRef data): 
	_data(data) 
	// Asteroid::Asteroid( GameDataRef data, sf::Texture AsteroidTexture, sf::Texture FireTexture, sf::Texture ExplosionTexture ).
	// Of erf in subklasse over van asteroid en plaats de textures zoals hier in de constructor en maak constructor anders per asteroid.
	{
		// Textures worden nu dus meegegeven en in aparte cpp worden verschillende asteroids gemaakt waaruit gekozen kan worden.
		// Dit gaat dus weg uit deze constructor en wordt in de constructor van de kleinere verschillende asteroid subklassen gedaan.
		Bullet_Sprite.setTexture(_data->assets.GetTexture("Bullet"));
		Bullet_Sprite.setScale(0.25, 0.25);

		_bullet_state = 1;	
	}

	void Bullet::MoveBullet()
	{	
		Bullet_Sprite.move( vel );
	}

	void Bullet::calculateBulletVel( Wapen *weapon )
	{	
		sf::Vector2i mousePosition = mouse.getPosition(_data->window);
		float relativeX = mousePosition.x - weapon->getWapenPosition().x;
		float relativeY = mousePosition.y - weapon->getWapenPosition().y;

		// Controleer of de gun naar links of rechts schiet.
		// Als de gun links schiet gewoon het aantal graden gebruiken maar dan de velocity negatief maken.
		if( relativeX < 0 ) {
			// To convert degrees to radians, multiply degrees by Pi/180.
			float y_Offset = tan( get_raw_degrees( relativeX, relativeY ) * 3.14159265359 / 180 ) * 1; // y_Offset for 1 x so if you want 3 x multiply the y_Offset by 3 as well.
			vel = sf::Vector2f( ( -bulletSpeed ) * 2, ( -y_Offset * bulletSpeed ) * 2 ); // Twee keer zo snel omdat scherm mee beweegt.
		}
		else {
			// To convert degrees to radians, multiply degrees by Pi/180.
			float y_Offset = tan( get_raw_degrees( relativeX, relativeY ) * 3.14159265359 / 180 ) * 1; // y_Offset for 1 x so if you want 3 x multiply the y_Offset by 3 as well.
			vel = sf::Vector2f( ( +bulletSpeed ), ( y_Offset * bulletSpeed ) );
		}
	}
	
	void Bullet::DrawBullet()
	{
		this->_data->window.draw( Bullet_Sprite );
	}

	sf::Sprite & Bullet::GetSprite() 
	{
		return Bullet_Sprite;
	}

	float Bullet::get_raw_degrees( float relativeX, float relativeY ) { // Test voor andere implementatie graden zonder flip.
        // Momenteel is de hoek voor als de muis voor of achter de speler is hetzelfde.
        // Misschien handig om toe te voegen dat als de afstand negatief is dat het op een andere manier wordt gedaan dan als de afstand positief is.
        // Als relativeX negatief is 180 toevoegen aan de degrees.
		// To convert degrees to radians, multiply degrees by Pi/180.
		float degrees = atan( ( relativeY * 3.14159265359 / 180 ) / ( relativeX * 3.14159265359 / 180 ) ); // Overstaand delen door aanliggend.
        degrees = degrees / ( 3.14159265359 / 180 );
        return degrees;
    }

}