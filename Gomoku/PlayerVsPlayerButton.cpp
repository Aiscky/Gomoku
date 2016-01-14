#include "PlayerVsPlayerButton.h"

PlayerVsPlayerButton::PlayerVsPlayerButton(EventManager **eventManagerAddr, sf::RenderWindow *window) 
	: Button(sf::Color::Cyan, sf::Color::Green, sf::Color::Red, _buttonWidth, _buttonHeight, _buttonOriginX, _buttonOriginY, "2 Players", false)
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
