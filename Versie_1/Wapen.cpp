 #include "Wapen.hpp"
 #include "sin.hpp"
 #include <iostream>
#include <math.h>
 namespace Flappy
 {
    
    Wapen::Wapen(GameDataRef _data, bool weapon_state): _data(_data), weapon_state(weapon_state)
    {
        wapen.setTexture(_data->assets.GetTexture("Geweer"));
        flip = false;
        vel_x = -2.0;
        wapen.setOrigin(wapen.getGlobalBounds().width/2, wapen.getGlobalBounds().height/2 );
        wapen.setPosition(_data->window.getSize().x ,  _data->window.getSize().y / 2);
        wapen.setScale(0.25,0.25);

        
    }
    Wapen::~Wapen()
    {
    }
    float Wapen::get_degrees_from_sprite(sf::Mouse m , sf::Sprite w)
    {
        float x_distance = m.getPosition(_data->window).x - (w.getPosition().x + w.getGlobalBounds().width/16);
        float y_distance = m.getPosition(_data->window).y - (w.getPosition().y + w.getGlobalBounds().height/32);

        //Vectoren normaliseren
        float normalize_distance = sqrtf(x_distance * x_distance + y_distance * y_distance);

        float sin = y_distance / normalize_distance;
        float cos = x_distance / normalize_distance;
                
       if(cos > 0 && sin <= 0)
       {
            flip = false;
            return 90 * (sin);
       }
        if(cos < 0 && sin < 0)
        {
            flip = true;

            return 90 * (cos) - 90;
        }
        if(cos > 0 && sin > 0)
        {
            flip = false;

            return 90 * (sin);
        }
        if(cos < 0 && sin >= 0)
        {
            flip = true;
            return 90 * ( -sin) + 180 ;
        }
       
    }
    void Wapen::Update( float dt, Bird *b)
    {
        if (weapon_state){   
           
            wapen.setPosition(b->GetSprite().getPosition().x + wapen.getGlobalBounds().width /2, 
                        b->GetSprite().getPosition().y + wapen.getGlobalBounds().height/2  );

            
            if (flip)
            {
                wapen.setScale(0.25, -0.25);
            }
            else
            {
                wapen.setScale(0.25, 0.25);
            }
            
            wapen.setRotation(get_degrees_from_sprite(mouse, wapen));
        }
        else{
            wapen.move(vel_x, 0.0);
        }

    }
    bool Wapen::Get_wapen_state()
    {
        return weapon_state;
    }
    void Wapen::Set_wapen_on()
    {
        weapon_state = true;
    }
    sf::Sprite Wapen::getSprite()
    {
        return wapen;
    }
    void Wapen::Draw()
    {
        
        _data->window.draw(wapen);
    }
 }