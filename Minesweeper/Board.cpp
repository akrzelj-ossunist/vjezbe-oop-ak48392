#include "Header.hpp"

Board::~Board() {
	for (int i = 0; i < row; i++)
		delete[] Frame[i];
	delete[] Frame;
}

void Board::check()
{
	int num = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (j == 1 && i == 1 && Frame[i][j] == '@')
			{
				if (Frame[i][j + 1] == '*')
					num += 1;
				if (Frame[i + 1][j + 1] == '*')
					num += 1;
				if (Frame[i + 1][j] == '*')
					num += 1;
				if (num > 0) {
					Frame[i][j] = num + '0';
					num = 0;
				}
			}
			if (j == 1 && i != 1 && Frame[i][j] == '@')
			{
				if (Frame[i - 1][j] == '*')
					num += 1;
				if (Frame[i + 1][j] == '*')
					num += 1;
				if (Frame[i + 1][j + 1] == '*')
					num += 1;
				if (Frame[i][j + 1] == '*')
					num += 1;
				if (Frame[i - 1][j + 1] == '*')
					num += 1;
				if (num > 0) {
					Frame[i][j] = num + '0';
					num = 0;
				}
			}
			if (j != 1 && i == 1 && Frame[i][j] == '@')
			{
				if (Frame[i][j - 1] == '*')
					num += 1;
				if (Frame[i][j + 1] == '*')
					num += 1;
				if (Frame[i + 1][j + 1] == '*')
					num += 1;
				if (Frame[i + 1][j] == '*')
					num += 1;
				if (Frame[i + 1][j - 1] == '*')
					num += 1;
				if (num > 0) {
					Frame[i][j] = num + '0';
					num = 0;
				}
			}
			if (j == col - 2 && i == row - 2 && Frame[i][j] == '@')
			{
				if (Frame[i][j - 1] == '*')
					num += 1;
				if (Frame[i - 1][j - 1] == '*')
					num += 1;
				if (Frame[i - 1][j] == '*')
					num += 1;
				if (num > 0) {
					Frame[i][j] = num + '0';
					num = 0;
				}
			}
			if (j == col - 2 && i != row - 2 && Frame[i][j] == '@')
			{
				if (Frame[i + 1][j] == '*')
					num += 1;
				if (Frame[i - 1][j] == '*')
					num += 1;
				if (Frame[i - 1][j - 1] == '*')
					num += 1;
				if (Frame[i][j - 1] == '*')
					num += 1;
				if (Frame[i + 1][j - 1] == '*')
					num += 1;
				if (num > 0) {
					Frame[i][j] = num + '0';
					num = 0;
				}
			}
			if (j != col - 2 && i == row - 2 && Frame[i][j] == '@')
			{
				if (Frame[i][j + 1] == '*')
					num += 1;
				if (Frame[i][j - 1] == '*')
					num += 1;
				if (Frame[i - 1][j - 1] == '*')
					num += 1;
				if (Frame[i - 1][j] == '*')
					num += 1;
				if (Frame[i - 1][j + 1] == '*')
					num += 1;
				if (num > 0) {
					Frame[i][j] = num + '0';
					num = 0;
				}
			}
			if (j != col - 2 && i != row - 2 && j != 1 && i != 1 && Frame[i][j] == '@')
			{
				if (Frame[i - 1][j - 1] == '*')
					num += 1;
				if (Frame[i][j - 1] == '*')
					num += 1;
				if (Frame[i + 1][j - 1] == '*')
					num += 1;
				if (Frame[i + 1][j] == '*')
					num += 1;
				if (Frame[i + 1][j + 1] == '*')
					num += 1;
				if (Frame[i][j + 1] == '*')
					num += 1;
				if (Frame[i - 1][j + 1] == '*')
					num += 1;
				if (Frame[i - 1][j] == '*')
					num += 1;
				if (num > 0) {
					Frame[i][j] = num + '0';
					num = 0;
				}
			}

		}

	}
}

void Board::display()
{
	cout << endl << "\t 12345678 " << endl;
	for (int i = 0; i < row; i++)
	{ 
		if (i != 0 && i != row - 1)
			cout << i << "\t";
		else
			cout << " \t";
		for (int j = 0; j < col; j++)
			cout << Frame[i][j];
		cout << endl;
	}
}

void Board::Beggining_display()
{
	cout << "----------------------------------------" << endl;
	cout << "|  *****      *     *       * *******  |" << endl;
	cout << "| *          * *    * *   * * *        |" << endl;
	cout << "| *   **    *****   *   *   * *****    |" << endl;
	cout << "| *     *  *     *  *       * *        |" << endl;
	cout << "|  *****  *       * *       * *******  |" << endl;
	cout << "| //////////////////////////////////// |" << endl;
	cout << "|                                      |" << endl;
	cout << "|                                      |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "RULES! " << endl;
	cout << "Board consists of 11 rows and 8 columns!" << endl;
	cout << "Each turn u can set or remove flag at any spot on board that you think there might be a mine!" << endl;
	cout << "Every turn open one tile on the board!" << endl;
	cout << "Numbers on the boards represent how many mines are around that number!" << endl;
	cout << "If you hit the mine you instantly lose!" << endl;
	cout << "To win you have to place flags on each mine!" << endl;
	cout << "\n\n\n\n " << endl;

}

void Board::Victory_screen()
{
	cout << "-----------------------------------------------------" << endl;
	cout << "| *       * *   ***** *******  *****  *****  *   *  |" << endl;
	cout << "|  *     *  *  *         *    *     * *    *  * *   |" << endl;
	cout << "|   *   *   *  *         *    *     * * * *    *    |" << endl;
	cout << "|    * *    *  *         *    *     * *  *     *    |" << endl;
	cout << "|     *     *   *****    *     *****  *   *    *    |" << endl;
	cout << "| ///////////////////////////////////////////////// |" << endl;
	cout << "|                                                   |" << endl;
	cout << "|                                                   |" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "\n\n" << endl;
}

void Board::Lose_screen()
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "|  *****      *     *       * *******     *****  *       * ****** ****  |" << endl;
	cout << "| *          * *    * *   * * *          *     *  *     *  *      *   * |" << endl;
	cout << "| *   **    *****   *   *   * *****      *     *   *   *   *****  ****  |" << endl;
	cout << "| *     *  *     *  *       * *          *     *    * *    *      * *   |" << endl;
	cout << "|  *****  *       * *       * *******     *****      *     ****** *  *  |" << endl;
	cout << "| ///////////////////////////////////////////////////////////////////// |" << endl;
	cout << "|                                                                       |" << endl;
	cout << "|                                                                       |" << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "\n\n" << endl;
}