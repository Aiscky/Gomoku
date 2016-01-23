#include "Button.h"
#include <tuple>

Button::Button(	unsigned int buttonOriginX, unsigned int buttonOriginY, std::string buttonContent)
{
	if (!_buttonFont.loadFromFile("Fonts/BLACKJAR.TTF"))
	{
		char *error = (char *)malloc(265);

		strerror_s(error, 256, errno);
		OutputDebugString(error);
		OutputDebugString("\n");
		OutputDebugString("Failed to load font\n");
		exit(EXIT_FAILURE);
	}

	_buttonContent.setFont(_buttonFont);
	_buttonContent.setString(buttonContent);
	_buttonContent.setColor(sf::Color::Black);	
	_buttonContent.setCharacterSize(80);

	sf::Vector2f textPosition;
	sf::FloatRect textRect;

	textRect = _buttonContent.getLocalBounds();
	textPosition.x = buttonOriginX;
	textPosition.y = buttonOriginY;
	_buttonContent.setPosition(textPosition);
}

void Button::Display(sf::RenderWindow *window)
{
	window->draw(_buttonContent);
}