#include "PlayerVsIAButton.h"

PlayerVsIAButton::PlayerVsIAButton(
	EventManager **eventManagerAddr,
	sf::RenderWindow *window,
	unsigned int buttonWidth,
	unsigned int buttonHeight,
	unsigned int buttonOriginX,
	unsigned int buttonOriginY)
	: Button(sf::Color::White, sf::Color::White, sf::Color::White, buttonWidth, buttonHeight, buttonOriginX, buttonOriginY, "Player Vs IA", false)
{
	_eventManagerAddr = eventManagerAddr;
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
