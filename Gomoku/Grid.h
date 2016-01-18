#ifndef GRID_H
# define GRID_H

#include "GameEngine.h"

class Grid
{
public:
	Grid();
	~Grid() {};
	
	enum PlayerColor
	{
		BLACK,
		WHITE
	};

	void addPawn(char x, char y, PlayerColor color);
	int getCell(char x, char y);
	unsigned int getSideSize();
	void affGrid();

private:

	const static unsigned int squareNumber = 19;
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
};

#endif
