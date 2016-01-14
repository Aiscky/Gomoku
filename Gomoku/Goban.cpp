#include "Goban.h"

Goban::Goban()
{
	for (int i = 0; i < 19; i++)
		_board.push_back("...................");
}