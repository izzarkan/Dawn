#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Settings {
	int difficulty;
	bool fullscreen;
};

void loadSettings(Settings& s) {
	ifstream file("config.ini");

	if (!file.is_open()) {
		// Default settings
		s.fullscreen = false;
		s.difficulty = 0;
		return;
	}

	string line;
	while (getline(file, line)) {
		if (line.rfind("fullscreen=", 0) == 0)
			s.fullscreen = stoi(line.substr(11));
		else if (line.rfind("difficulty=", 0) == 0)
			s.difficulty = stoi(line.substr(11));
	}

	file.close();
}

void saveSettings(const Settings& s) {
	ofstream file("config.ini");
	file << "fullscreen=" << (s.fullscreen ? 1 : 0) << endl;
	file << "difficulty=" << s.difficulty << endl;
	file.close();
}

void openSettings() {
	system("cls");
	cout << "Opening settings..." << endl;
	cout << "Under construction" << endl;
}

void settingsMenu(Settings& s) {
	int choice;

	cout << "====== Settings ======" << endl;
	cout << "1. Toggle Fullscreen (Current: " << (s.fullscreen ? "On" : "Off") << ")" << endl;
	cout << "2. Set Difficulty (Current: " << s.difficulty << ")" << endl;
	cout << "0. Back to main menu\n";
	cout << "====================" << endl;
	cout << "Choose: ";
	cin >> choice;

	switch (choice) {
		case 1:
			s.fullscreen = !s.fullscreen;
			cout << "Fullscreen toggled.\n";
		break;
		case 2:
			cout << "Difficulty (0 = Easy, 1 = Normal, 2 = Hard): ";
			cin >> s.difficulty;
		break;
		default:
			return;
	}

	saveSettings(s);
	cout << "Settings saved!\n";
}