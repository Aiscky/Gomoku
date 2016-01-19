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
		if (event.type == sf::Event::MouseButtonPressed)
		{
			switch (event.mouseButton.button)
			{
			case sf::Mouse::Left:
				((PlayerVsAIModel *)this->_model)->Clicked(event.mouseButton.x, event.mouseButton.y);
				break;
			}
		}
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				((PlayerVsAIModel *)this->_model)->BackToMenu();
				return true;
			}
		}
		_model->Display(_window);
	}
	return true;
}
