#pragma once

#include "EventManager.h"
#include "MenuModel.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>

class MenuEventManager : public EventManager
{
public:
	MenuEventManager(sf::RenderWindow *window, EventManager **EventManagerAddr);
	virtual ~MenuEventManager();
	virtual bool HandleEvent();
};

