#pragma once
#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
namespace Flappy {
	class action {
	private:
		std::function< bool() > condition;
		std::function< void() > work;
	public:
		action() {}
		action(
			std::function< bool() > condition,
			std::function< void() > work
		);

		action(
			sf::Keyboard::Key key,
			std::function< void() > work
		);

		action(
			sf::Mouse::Button button,
			std::function< void() > work
		);
		action(
			bool unconditional,
			std::function<void()> work
		);


		void operator()();
	};
};