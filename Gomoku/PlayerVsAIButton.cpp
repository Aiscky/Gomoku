#include "PlayerVsAIButton.h"

PlayerVsAIButton::PlayerVsAIButton(EventManager **eventManagerAddr, sf::RenderWindow *window)
	: Button(_buttonOriginX, _buttonOriginY, "Player Vs CPU")
{
	_eventManagerAddr = eventManagerAddr;
	_window = window;
}

bool PlayerVsAIButton::ButtonPressed()
{
	delete (*_eventManagerAddr);
	(*_eventManagerAddr) = new PlayerVsAIEventManager(_window, _eventManagerAddr);
	return true;
}
