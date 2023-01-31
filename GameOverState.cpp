#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"
#include <iostream>
#include <fstream>

namespace Flappy
{
	GameOverState::GameOverState(GameDataRef data, int  score ): _data(data), _score(score)
	{

	}

	void GameOverState::Init()
	{
		std::ifstream readScore;
		readScore.open("Highest_score.txt");
		if (readScore.is_open())
		{
			while (!readScore.eof())
			{
				readScore >> _highScore;
			}
			
		}
		readScore.close();
		std::ofstream writeFile("Highest_score.txt");
		if (writeFile.is_open())
		{
			if (_score > _highScore)
			{
				_highScore = _score;
			}
			writeFile << _highScore;
		}
		writeFile.close();
		this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));

		_background.setScale(this->_data->window.getSize().x / _background.getGlobalBounds().width,
			this->_data->window.getSize().y / _background.getGlobalBounds().height);

		_title.setTexture(this->_data->assets.GetTexture("Game Over Title"));
		_GameOver_Container.setTexture(this->_data->assets.GetTexture("Game Over Body"));
		_play_again_Button.setTexture(this->_data->assets.GetTexture("Play Button"));

		_title.setScale(0.25, 0.25);
		_title.setPosition((SCREEN_WIDTH / 2) - _title.getGlobalBounds().width / 2, (SCREEN_HEIGHT / 2) - _title.getGlobalBounds().height / 2);

		_GameOver_Container.setScale(1.5,1.5);

		_GameOver_Container.setPosition(_data->window.getSize().x / 2 - (_GameOver_Container.getGlobalBounds().width / 2),
			(_data->window.getSize().y / 2 - (_GameOver_Container.getGlobalBounds().height / 2)));
		_play_again_Button.setPosition(_data->window.getSize().x / 2 - (_play_again_Button.getGlobalBounds().width / 2),
			(_GameOver_Container.getPosition().y + _GameOver_Container.getGlobalBounds().height + _play_again_Button.getGlobalBounds().height *0.2));

		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_scoreText.setString( std::to_string(_score));
		_scoreText.setCharacterSize(75);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2,
			_scoreText.getGlobalBounds().height / 2);
		_scoreText.setPosition(_data->window.getSize().x / 10 * 7.25, 
			_data->window.getSize().y * 0.45);

		_highScoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_highScoreText.setString(std::to_string(_highScore));
		_highScoreText.setCharacterSize(70);
		_highScoreText.setFillColor(sf::Color::White);

		_highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2,
			_highScoreText.getGlobalBounds().height / 2);
		_highScoreText.setPosition(_data->window.getSize().x / 10 * 7.25,
			_data->window.getSize().y * 0.60);
	}

	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (_data->input.IsSpriteClicked(_play_again_Button, sf::Mouse::Left,
				_data->window))
			{
				this->_data->machine.AddState(StateRef(new GameState(this->_data)), true);
			}
		}
	}

	void GameOverState::Update(float dt)
	{
	
		float _scale_x = _title.getScale().x + SCALE_SPEED* dt;
		float _scale_y = _title.getScale().y + SCALE_SPEED * dt;
		
		if (_scale_x >= 1.0 || _scale_y >= 1.0 ) {

			_scale_y = 1.0;
			_scale_x = 1.0;
			
		}
		else
		{
			//std::cout << time_scale << std::endl;
			_title.setScale(_scale_x, _scale_y);
			_title.setPosition(_data->window.getSize().x / 2 - (_title.getGlobalBounds().width / 2),
				_GameOver_Container.getPosition().y - _title.getGlobalBounds().height * 1.2);
		}

	}

	void GameOverState::Draw(float dt)
	{
		turnVolume(this->_data, dt, true, 50.0);

		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_GameOver_Container);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_play_again_Button);
		this->_data->window.draw(this->_scoreText);
		this->_data->window.draw(this->_highScoreText);
		
		this->_data->window.display();
	}
}