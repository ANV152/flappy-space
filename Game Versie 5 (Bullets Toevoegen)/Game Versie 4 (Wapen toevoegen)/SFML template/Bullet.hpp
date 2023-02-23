#pragma once


#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Wapen.hpp"
#include <vector>
#include "DEFINITIONS.hpp"
namespace Flappy
{
	class Bullet
	{
	public:
		Bullet( GameDataRef data );
		void calculateBulletVel( Wapen *weapon );
		void MoveBullet();
		void DrawBullet();
		float get_raw_degrees( float relativeX, float relativeY );
		sf::Mouse mouse;
		sf::Sprite & GetSprite();
		int _bullet_state;
		
	protected: // Protected gemaakt omdat anders moet je voor elke waarden een aparte get maken en heeft niet zoveel nut want alleen de asteroid versions gebruikt deze.
		sf::Sprite Bullet_Sprite;
		sf::Vector2f vel;
		float bulletSpeed = 6.0;

	private:
		GameDataRef _data;
	};
}
