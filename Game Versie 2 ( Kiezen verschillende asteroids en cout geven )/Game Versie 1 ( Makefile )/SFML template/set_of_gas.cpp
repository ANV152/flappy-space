#include "set_of_gas.hpp"
namespace Flappy
{
	Gasoline::Gasoline(GameDataRef data): _data(data)
	{
		vel = sf::Vector2f{ 4.0,0.0 };
		_GasSpawnYoffset = 0;

	}
	void Gasoline::SpawnGasoline(float landheight)
	{
		sf::Sprite newGasoline;
		_GasSpawnYoffset = rand() % (int)landheight;
		newGasoline.setTexture(_data->assets.GetTexture("Gas"));
		newGasoline.setScale(0.1, 0.1);
		newGasoline.setPosition(_data->window.getSize().x, _GasSpawnYoffset);
		set_of_gasolines.push_back(newGasoline);
		
	}
	void Gasoline::MoveGasoline(float dt)
	{
		for (unsigned short int i = 0; i < set_of_gasolines.size(); i++)
		{
			set_of_gasolines.at(i).move(-vel.x, 0.0);
		}
	}

	void Gasoline::DrawGasoline()
	{
		for (unsigned short int i = 0; i < set_of_gasolines.size(); i++)
		{
			this->_data->window.draw(set_of_gasolines.at(i));
		}
	}
	 std::vector<sf::Sprite>&Gasoline::GetSprite() 
	{
		return set_of_gasolines;
	}

	

}
