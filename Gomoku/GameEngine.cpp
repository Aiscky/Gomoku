#include "GameEngine.h"
#include <Windows.h>

void GameEngine::InitWindow()
{
	if ((this->_window = new sf::RenderWindow(sf::VideoMode(_windowInfo._windowWidth, _windowInfo._windowHeight), _windowInfo._windowTitle, WINDOW_STYLE)) == NULL)
	{
		exit(EXIT_FAILURE);
	}
}

void GameEngine::Run()
{
	while (_window->isOpen())
	{
		_eventManager->HandleEvent();
	}
}

GameEngine::GameEngine()
{
	_windowInfo._windowHeight = WINDOW_HEIGHT;
	_windowInfo._windowWidth = WINDOW_WIDTH;
	_windowInfo._windowTitle = WINDOW_TITLE;
	_windowInfo._windowStyle = WINDOW_STYLE;

	InitWindow();

	_eventManager = new MenuEventManager(_window, &(this->_eventManager));
}

GameEngine::~GameEngine()
{
	delete this->_window;
}
