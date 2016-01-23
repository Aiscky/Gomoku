#include "MenuModel.h"

void MenuModel::Init()
{
	_buttonList.push_back(new PlayerVsAIButton(_eventManagerAddr, _window));
	_buttonList.push_back(new PlayerVsPlayerButton(_eventManagerAddr, _window));
	_buttonList.push_back(new ExitButton(_window));
}

MenuModel::MenuModel(sf::RenderWindow *window, EventManager **eventManager)
{
	this->_eventManagerAddr = eventManager;
	this->_window = window;
	this->_index = 0;
	
	
	_menuBackgroundTexture.loadFromFile("Images/wood_background.bmp");
	_menuBackground.setTexture(_menuBackgroundTexture);
	_menuBackground.setPosition(0, 0);

	// SETTING CURSOR

	_cursorTexture.loadFromFile("Images/Cursor.png");
	_cursor.setTexture(_cursorTexture);
	_cursorPosition[0][0] = 300;
	_cursorPosition[0][1] = 100;
	_cursorPosition[1][0] = 300;
	_cursorPosition[1][1] = 320;
	_cursorPosition[2][0] = 300;
	_cursorPosition[2][1] = 540;
	_cursor.setPosition(_cursorPosition[0][0], _cursorPosition[0][1]);

	this->Init();
}

void MenuModel::Display(sf::RenderWindow *window)
{
	_window->clear();
	window->draw(_menuBackground);
	window->draw(_cursor);
	OutputDebugString("Display function\n");
	for (size_t i = 0; i != _buttonList.size(); i++)
	{
		OutputDebugString("Iteration display loop\n");
		_buttonList[i]->Display(window);
	}
	_window->display();
	return;
}

void MenuModel::GoPrevious()
{
	if (_index == 0)
		_index = _buttonList.size() - 1;
	else
		_index -= 1;
	moveCursor(_index);
}

void MenuModel::GoNext()
{
	if (_index == _buttonList.size() - 1)
		_index = 0;
	else
		_index += 1;
	moveCursor(_index);
}

void MenuModel::Execute()
{
	this->_buttonList[_index]->ButtonPressed();
}

void MenuModel::Execute(char index)
{
	this->_buttonList[index]->ButtonPressed();
}

void MenuModel::moveCursor(char index)
{
	_index = index;
	_cursor.setPosition(_cursorPosition[index][0], _cursorPosition[index][1]);
	Display(_window);
}