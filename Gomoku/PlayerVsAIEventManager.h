#pragma once

#include "EventManager.h"
#include "PlayervsAIModel.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>

class PlayerVsAIEventManager : public EventManager
{

public:
	PlayerVsAIEventManager(sf::RenderWindow *window, EventManager **EventManagerAddr);
	virtual ~PlayerVsAIEventManager() {};
	virtual bool HandleEvent();
};

