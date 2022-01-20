#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

typedef struct Point {
public:
	int x, y;
	Point(int x1, int y1) :x(x1), y(y1) {};
}Point;

class Board {
	char** Frame;
	int row, col;
public:
	Board() = default;

	Board(int row1, int col1){
		row = row1; col = col1;
		Frame = new char* [row];
		for (int i = 0; i < row; i++)
			Frame[i] = new char[col];
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				if (i == 0)
					Frame[i][j] = '-';
				else if (i == row - 1)
					Frame[i][j] = '-';
				else if (j == 0 || j == col - 1)
					Frame[i][j] = '|';
				else
					Frame[i][j] = '@';
			}
	};

	Board(Board& B) {
		col = B.col; row = B.row;
		Frame = new char* [row];
		for (int i = 0; i < row; i++)
			Frame[i] = new char[col];
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				Frame[i][j] = B.Frame[i][j];
	}


	~Board();

	int flag_num = 10;
	void draw_char(Point P, char ch, int &mine_num);
	void display();
	void check();
	bool check_mine(Board  b,Point P);
	bool check_flag(Board b);
	void set_board(Board b, Point p);
	void set_board_num(Board b);
	void set_flag();
	void remove_flag();
	bool check_space(int x, int y);
	void draw_mines();
	void Beggining_display();
	void Victory_screen();
	void Lose_screen();
};


#endif // !_HEADER_H
