#pragma once

#include <SFML/Graphics.hpp>

class Model
{
public:
	virtual ~Model() = 0;
	virtual void Display(sf::RenderWindow *window) = 0;
};