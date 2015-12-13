#pragma once

#include "EventManager.h"
#include <SFML/Graphics.hpp>

class MenuEventManager : public EventManager
{
public:
	MenuEventManager(sf::RenderWindow *window);
	virtual ~MenuEventManager();
	virtual bool HandleEvent();
};

