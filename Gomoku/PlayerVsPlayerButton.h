#pragma once

#include "Button.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "EventManager.h"

class PlayerVsPlayerButton : public Button
{

private:
	EventManager **_eventManagerAddr;
	sf::RenderWindow *_window;
	static const unsigned int _buttonWidth = 0;
	static const unsigned int _buttonHeight = 0;
	static const unsigned int _buttonOriginX = 0;
	static const unsigned int _buttonOriginY = 0;

public:
	PlayerVsPlayerButton(EventManager **eventManagerAddr, sf::RenderWindow *window);
	virtual ~PlayerVsPlayerButton();
	virtual bool ButtonPressed();
};

