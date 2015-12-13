#pragma once

#include "Button.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "EventManager.h"

class PlayerVsIAButton : public Button
{
private:
	EventManager **_eventManagerAddr;

public:
	PlayerVsIAButton(
		EventManager **eventManagerAddr,
		sf::RenderWindow *window,
		unsigned int buttonWidth,
		unsigned int buttonHeight,
		unsigned int buttonOriginX,
		unsigned int buttonOriginY);
	virtual ~PlayerVsIAButton();
	virtual bool ButtonPressed();
};

