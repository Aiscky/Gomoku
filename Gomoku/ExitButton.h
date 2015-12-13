#pragma once

#include "Button.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "EventManager.h"

class ExitButton : public Button
{
	static const unsigned int _buttonWidth = 400;
	static const unsigned int _buttonHeight = 200;
	static const unsigned int _buttonOriginX = 0;
	static const unsigned int _buttonOriginY = 0;

private:
	EventManager **_eventManagerAddr;

public:
	ExitButton(sf::RenderWindow *window);
	virtual ~ExitButton();
	virtual bool ButtonPressed();
};

