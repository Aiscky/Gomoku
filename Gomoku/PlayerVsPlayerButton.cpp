#include "PlayerVsPlayerButton.h"

PlayerVsPlayerButton::PlayerVsPlayerButton(EventManager **eventManagerAddr, sf::RenderWindow *window) 
	: Button(_buttonOriginX, _buttonOriginY, "Player Vs Player")
{
	_eventManagerAddr = eventManagerAddr;
	_window = window;
}

bool PlayerVsPlayerButton::ButtonPressed()
{
	delete (*_eventManagerAddr);
	(*_eventManagerAddr) = new PVPEventManager(_eventManagerAddr, _window);
	return true;
}
