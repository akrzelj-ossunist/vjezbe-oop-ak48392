#include "Header.hpp"

bool Board::check_flag(Board b)
{
	int check = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if(b.Frame[i][j] == '?' && Frame[i][j] == '*')
				check++;
	if (check == 10) {
		Victory_screen();
		cout << "Congratiulation!! You won..." << endl;
		return 0;
	}
	else
		return 1;
}

void Board::set_flag()
{
	while (flag_num) {
		flag_num--;
		cout << "where do you wanna place a flag?" << endl;
		int x, y;
		cout << "row? "; cin >> x;
		while (x < 1 || x > 11) {
			while (cin.fail()) {
				cin.clear(); cin.ignore(512, '\n');
				cout << "Wrong input!!! You need to input number..." << endl;
				cout << "New input: "; cin >> x;
			}
			if (x > 0 && x < 12)
				break;
			cout << "Wrong input!!! There are only 11 rows..." << endl;
			cout << "New input: "; cin >> x;
		}
		cout << "column? "; cin >> y;
		while (y < 1 || y > 8) {
			while (cin.fail()) {
				cin.clear(); cin.ignore(512, '\n');
				cout << "Wrong input!!! You need to input number..." << endl;
				cout << "New input: "; cin >> y;
			}
			if (y > 0 && y < 9)
				break;
			cout << "Wrong input!!! There are only 9 columns..." << endl;
			cout << "New input: "; cin >> y;
		}
		if (Frame[x][y] == '?')
			flag_num++;
		else
			Frame[x][y] = '?';
		system("CLS");
		display();
		cout << "Do you wanna more flags? " << endl;
		cout << "Press 'y' for yes or 'n' for no..." << endl;
		char choice;
		cin >> choice;
		while (choice != 'y' && choice != 'n') {
			cout << "Wrong input!!!" << endl << "Press 'y' for yes or 'n' for no... ";
			cin >> choice;
		}
		if (choice == 'y') {
			if (flag_num == 0)
				cout << "You are out of flags! Remove some if you placed them wrong..." << endl;
			continue;
		}
		else
			break;
	}
}

void Board::remove_flag()
{
	while (1) {
		cout << "Pick a spot of a flag you wanna remove?" << endl;
		int x, y;
		cout << "row? "; cin >> x;
		while (x < 1 || x > 11) {
			while (cin.fail()) {
				cin.clear(); cin.ignore(512, '\n');
				cout << "Wrong input!!! You need to input number..." << endl;
				cout << "New input: "; cin >> x;
			}
			if (x > 0 && x < 12)
				break;
			cout << "Wrong input!!! There are only 11 rows..." << endl;
			cout << "New input: "; cin >> x;
		}
		cout << "columns? "; cin >> y;
		while (y < 1 || y > 8) {
			while (cin.fail()) {
				cin.clear(); cin.ignore(512, '\n');
				cout << "Wrong input!!! You need to input number..." << endl;
				cout << "New input: "; cin >> y;
			}
			if (y > 0 && y < 9)
				break;
			cout << "Wrong input!!! There are only 9 columns..." << endl;
			cout << "New input: "; cin >> y;
		}
		if (Frame[x][y] != '?') {
			cout << "You picked wrong spot! " << endl;
			cout << "Pick new('y') or continue playing('n')? " << endl;
			char choice;
			cin >> choice;
			while (choice != 'y' && choice != 'n') {
				cout << "Wrong input!!!" << endl << "Press 'y' for yes or 'n' for no... ";
				cin >> choice;
			}
			if (choice == 'y')
				continue;
			else
				break;
		}
		Frame[x][y] = '@';
		system("CLS");
		display();
		cout << "Do you wanna remove more flags? " << endl;
		cout << "Press 'y' for yes or 'n' for no..." << endl;
		char choice;
		cin >> choice;
		if (choice == 'y')
			continue;
		else
			break;
	}
}