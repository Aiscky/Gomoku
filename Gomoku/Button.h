#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <Windows.h>

class Button
{
protected:
	sf::Color _idleColor;
	sf::Color _activeColor;
	sf::Color _pressedColor;
	sf::RenderWindow *_window;
	sf::RectangleShape _buttonBackground;
	sf::Font _buttonFont;
	sf::Text _buttonContent;
	bool _isEnabled;

public:
	Button(sf::Color idleColor,
		sf::Color activeColor,
		sf::Color pressedColor,
		unsigned int buttonWidth,
		unsigned int buttonHeight,
		unsigned int buttonOriginX,
		unsigned int buttonOriginY,
		std::string buttonContent,
		bool isEnabled);

	virtual ~Button() {};
	void Display(sf::RenderWindow *window);
	virtual bool ButtonPressed() = 0;
	void centerTextInBackground();
};

