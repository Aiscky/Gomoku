#include "PlayerVsAIEventManager.h"

PlayerVsAIEventManager::PlayerVsAIEventManager(sf::RenderWindow *window, EventManager **gameEngineAddr)
{
	_window = window;
	_model = new PlayerVsAIModel(window, gameEngineAddr);
	_model->Display(window);
}


bool PlayerVsAIEventManager::HandleEvent()
{
	return true;
}
