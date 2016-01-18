#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

class Arbiter
{
private:
	Arbiter();

public:
	~Arbiter();
	static bool CheckPlayable(bool currentPlayer, char** grid, sf::Vector2u xy);
};

