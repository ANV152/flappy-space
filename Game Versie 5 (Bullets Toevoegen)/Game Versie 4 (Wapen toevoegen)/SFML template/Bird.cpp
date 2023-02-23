#include "Bird.hpp"

namespace Flappy
{
	Bird::Bird(GameDataRef data, sf::Vector2f vel) : _data(data), vel(vel)
	{
		_animationIterator = 0;
		_animationFrames.push_back(_data->
			assets.GetTexture("Space Bird Frame 1"));
		_animationFrames.push_back(_data->
			assets.GetTexture("Space Bird Frame 2"));
		_animationFrames.push_back(_data->
			assets.GetTexture("Space Bird Frame 3"));
		/*_animationFrames.push_back(_data->
			assets.GetTexture("Bird Frame 4"));*/
		_boostSprite.setTexture(_data->assets.GetTexture("Fire"));
		
		

		_birdSprite.setTexture(_animationFrames.at(_animationIterator));
		_birdSprite.setPosition((_data->window.getSize().x / 4) - 
			(_birdSprite.getGlobalBounds().width / 2), 
			(_data->window.getSize().y / 2) - 
			(_birdSprite.getGlobalBounds().height / 2));
		_birdState = BIRD_STATE_STILL;

		_boostSprite.setScale((_birdSprite.getGlobalBounds().width / _boostSprite.getGlobalBounds().width / 3.5),
			_birdSprite.getGlobalBounds().height / _boostSprite.getGlobalBounds().height/2);
		_boostSprite.setPosition(_birdSprite.getPosition().x, _birdSprite.getGlobalBounds().height + _birdSprite.getPosition().y);

		
	}

	Bird::~Bird()
	{
	}

	void Bird::Draw()
	{
		_data->window.draw(_birdSprite);
		if (BIRD_STATE_FLYING == _birdState)
		{
			_boostSprite.setPosition(_birdSprite.getPosition().x, _birdSprite.getGlobalBounds().height + _birdSprite.getPosition().y);
			this->_data->window.draw(_boostSprite);
		}

	}

	void Bird::Animate(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() >
			BIRD_ANIMATION_DURATION / _animationFrames.size())
		{
			if (_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}
			_birdSprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart();
		}
	}
	
	void Bird::Boost()
		{}
	void Bird::Update(float dt, float land)
	{
		
		jet_force = 0.4;
		
		distance_y = land - _birdSprite.getPosition().y;
		float force = 4.0 * dt;
		
		acceleration_y = distance_y * GRAVITY * dt * 0.5 ;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			_birdState = BIRD_STATE_FLYING;
			acceleration_y -= jet_force;
		}
		else
		{
			_birdState = BIRD_STATE_FALLING;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			acceleration_x += force + 0.1;
			vel.x -= acceleration_x;
			
		}
		else
		{
			acceleration_x = 0.0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			acceleration_y += 0.2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			acceleration_x += force + 0.2;
			vel.x += acceleration_x;
		}
		else
		{
			acceleration_x = 0.0;
		}
		

		vel.y += acceleration_y;
		_birdSprite.move(vel.x, 0.0);
		_birdSprite.move(0, vel.y);
	}

	void Bird::Tap()
	{
		_movementClock.restart();
		
		_birdState = BIRD_STATE_FLYING;

		
		
		
	}
	const sf::Sprite& Bird::GetSprite() const {
		return _birdSprite;

	}
}