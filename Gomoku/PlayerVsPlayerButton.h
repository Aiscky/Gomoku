#pragma once

#include "Button.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "EventManager.h"

class PlayerVsPlayerButton : public Button
{

private:
	EventManager **_eventManagerAddr;
	static unsigned int _buttonWidth;
	static unsigned int _buttonHeight;
	static unsigned int _buttonOriginX;
	static unsigned int _buttonOriginY;

public:
	PlayerVsPlayerButton(EventManager **eventManagerAddr);
	virtual ~PlayerVsPlayerButton();
	virtual bool ButtonPressed();
};

