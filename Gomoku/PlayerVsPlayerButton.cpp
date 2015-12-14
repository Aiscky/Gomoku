#include "PlayerVsPlayerButton.h"



PlayerVsPlayerButton::PlayerVsPlayerButton(EventManager **eventManagerAddr, sf::RenderWindow *window) 
	: Button(sf::Color::White, sf::Color::White, sf::Color::White, _buttonWidth, _buttonHeight, _buttonOriginX, _buttonOriginY, "Player Vs Player", true)
{
	_eventManagerAddr = eventManagerAddr;
	_window = window;
}

PlayerVsPlayerButton::~PlayerVsPlayerButton()
{

}

bool PlayerVsPlayerButton::ButtonPressed()
{
	delete (*_eventManagerAddr);
	(*_eventManagerAddr); //ADD NEW EVENTMANAGER
	return true;
}


