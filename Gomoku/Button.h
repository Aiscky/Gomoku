#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <Windows.h>

class Button
{

protected:
	sf::RenderWindow *_window;
	sf::Font _buttonFont;
	sf::Text _buttonContent;
	bool _isEnabled;

public:
	Button(unsigned int buttonOriginX, unsigned int buttonOriginY, std::string buttonContent);

	virtual ~Button() {};

	void Display(sf::RenderWindow *window);
	virtual bool ButtonPressed() = 0;
};

