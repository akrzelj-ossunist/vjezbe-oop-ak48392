#include "Header.hpp"

void Board::set_board(Board b, Point p)
{
	system("CLS");
	int min, max;
	int j = p.y, i = p.x;
	if (b.Frame[p.x][p.y] == '@')
	{
		while (b.Frame[i][j] == '@') {
			Frame[i][j] = ' ';
			j++;
		}
		max = j - 1;
		j = p.y;
		while (b.Frame[i][j] == '@') {
			Frame[i][j] = ' ';
			j--;
		}
		min = j + 1;
		int n_max = max, n_min = min;
		//////////////////////////////////////////////////////////////////////////////////
		i++;
		while (b.Frame[i][j] != '-') {
			for (j = min; j < b.col; j++) {
				if (Frame[i - 1][j] != ' ' && Frame[i][j - 1] != ' ' && j > max)
					break;
				if ((Frame[i - 1][j] == ' ' || Frame[i][j - 1] == ' ' || j <= max) && b.Frame[i][j] == '@') {
					Frame[i][j] = ' ';
					n_max = j;
				}
			}
			max = n_max;
			for (j = max; j > 0; j--) {
				if (Frame[i][j + 1] != ' ' && Frame[i - 1][j] != ' ')
					break;
				if ((Frame[i][j + 1] == ' ' || Frame[i - 1][j] == ' ' || j >= min) && b.Frame[i][j] == '@') {
					Frame[i][j] = ' ';
					n_min = j;
				}
			}
			min = n_min;
			if (Frame[i][min] != ' ' && Frame[i][max] != ' ')
				break;
			i++;
		}
		//////////////////////////////////////////////////////////////////////////////////
		i--;
		while (b.Frame[i][j] != '-') {
			for (j = min; j < b.col; j++) {
				if (Frame[i + 1][j] != ' ' && Frame[i][j - 1] != ' ' && j > max)
					break;
				if ((Frame[i + 1][j] == ' ' || Frame[i][j - 1] == ' ' || j <= max) && b.Frame[i][j] == '@') {
					Frame[i][j] = ' ';
					n_max = j;
				}
			}
			max = n_max;
			for (j = max; j > 0; j--) {
				if (Frame[i][j + 1] != ' ' && Frame[i + 1][j] != ' ')
					break;
				if ((Frame[i][j + 1] == ' ' || Frame[i + 1][j] == ' ' || j >= min) && b.Frame[i][j] == '@') {
					Frame[i][j] = ' ';
					n_min = j;
				}
			}
			min = n_min;
			if (Frame[i][min] != ' ' && Frame[i][max] != ' ')
				break;
			i--;
		}
		//////////////////////////////////////////////////////////////////////////////////
		i++;
		while (b.Frame[i][j] != '-') {
			for (j = min; j < b.col; j++) {
				if (Frame[i - 1][j] != ' ' && Frame[i][j - 1] != ' ' && j > max)
					break;
				if ((Frame[i - 1][j] == ' ' || Frame[i][j - 1] == ' ' || j <= max) && b.Frame[i][j] == '@') {
					Frame[i][j] = ' ';
					n_max = j;
				}
			}
			max = n_max;
			for (j = max; j > 0; j--) {
				if (Frame[i][j + 1] != ' ' && Frame[i - 1][j] != ' ')
					break;
				if ((Frame[i][j + 1] == ' ' || Frame[i - 1][j] == ' ' || j >= min) && b.Frame[i][j] == '@') {
					Frame[i][j] = ' ';
					n_min = j;
				}
			}	
			min = n_min;
			if (Frame[i][min] != ' ' && Frame[i][max] != ' ')
				break;
			i++;
		}
	}
	if (isdigit(b.Frame[p.x][p.y]))
		Frame[p.x][p.y] = b.Frame[p.x][p.y];
	if (b.Frame[p.x][p.y] == '*')
		cout << "lose" << endl;
}

void Board::set_board_num(Board b)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if(isdigit(b.Frame[i][j]))
				if (check_space(i, j))
					Frame[i][j] = b.Frame[i][j];
		}
	}
}

bool Board::check_space(int x, int y)
{
	if (Frame[x][y] == '_' || Frame[x][y] == '-')
		return 0;
	if (Frame[x + 1][y] == ' ' || Frame[x - 1][y] == ' ' || Frame[x][y - 1] == ' ' || Frame[x][y + 1] == ' '
		|| Frame[x + 1][y + 1] == ' ' || Frame[x - 1][y - 1] == ' ' || Frame[x - 1][y + 1] == ' ' || Frame[x + 1][y - 1] == ' ')
		return 1;
	else
		return 0;
}