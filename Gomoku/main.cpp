#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include "MenuEventManager.h"

int _stdcall WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
	)
{
	GameEngine gameEngine;

	gameEngine.Run();
	
	return 0;
}