#pragma once

#include <iostream>
#include <vector>

class Grid
{

private:
	const static unsigned char squareNumber = 19;
	char _playersPawnsLeft[2];
	char _playersPairsCaptured[2];

	typedef struct s_3PFreeLine {
		char start[2];
		char end[2];
	} t_3PFreeline;

	std::vector<t_3PFreeline> _3PFreeLines;

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
		WHITE = 2,
		EDGE = 3
	};

	char _grid[squareNumber][squareNumber];
	void addPawn(char x, char y, PlayerColor color);
	void deletePawn(char x, char y);
	bool isCellEmpty(char x, char y);
	char getCell(char x, char y);
	unsigned char getSideSize();
	char getLeft();
	char getRight();
	char getTop();
	char getBottom();
	PlayerColor getOpponentColor(PlayerColor playerColor);
	char capturedPairs(PlayerColor playerColor);
	
	void affGrid();

};

