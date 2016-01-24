#pragma once

#include <iostream>
#include <vector>

class Grid
{

private:
	const static unsigned char squareNumber = 19;
	char _playersPawnsLeft[2];
	char _playersPawnsCaptured[2];

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

	static const int StartingPawnsLeft = 60;
	static const int StartingPawnsCaptured = 0;


public:
	Grid();
	~Grid() {};
	
	enum PlayerColor
	{
		NONE = 0,
		BLACK = 1,
		WHITE = 2,
		EDGE = 3,
		CAPTURED = 4,
		BLACKCAPTURED = 5,
		WHITECAPTURED = 6
	};

	char _grid[squareNumber][squareNumber];
	void addPawn(char x, char y, PlayerColor color);
	void deletePawn(char x, char y);
	bool isCellEmpty(char x, char y);
	char getCell(char x, char y);
	char getNextCell(char x, char y, char directionX, char directionY);
	unsigned char getSideSize();
	char getLeft();
	char getRight();
	char getTop();
	char getBottom();
	PlayerColor getOpponentColor(PlayerColor color);
	void checkCapture(char x, char y, PlayerColor color);
	void capturePawns(char x1, char y1, char x2, char y2, PlayerColor color);
	void cancelCapture(PlayerColor color);
	void cleanCapture();
	
	char *getPlayersPawnsLeft();
	char *getPlayersPawnsCaptured();
	void RemovePawnFromPlayerPawnsLeft(char playerNumber);
};

