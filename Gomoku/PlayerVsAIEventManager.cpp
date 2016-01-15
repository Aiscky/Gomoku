#include "PlayerVsAIEventManager.h"

PlayerVsAIEventManager::PlayerVsAIEventManager(sf::RenderWindow *window, EventManager **gameEngineAddr)
{
	_window = window;
	_model = new PlayerVsAIModel(window, gameEngineAddr);
	_model->Display(window);
}


bool PlayerVsAIEventManager::HandleEvent()
{
	sf::Event event;
	while ((*_window).pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			(*_window).close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			((PlayerVsAIModel *)this->_model)->Clicked(sf::Mouse::getPosition(*_window));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{	
			exit(EXIT_SUCCESS);
			break;
		}
		_model->Display(_window);
	}
	return true;
}
