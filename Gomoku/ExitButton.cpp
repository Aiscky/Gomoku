#include "ExitButton.h"

ExitButton::ExitButton(sf::RenderWindow *window)
	: Button(_buttonOriginX, _buttonOriginY, "EXIT")
{
	_window = window;
}

bool ExitButton::ButtonPressed()
{
	_window->close();
	return true;
}