#pragma once
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "Land.hpp"
#include <vector>

namespace Flappy {
	class Gasoline
	{
	private:
		GameDataRef _data;
		sf::Sprite gasoline_Sprite;
		float _GasSpawnYoffset;
		sf::Vector2f vel;
		std::vector<sf::Sprite> set_of_gasolines;

	public:

		Gasoline(GameDataRef data);

		void SpawnGasoline(float landheight);

		void MoveGasoline(float dt);
		void DrawGasoline();
	
		std::vector<sf::Sprite> &GetSprite() ;

	};


}

