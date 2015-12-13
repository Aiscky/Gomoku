#pragma once

#include <SFML/Graphics.hpp>

class EventManager
{
protected:
	sf::RenderWindow *_window;

public:
	virtual ~EventManager() = 0;
	virtual bool HandleEvent() = 0;
};