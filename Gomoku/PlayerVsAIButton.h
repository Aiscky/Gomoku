#pragma once

#include "Button.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "EventManager.h"
#include "PlayerVsAIEventManager.h"

class PlayerVsAIButton : public Button
{

private:
	EventManager **_eventManagerAddr;
	sf::RenderWindow *_window;
	static const unsigned int _buttonOriginX = 430;
	static const unsigned int _buttonOriginY = 100;

public:
	PlayerVsAIButton(EventManager **eventManagerAddr, sf::RenderWindow *window);
	virtual ~PlayerVsAIButton() {};
	virtual bool ButtonPressed();
};

