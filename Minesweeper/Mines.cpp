#include "Header.hpp"

void Board::draw_char(Point p, char ch, int& mine_num)
{
	int row = p.x, col = p.y;
	if (Frame[row][col] == ch)
		mine_num++;
	else
		Frame[row][col] = ch;
}

void Board::draw_mines()
{
	int mine_num = 10;
	while (mine_num)
	{
		int x = rand() % (row - 2) + 1;
		int y = rand() % (col - 2) + 1;
		Point p(x, y);
		draw_char(p, '*', mine_num);
		mine_num--;
	}
}

bool Board::check_mine(Board b, Point p)
{
	if (Frame[p.x][p.y] == '*') {
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (Frame[i][j] == '@')
					Frame[i][j] = ' ';
		display();
		return 0;
	}
	else
		return 1;
}