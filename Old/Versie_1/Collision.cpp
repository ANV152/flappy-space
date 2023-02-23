 #include "Collision.hpp"

namespace Flappy
{
	Collision::Collision()
	{
	}

	Collision::~Collision()
	{
	}

	bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
	{
		sf::Rect<float> rect1 = sprite1.getGlobalBounds();
		sf::Rect<float> rect2 = sprite2.getGlobalBounds();

		if (rect1.intersects(rect2))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Collision::CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2, float y_offset)
	{
		sprite1.setScale(scale1, scale1);
		sprite2.setScale(scale2, scale2);
		sprite2.setPosition(sprite2.getPosition().x, sprite2.getPosition().y + y_offset);
		sf::Rect<float> rect1 = sprite1.getGlobalBounds();
		sf::Rect<float> rect2 = sprite2.getGlobalBounds();
		

		return rect1.intersects(rect2);
	}
}