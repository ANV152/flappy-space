#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "InputManager.hpp"
#include <iostream>

namespace Flappy
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Subtitle", GAME_SUBTITLE_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_subtitle.setTexture(this->_data->assets.GetTexture("Subtitle"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		_subtitle.setScale(0.9, 0.9);

		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
		_subtitle.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2) + 50, _title.getPosition().y + _title.getGlobalBounds().height + _subtitle.getGlobalBounds().height);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT * 0.7) - (_playButton.getGlobalBounds().height / 2));
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
			{
				// Switch To Main Menu
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void MainMenuState::Update(float dt)
	{
		
	}

	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_subtitle);
		this->_data->window.draw(this->_playButton);

		this->_data->window.display();
	}
}