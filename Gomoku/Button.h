#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

class Button
{
protected:
	sf::Color _idleColor;
	sf::Color _activeColor;
	sf::Color _pressedColor;
	sf::RenderWindow *_window;
	std::tuple<unsigned int, unsigned int> _buttonSize;
	std::tuple<unsigned int, unsigned int> _buttonOrigin;
	sf::Text _content;
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

	virtual ~Button() = 0;
	virtual void Display(sf::RenderWindow *window) = 0;
	virtual bool ButtonPressed() = 0;
};

