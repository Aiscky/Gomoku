#include "PlayerVsIAButton.h"

PlayerVsIAButton::PlayerVsIAButton(EventManager **eventManagerAddr, sf::RenderWindow *window)
	: Button(sf::Color::Cyan, sf::Color::Green, sf::Color::Red, _buttonWidth, _buttonHeight, _buttonOriginX, _buttonOriginY, "1 Player", false)
{
	_eventManagerAddr = eventManagerAddr;
	_window = window;
}


PlayerVsIAButton::~PlayerVsIAButton()
{

}

bool PlayerVsIAButton::ButtonPressed()
{
	delete (*_eventManagerAddr);
	(*_eventManagerAddr); //ADD NEW EVENTMANAGER
	return true;
}
