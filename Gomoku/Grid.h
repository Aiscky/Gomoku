#pragma once

#include <iostream>

class Grid
{

private:
	const static unsigned char squareNumber = 19;
	char _grid[squareNumber][squareNumber];
	char _playersPawnsLeft[2];
	char _playersPawnsCaptured[2];

	typedef struct s_searchSpace {
		char top;
		char bottom;
		char left;
		char right;
	} t_searchspace;

	t_searchspace _searchSpace;

public:
	Grid();
	~Grid() {};
	
	enum PlayerColor
	{
		NONE = 0,
		BLACK = 1,
		WHITE = 2
	};

	void addPawn(char x, char y, PlayerColor color);
	void deletePawn(char x, char y);
	char getCell(char x, char y);
	unsigned char getSideSize();
	char getLeft();
	char getRight();
	char getTop();
	char getBottom();
	void affGrid();

};

