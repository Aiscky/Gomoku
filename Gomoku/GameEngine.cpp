#include "GameEngine.h"

void GameEngine::InitWindow()
{
	if ((this->_window = new sf::RenderWindow(sf::VideoMode(_windowInfo._windowWidth, _windowInfo._windowHeight), _windowInfo._windowTitle, sf::Style::Close)) == NULL)
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

GameEngine::GameEngine(EventManager *eventManager)
{
	_eventManager = eventManager;
	_windowInfo._windowHeight = WINDOW_HEIGHT;
	_windowInfo._windowWidth = WINDOW_WIDTH;
	_windowInfo._windowTitle = WINDOW_TITLE;
	_windowInfo._windowStyle = WINDOW_STYLE;

	InitWindow();
}


GameEngine::~GameEngine()
{
	delete this->_window;
}
