#pragma once

#include "EventManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MenuEventManager.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400
#define WINDOW_TITLE "Gomoku"
#define WINDOW_STYLE 4

class GameEngine
{
private:
	EventManager *_eventManager;
	sf::RenderWindow *_window;
	class WindowInfo
	{
	public:
		std::string _windowTitle;
		unsigned int _windowWidth;
		unsigned int _windowHeight;
		unsigned char _windowStyle;
	};
	WindowInfo _windowInfo;

public:
	void InitWindow();
	void Run();
	GameEngine();
	~GameEngine();
};

