#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.hpp"
#include "Bird.hpp"
#include "DEFINITIONS.hpp"
namespace Flappy
{
    class Wapen
    {
        private:
            GameDataRef _data;
            bool weapon_state;
            sf::Sprite wapen;
            sf::Mouse mouse;
            bool flip;
            float vel_x;
        
        public:
            Wapen(GameDataRef _data ,  bool weapon_state);
            ~Wapen();
            float get_degrees_from_sprite(sf::Mouse m , sf::Sprite w);
            // void rotate_wapen(float degrees);
            void Update( float dt, Bird *b);
            void Draw();
            bool Get_wapen_state();
            void Set_wapen_on();
            sf::Sprite getSprite();
            
    };
}