#pragma once
#include <SFML/Graphics.hpp>
class Gravity
{
private:

	float strength;
	float y_source;
	
public:

	Gravity(float strength);
	
	float getStrength();

};