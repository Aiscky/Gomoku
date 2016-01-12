#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Button.h"
#include "EventManager.h"

class ExitButton : public Button
{
	static const unsigned int _buttonWidth = 100;
	static const unsigned int _buttonHeight = 30;
	static const unsigned int _buttonOriginX = 590;
	static const unsigned int _buttonOriginY = 290;

private:
	EventManager **_eventManagerAddr;

public:
	ExitButton(sf::RenderWindow *window);
	virtual ~ExitButton();
	virtual bool ButtonPressed();
};

