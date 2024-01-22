/**
*
* Solution to course project # 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Nelly Ilieva
* @idnumber 1MI0600400
* @compiler VC
*
* Game 2048
*
*/



#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "moveFunctions.h"

using namespace std;

int POINTS = 0;

void printMenu() {
	cout << "-enter 's' to Start new game-" << endl;
	cout << "-enter 'l' to see Leaderboard-" << endl;
	cout << "-enter 'q' to Quit-" << endl;
	cout << endl;
	cout << "-to make move up use 'w'-" << endl;
	cout << "-to make move down use 's'-" << endl;
	cout << "-to make move left use 'a'-" << endl;
	cout << "-to make move right use 'd'-" << endl;
	cout << endl;
	cout << "MENU" << endl;
	cout << "Start game" << endl;
	cout << "Leaderboard" << endl;
	cout << "Quit" << endl;
}

bool checkSize(int SIZE) {
	if (SIZE < 4 || SIZE > 10) {
		return false;
	}
	return true;
}

bool hasFreePosition(int matrix[][SIZE], const size_t SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (matrix[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}

bool validCommand(char command) {
	if (command == 'w' || command == 'a' || command == 's' || command == 'd') {
		return true;
	}

	return false;
}

int returnOnRandomTwoOrFour() {
	srand(static_cast<unsigned int>(time(nullptr)));

	return (rand() % 2 == 0) ? 2 : 4;
}

void printMatrix(int matrix[][SIZE], const size_t SIZE, int points) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << setw(4) << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Score: " << points << endl;
}

unsigned randomGenerator(int matrix[][SIZE], const size_t SIZE) {
	if (!hasFreePosition(matrix, SIZE)) {
		return -1;
	}

	srand(static_cast<unsigned int>(time(nullptr)));

	while (true) {
		size_t randomRow = rand() % SIZE;
		size_t randomCol = rand() % SIZE;

		if (matrix[randomRow][randomCol] == 0) {
			matrix[randomRow][randomCol] = returnOnRandomTwoOrFour();
			break;
		}
	}
	POINTS += returnOnRandomTwoOrFour();
	printMatrix(matrix, SIZE, POINTS);
}

void commandsMovement(char command, int matrix[][SIZE], const size_t SIZE) {
	switch (command) {
	case 'w':
		makeMoveUp(matrix, SIZE);
		break;
	case 'a':
		makeMoveLeft(matrix, SIZE);
		break;
	case 's':
		makeMoveDown(matrix, SIZE);
		break;
	case 'd':
		makeMoveRight(matrix, SIZE);
		break;
	}
}

void playGame(int matrix[][10], const int SIZE, char command, int& points) {

	if (hasFreePosition(matrix, SIZE)) {
		if (!validCommand(command)) {
			printMatrix(matrix, SIZE, points);
		}
		else {
			commandsMovement(command, matrix, SIZE);
			randomGenerator(matrix, SIZE);
		}
	}

}

unsigned safeInfoAboutPlayer(string nickname, const int SIZE, int& points) {
	if (SIZE >= 4 && SIZE <= 10) {
		ofstream file(to_string(SIZE) + "Dimension.txt", ios::app);

		if (!file.is_open()) {
			return false;
		}

		file << nickname << " - " << points << endl;

		file.clear();
		file.close();
	}
}

unsigned showLeaderboard(const int SIZE) {
	string text;

	if (SIZE >= 4 && SIZE <= 10) {

		ifstream file(to_string(SIZE) + "Dimension.txt");

		if (!file.is_open()) {
			return false;
		}

		while (getline(file, text)) {
			cout << text << endl;
		}

		file.clear();
		file.close();
	}
}

int main()
{
	while (true) {
		printMenu();

		char ch;
		cin >> ch;

		string nickname;
		size_t dimension;
		char command;

		int board[SIZE][SIZE] = { 0 };

		if (ch == 's') {
			cout << "Enter your nickname: " << endl;
			cin >> nickname;

			cout << "Enter dimension between 4 and 10: " << endl;
			cin >> dimension;

			if (!checkSize(dimension)) {
				cout << "Invalid dimension!" << endl;
				break;
			}

			randomGenerator(board, dimension);
			while (hasFreePosition(board, dimension)) {
				cin >> command;
				playGame(board, dimension, command, POINTS);
				POINTS += returnOnRandomTwoOrFour();
			}

			safeInfoAboutPlayer(nickname, dimension, POINTS);
			POINTS = 0;
		}
		else if (ch == 'l') {
			cout << "Enter dimension: ";
			cin >> dimension;
			showLeaderboard(dimension);
			break;
		}

		else if (ch == 'q') {
			cout << "END" << endl;
			break;
		}

		else {
			cout << "Enter valid command!" << endl;
		}
	}
}