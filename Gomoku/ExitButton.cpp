#include "ExitButton.h"

ExitButton::ExitButton(sf::RenderWindow *window)
	: Button(sf::Color::Cyan, sf::Color::Green, sf::Color::Red, _buttonWidth, _buttonHeight, _buttonOriginX, _buttonOriginY, "EXIT", false)
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

