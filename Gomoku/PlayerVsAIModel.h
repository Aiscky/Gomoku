#pragma once

#include "Model.h"
#include "EventManager.h"

#include <iostream>
#include <vector>
#include <Windows.h>

class PlayerVsAIModel : public Model
{

private:
	EventManager **_eventManagerAddr;
	sf::RenderWindow *_window;

public:
	PlayerVsAIModel(sf::RenderWindow *window, EventManager **eventManager);
	virtual ~PlayerVsAIModel() {};
	virtual void Display(sf::RenderWindow *) {};
	void Init();
	void Clicked(sf::Vector2i);
};