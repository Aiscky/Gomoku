#include "ExitButton.h"

ExitButton::ExitButton(sf::RenderWindow *window)
	: Button(sf::Color::Black, sf::Color::White, sf::Color::White, _buttonWidth, _buttonHeight, _buttonOriginX, _buttonOriginY, "EXIT", false)
{
	_window = window;
}


ExitButton::~ExitButton()
{}

bool ExitButton::ButtonPressed()
{
	_window->close();
	return true;
}

