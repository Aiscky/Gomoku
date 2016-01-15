#pragma once
#include "EventManager.h"
#include "PVPModel.h"

class PVPEventManager :
	public EventManager
{
private:
	EventManager **_eventManagerAddr;
	sf::RenderWindow *window;

public:
	PVPEventManager(EventManager **, sf::RenderWindow *);
	virtual ~PVPEventManager();
	bool HandleEvent();
};

