#include <iostream>

#include "game.h"
#include "settings.h"
#include "about.h"
using namespace std;

void inputfield() {
	cout << "====================" << endl;
}

void title() {
	cout << "==========" << endl;
	cout << "   Dawn   " << endl;
	cout << "==========" << endl;
}

void menu() {
	cout << "1. Play" << endl;
	cout << "2. Settings" << endl;
	cout << "3. About" << endl;
	cout << "0. Exit" << endl;
}

int main() {
	//	Variables
	int userAns;
	char running = 'y';

	do {
		system("cls");
		title();
		menu();

		cout << endl;
		inputfield();
		cout << "Please select an action: ";
		cin >> userAns;

		switch (userAns) {
		case 0:
			cout << "Exitting...";
			running = 'n';
			break;
		case 1:
			startGame();
			system("pause");
			break;
		case 2:
			openSettings();
			system("pause");
			break;
		case 3:
			showAbout();
			system("pause");
			break;
		default:
			cout << "Invalid";
			break;
		}

	} while (running == 'Y' || running == 'y');

	return 0;
}