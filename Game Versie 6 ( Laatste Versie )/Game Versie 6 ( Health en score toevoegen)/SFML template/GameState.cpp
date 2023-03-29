#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace Flappy
{

	GameState::GameState(GameDataRef data) : _data(data){
		
	}
	
	void GameState::Init()
	{
		if (!_Hit_sound_buffer.loadFromFile(HIT_SOUND_FILEPATH))
		{
			std::cout << "Error loading Hit Sound effect"<< std::endl;
		}
		if (!_Point_sound_buffer.loadFromFile(POINT_SOUND_FILEPATH))
		{
			std::cout << "Error loading _Point_sound_buffer effect" << std::endl;
		}
		if (!_Hit_bird_sound_buffer.loadFromFile(EXPLOSION_SOUND_FILEPATH))
		{
			std::cout << "Error loading Hit Sound effect" << std::endl;
		}
		_Hit_bird_sound.setBuffer(_Hit_bird_sound_buffer);
		_Hit_bird_sound.setVolume(50.0);
		
		_Hit_sound.setBuffer(_Hit_sound_buffer);
		_Point_Sound.setBuffer(_Point_sound_buffer);
		

		
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		this->_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		this->_data->assets.LoadTexture("Land", LAND_FILEPATH);
		this->_data->assets.LoadTexture("Space Bird Frame 1", SPACE_BIR_FRAME_1_FILEPATH);
		this->_data->assets.LoadTexture("Space Bird Frame 2", SPACE_BIR_FRAME_2_FILEPATH);
		this->_data->assets.LoadTexture("Space Bird Frame 3", SPACE_BIR_FRAME_3_FILEPATH);
		//this->_data->assets.LoadTexture("Bird Frame 4", BIR_FRAME_4_FILEPATH);
		this->_data->assets.LoadTexture("Asteroid1", ASTEROID1_FILEPATH);
		this->_data->assets.LoadTexture("Asteroid2", ASTEROID2_FILEPATH);
		this->_data->assets.LoadTexture("Asteroid Fire", ASTEROID_FIRE_FILEPATH);
		this->_data->assets.LoadTexture("Gas", GAS_FILEPATH);
		this->_data->assets.LoadTexture("Wapen", WAPEN_FILEPATH);
		this->_data->assets.LoadTexture("Bullet", BULLET_FILEPATH);
		this->_data->assets.LoadTexture("Explosion", EXPLOSION_FILEPATH);

		this->_data->assets.LoadTexture("Fire", FIRE_BOOST_FILE_PATH);
		this->_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);
		
		
		
		

		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data, sf::Vector2f{0.0, -5.0});
		flash = new Flash(_data);
		hud = new HUD(_data);
		asteroids = new Falling_Asteroids(_data, 0);
		asteroids_2 = new Falling_Asteroids(_data, _data->window.getSize().x / 2);
		gasoline = new Gasoline(_data);
		wapen = new Wapen(_data, false);
		wapen->getSprite().setOrigin(wapen->getSprite().getGlobalBounds().width/2, wapen->getSprite().getGlobalBounds().height/2);
		bullets = new Bullet_Array( _data );

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		_score = 0;
		hud->UpdateScore(_score);

		_gameState = GameStates::ePlaying;
		

	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}		
			
		}
	}
	


	void GameState::Update(float dt)
	{
		

		float ground_height = land->GetSprites()[0].getPosition().y;
		

		if (GameStates::eGameOver != _gameState) 
		{
			bird->Animate(dt);
			
			land->MoveLand(dt);
			asteroids->Throw_Asteroid(dt, ground_height);
			asteroids_2->Throw_Asteroid(dt, ground_height);
		}
		if (GameStates::ePlaying == _gameState) 
		 {
			land->MoveLand(dt);
			
			asteroids->Throw_Asteroid(dt, ground_height);
			asteroids_2->Throw_Asteroid(dt, ground_height);
			
			if (clock_1.getElapsedTime().asSeconds() > ASTEROID_SPAWN_FREQUENCY )
			{
				asteroids->SpawnAsteroids();
				asteroids_2->SpawnAsteroids();
				clock_1.restart();
			}
			if (clock_2.getElapsedTime().asSeconds() > GASOLINE_SPAWN_FREQUENCY)
			{
				gasoline->SpawnGasoline(ground_height);
				clock_2.restart();
			}

			if(collision.CheckSpriteCollision(bird->GetSprite(), wapen->getSprite()) && wapen->Get_wapen_state() == false)
			{				
				wapen->Set_wapen_on();
			}

			if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) {
				bullets->SpawnBullet( wapen );
			}

			wapen->Update(dt,bird);
			bird->Update(dt, ground_height);
			asteroids->Throw_Asteroid(dt, ground_height);
			gasoline->MoveGasoline(dt);
			bullets->MoveBullets();
			bullets->checkOffScreen();

			std::vector<Bullet> Bullets = bullets->Get_Sprites();
			std::vector<Asteroid> Asteroids = asteroids->Get_Sprites();
			std::vector<Asteroid> Asteroids2 = asteroids_2->Get_Sprites();
			for ( unsigned int i = 0; i < Bullets.size(); i++ ) {
				for( unsigned int j = 0; j < Asteroids.size(); j++ ) {
					if( collision.CheckSpriteCollision( Bullets[i].GetSprite(), 0.5, Asteroids[j].GetSprite(), 0.5 ) ) {
						bullets->DestroyBullet(i); // Veranderen naar lowerBulletHP().
						asteroids->updateAsteroidHealth(j); // Veranderen naar lowerAsteroidHP().

						_score++;
						this->hud->UpdateScore(_score);
						std::cout << "Hit" << "\n";
					}
				}
				for( unsigned int j = 0; j < Asteroids2.size(); j++ ) {
					if( collision.CheckSpriteCollision( Bullets[i].GetSprite(), 0.5, Asteroids2[j].GetSprite(), 0.5 ) ) {
						bullets->DestroyBullet(i); // Veranderen naar lowerBulletHP().
						asteroids_2->updateAsteroidHealth(j); // Veranderen naar lowerAsteroidHP().

						_score++;
						this->hud->UpdateScore(_score);
						std::cout << "Hit2" << "\n";
					}
				}
			}

			//Check collision with Land
			std::vector<sf::Sprite> landSprites = land->GetSprites();
			for (int i = 0; i < landSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(bird->GetSprite(),1.0f,
					landSprites.at(i),0.8f))
				{
					_gameState = GameStates::eGameOver;
					clock_1.restart();
				}
			}

			//Check collision with asteroids
			std::vector<Asteroid> asteroid_Sprites = asteroids->Get_Sprites();
			for (int i = 0; i < asteroid_Sprites.size(); i++)
			{
				if (asteroid_Sprites.at(i).GetSprite().getPosition().y > ground_height)
				{
					_Hit_bird_sound.play();
				}
				if (collision.CheckSpriteCollision(bird->GetSprite(), 0.75f,
					asteroid_Sprites.at(i).GetSprite(), 0.2f))
				{
					
					_Hit_bird_sound.play();
					_gameState = GameStates::eGameOver;
					clock_1.restart();
				}
				
			}
			
			std::vector<Asteroid> asteroid_Sprites_2 = asteroids_2->Get_Sprites();
			for (int i = 0; i < asteroid_Sprites_2.size(); i++)
			{
				if (collision.CheckSpriteCollision(bird->GetSprite(), 0.75f,
					asteroid_Sprites_2.at(i).GetSprite(), 0.2f))
				{
					_Hit_bird_sound.play();
					_gameState = GameStates::eGameOver;
					clock_1.restart();
				}
			}

			if (_gameState == GameStates::ePlaying)
			{
				std::vector<sf::Sprite> gasoline_Sprites = gasoline->GetSprite();
				for (int i = 0; i < gasoline_Sprites.size(); i++)
				{
					if (collision.CheckSpriteCollision(bird->GetSprite(), 0.75f,
						gasoline_Sprites.at(i), 0.1))
					{

						_Point_Sound.play();
						gasoline_Sprites.erase(gasoline_Sprites.begin() + i);
						gasoline->GetSprite().erase(gasoline->GetSprite().begin() + i);
						_score+=10;
						this->hud->UpdateScore(_score);
						
					}
				}
				
				

			}
		}
		if (GameStates::eGameOver == _gameState)
		{
			flash->Show(dt);
			if (clock_1.getElapsedTime().asSeconds() >= TIME_BEFORE_GAMEOVER_SHOW)
			{
				_data->machine.AddState(StateRef(new GameOverState(_data, _score)));
			}
		}
		
		
	}

	void GameState::Draw(float dt)
	{
		turnVolume(this->_data, dt, false, 5.0);
		
		this->_data->window.clear(sf::Color::Red);
		
		this->_data->window.draw(this->_background);
		
		
		this->land->DrawLand();
		this->asteroids->Draw_Asteroids();
		this->asteroids_2->Draw_Asteroids();
		this->bullets->Draw_Bullets();
		this->bird->Draw();
		this->wapen->Draw();
		this->flash->Draw();
		this->hud->Draw();
		this->gasoline->DrawGasoline();
		this->_data->window.display();
	}
	
}