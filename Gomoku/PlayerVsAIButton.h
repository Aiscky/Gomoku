#pragma once

#include "Button.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "EventManager.h"

class PlayerVsAIButton : public Button
{

private:
	EventManager **_eventManagerAddr;
	sf::RenderWindow *_window;
	static const unsigned int _buttonWidth = 120;
	static const unsigned int _buttonHeight = 30;
	static const unsigned int _buttonOriginX = 590;
	static const unsigned int _buttonOriginY = 200;

public:
	PlayerVsAIButton(EventManager **eventManagerAddr, sf::RenderWindow *window);
	virtual ~PlayerVsAIButton() {};
	virtual bool ButtonPressed();
};
