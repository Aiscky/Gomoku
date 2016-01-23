#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Button.h"
#include "EventManager.h"

class ExitButton : public Button
{

private:
	EventManager **_eventManagerAddr;
	static const unsigned int _buttonOriginX = 540;
	static const unsigned int _buttonOriginY = 530;

public:
	ExitButton(sf::RenderWindow *window);
	virtual ~ExitButton() {};
	virtual bool ButtonPressed();
};

