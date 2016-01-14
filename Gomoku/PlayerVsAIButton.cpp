#include "PlayerVsAIButton.h"

PlayerVsAIButton::PlayerVsAIButton(EventManager **eventManagerAddr, sf::RenderWindow *window)
	: Button(sf::Color::Cyan, sf::Color::Green, sf::Color::Red, _buttonWidth, _buttonHeight, _buttonOriginX, _buttonOriginY, "1 PLayer", false)
{
	_eventManagerAddr = eventManagerAddr;
	_window = window;
}

bool PlayerVsAIButton::ButtonPressed()
{
	delete (*_eventManagerAddr);
	(*_eventManagerAddr); //ADD NEW EVENTMANAGER
	return true;
}
