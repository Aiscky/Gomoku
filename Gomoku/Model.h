#pragma once

#include <SFML/Graphics.hpp>

class Model
{
public:
	virtual ~Model() {};
	virtual void Display(sf::RenderWindow *window) = 0;
};