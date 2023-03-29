#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Asteroids.hpp"
#include "Game.hpp"

namespace Flappy{
    class Asteroid1 : public Asteroid {
        private:
            GameDataRef _data;

        public:
            Asteroid1( GameDataRef _data ) :
                Asteroid( _data ),
                _data( _data )
            {
                vel = sf::Vector2f{ 3.0,0.0 };
                _asteroidSpawnXoffset = 0;

                // Textures worden nu dus meegegeven en in aparte cpp worden verschillende asteroids gemaakt waaruit gekozen kan worden.
                // Dit gaat dus weg uit deze constructor en wordt in de constructor van de kleinere verschillende asteroid subklassen gedaan.
                asteroid_Sprite.setTexture(_data->assets.GetTexture("Asteroid1"));
                asteroid_Sprite.setScale(0.25, 0.25);

                fire_Sprite.setTexture(_data->assets.GetTexture("Asteroid Fire"));
                fire_Sprite.setScale(0.25, 0.25);

                explosion_Sprite.setTexture(_data->assets.GetTexture("Explosion"));
                explosion_Sprite.setScale(0.25, 0.25);

                _asteroid_state = ASTEROID_STATE_NORMAL;

                health = 1;
            }

            void test() {
                std::cout << "boop" << "\n";
            }
    };

    class Asteroid2 : public Asteroid {
        private:
            GameDataRef _data;

        public:
            Asteroid2( GameDataRef _data ) :
                Asteroid( _data ),
                _data( _data )
            {
                vel = sf::Vector2f{ 3.0,0.0 };
                _asteroidSpawnXoffset = 0;

                // Textures worden nu dus meegegeven en in aparte cpp worden verschillende asteroids gemaakt waaruit gekozen kan worden.
                // Dit gaat dus weg uit deze constructor en wordt in de constructor van de kleinere verschillende asteroid subklassen gedaan.
                asteroid_Sprite.setTexture(_data->assets.GetTexture("Asteroid2"));
                asteroid_Sprite.setScale(0.4, 0.4);

                fire_Sprite.setTexture(_data->assets.GetTexture("Asteroid Fire"));
                fire_Sprite.setScale(0.4, 0.4);

                explosion_Sprite.setTexture(_data->assets.GetTexture("Explosion"));
                explosion_Sprite.setScale(0.4, 0.4);

                _asteroid_state = ASTEROID_STATE_NORMAL;

                health = 3;
            }

            void test() {
                std::cout << "boop" << "\n";
            }
    };
}

#endif