#include "Header.hpp"

void end_prog() { return; };

void main()
{
	srand(time(NULL));
	int row = 13, col = 10;
	Board b(row, col), g(row,col);
	b.Beggining_display();
	b.draw_mines();
	b.check();
	char choice;
	int result = 1;
	while (result) {
		cout << "Do you wanna place a flag?" << endl;
		cout << "Press 'y' for yes..." << endl;
		cout << "Press 'n' for no..." << endl;
		cin >> choice;
		while (choice != 'y' && choice != 'n') {
			cout << "Wrong input!!!" << endl << "Press 'y' for yes or 'n' for no... ";
			cin >> choice;
		}
		(choice == 'y') ? g.set_flag() : end_prog();
		result = b.check_flag(g);
		if (result == 0) {
			cout << "Do you wanna play again?" << endl;
			cin >> choice;
			while (choice != 'y' && choice != 'n') {
				cout << "Wrong input!!!" << endl << "Press 'y' for yes or 'n' for no... ";
				cin >> choice;
			}
			if (choice == 'y') {
				result = 1;
				Board d(row, col);
				Board g = d;
				Board b = d;
				b.draw_mines();
				b.check();
				system("CLS");
				continue;
			}
			else
				break;
		}
		cout << "Do you wanna remove a flag?" << endl;
		cout << "Press 'y' for yes..." << endl;
		cout << "Press 'n' for no..." << endl;
		cin >> choice;
		while (choice != 'y' && choice != 'n') {
			cout << "Wrong input!!!" << endl << "Press 'y' for yes or 'n' for no... ";
			cin >> choice;
		}
		(choice == 'y') ? g.remove_flag() : end_prog();
		int G_row, G_col;
		cout << "Input row and column u wanna pick: " << endl;
		cout << "Row: "; cin >> G_row;
		while (G_row < 1 || G_row > 11) {
			while (cin.fail()) {
				cin.clear(); cin.ignore(512, '\n');
				cout << "Wrong input!!! You need to input number..." << endl;
				cout << "New input: "; cin >> G_row;
			}
			if (G_row > 0 && G_row < 12)
				break;
			cout << "Wrong input!!! There are only 11 rows..." << endl;
			cout << "New input: "; cin >> G_row;
		}
		cout << endl;
		cout << "Column: "; cin >> G_col;
		while (G_col < 1 || G_col > 8) {
			while (cin.fail()) {
				cin.clear(); cin.ignore(512, '\n');
				cout << "Wrong input!!! You need to input number..." << endl;
				cout << "New input: "; cin >> G_col;
			}
			if (G_col > 0 && G_col < 9)
				break;
			cout << "Wrong input!!! There are only 8 columns..." << endl;
			cout << "New input: "; cin >> G_col;
		}
		Point P(G_row, G_col);
		result = b.check_mine(g, P);
		if (result == 0) {
			b.Lose_screen();
			cout << "Unfortunately you lost! Better luck next time..." << endl;
			cout << "Do you wanna play again?" << endl;
			cin >> choice;
			while (choice != 'y' && choice != 'n') {
				cout << "Wrong input!!!" << endl << "Press 'y' for yes or 'n' for no... ";
				cin >> choice;
			}
			if (choice == 'y') {
				result = 1;
				Board d(row, col);
				Board g = d;
				Board b = d;
				b.draw_mines();
				b.check();
				system("CLS");
				continue;
			}
			else
				break;
		}
		g.set_board(b, P);
		g.set_board_num(b);
		g.display();	
	}
}