#include "Button.h"
#include <tuple>

Button::Button(
	sf::Color idleColor,
	sf::Color activeColor,
	sf::Color pressedColor,
	unsigned int buttonWidth,
	unsigned int buttonHeight,
	unsigned int buttonOriginX,
	unsigned int buttonOriginY,
	std::string buttonContent,
	bool isEnabled)
{
	_idleColor = idleColor;
	_activeColor = activeColor;
	_pressedColor = pressedColor;
	_isEnabled = isEnabled;

	_buttonBackground.setPosition(buttonOriginX, buttonOriginY);
	_buttonBackground.setSize(sf::Vector2f(buttonWidth, buttonHeight));
	_buttonBackground.setFillColor(sf::Color::Black);

	//TODO set text content,
	//TODO Make a font manager

	if (!_buttonFont.loadFromFile("Track.ttf"))
	{
		OutputDebugString(strerror_s(errno));
		OutputDebugString("Failed to load font\n");
		exit(EXIT_FAILURE);
	}

	_buttonContent.setFont(_buttonFont);
	_buttonContent.setString(buttonContent);
	_buttonContent.setColor(sf::Color::White);	
	_buttonContent.setCharacterSize(20);
	//centerTextInBackground();
}

void Button::Display(sf::RenderWindow *window)
{
	window->draw(_buttonBackground);
	window->draw(_buttonContent);
}

void Button::centerTextInBackground()
{
	sf::Vector2f textPosition;
	sf::FloatRect textRect;

	textRect = _buttonContent.getLocalBounds();
	textPosition.x = textRect.left + _buttonBackground.getSize().x / 2 - textRect.width / 2;
	textPosition.y = textRect.top + _buttonBackground.getSize().y / 2 - textRect.height / 2;
	_buttonContent.setPosition(textPosition);
}


