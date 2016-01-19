#include "Arbiter.h"

Arbiter::Arbiter()
{
}

Arbiter::~Arbiter()
{
}

// Checking if selection square is playable

bool Arbiter::CheckPlayable(Grid::PlayerColor currentPlayer, Grid *grid, char x, char y)
{
	// Check current line on horizontal

	char count = 1;

	std::cout << (int)grid->getCell(x, y) << " " << (int)Grid::NONE << std::endl;
	std::cout << "x : " << (int)x << " y : " << (int)y << std::endl;

	if (grid->getCell(x, y) != Grid::NONE)
	{
		return false;
	}

	if (!CheckSideFreeLine(currentPlayer, grid, x + 1, y, count, 1, 0)/* && !CheckSideFreeLine(currentPlayer, grid, x, y, count, -1, 0)*/ && count >= 3)
	{
		//CHECK OTHER LINES
		return false;
	}
	else
	{
		std::cout << "COUNT : " << (int)count << std::endl;
		return true;
	}
}

//CHECKING FOR 3 OR MORE FREE LINE ON HORIZONTAL

bool Arbiter::CheckSideFreeLine(Grid::PlayerColor currentPlayer, Grid *grid, char x, char y, char &count, char xStep, char yStep)
{
	bool blocked = false;
	bool lastEmpty = false;

	while (!blocked)
	{
		if (x < 0 || x > grid->getSideSize() || y < 0 || y > grid->getSideSize())
		{
			if (lastEmpty == false)
			{
				blocked = true;
			}
			else
			{
				break;
			}
			std::cout << "GETTING BLOCKED" << std::endl;
		}
		else if (grid->getCell(x, y) == currentPlayer)
		{
			lastEmpty = false;
			count++;
			/*std::cout << "ADDING TO COUNT" << std::endl;*/
		}
		else if (grid->getCell(x, y) != Grid::NONE)
		{
			if (lastEmpty == false)
			{
				blocked = true;
			}
			else
			{
				break;
			}
		}
		else
		{
			/*std::cout << "EMPTY SPACE" << std::endl;*/
			lastEmpty = true;
		}

		x = x + xStep;
		y = y + yStep;
		/*std::cout << "STEP" << std::endl;*/
	}
	
	std::cout << "BLOCKED : " << blocked << std::endl;
	return (blocked);
}

//bool Arbiter::CheckFreeLineHorizontal(Grid::PlayerColor currentPlayer, Grid *grid, char x, char y)
//{
//	unsigned char n = x - 1;
//	unsigned char count = 1;
//	bool blocked = false;
//	bool lastEmpty = false;
//
//	/* LOOP LEFT */
//
//	while (!blocked)
//	{
//		if (n < 0)
//		{
//			if (lastEmpty == false)
//			{
//				blocked == true;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else if (grid->getCell(n, y) == currentPlayer)
//		{
//			count++;
//		}
//		else if (grid->getCell(n, y) != Grid::NONE)
//		{
//			if (lastEmpty == false)
//			{
//				blocked = true;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else
//		{
//			lastEmpty == true;
//		}
//
//		n--;
//	}
//
//	if (blocked == false)
//	{
//		return (false);
//	}
//
//	/* LOOP RIGHT */
//
//	n = x + 1;
//	blocked = false;
//
//	while (!blocked)
//	{
//		if (n > grid->getSideSize())
//		{
//			if (lastEmpty == false)
//			{
//				blocked == true;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else if (grid->getCell(n, y) == currentPlayer)
//		{
//			count++;
//		}
//		else if (grid->getCell(n, y) != Grid::NONE)
//		{
//			if (lastEmpty == false)
//			{
//				blocked = true;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else
//		{
//			lastEmpty == true;
//		}
//
//		n++;
//	}
//
//	if (blocked == false && count >= DoubleFreeLineNumber)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Arbiter::CheckFreeLineVertical(Grid::PlayerColor currentPlayer, Grid *grid, char x, char y)
//{
//	unsigned char n = y - 1;
//	unsigned char count = 1;
//	bool blocked = false;
//	bool lastEmpty = false;
//
//	/* LOOP UP */
//
//	while (!blocked)
//	{
//		if (n < 0)
//		{
//			if (lastEmpty == false)
//			{
//				blocked == true;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else if (grid->getCell(x, n) == currentPlayer)
//		{
//			count++;
//		}
//		else if (grid->getCell(x, n) != Grid::NONE)
//		{
//			if (lastEmpty == false)
//			{
//				blocked = true;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else
//		{
//			lastEmpty == true;
//		}
//
//		n++;
//	}
//
//	if (blocked == false)
//	{
//		return (false);
//	}
//
//	/* LOOP DOWN */
//
//	n = y + 1;
//	blocked = false;
//
//	while (!blocked)
//	{
//		if (y > grid->getSideSize())
//		{
//			if (lastEmpty == false)
//			{
//				blocked == true;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else if (grid->getCell(x, n) == currentPlayer)
//		{
//			count++;
//		}
//		else if (grid->getCell(x, n) != Grid::NONE)
//		{
//			if (lastEmpty == false)
//			{
//				blocked = true;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else
//		{
//			lastEmpty == true;
//		}
//
//		x++;
//	}
//}