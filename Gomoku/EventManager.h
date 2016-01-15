#pragma once

#include <SFML/Graphics.hpp>
#include "Model.h"
#include <iostream>

class EventManager
{

protected:
	sf::RenderWindow *_window;
	Model *_model;

public:
	virtual ~EventManager() {};
	virtual bool HandleEvent() = 0;
};