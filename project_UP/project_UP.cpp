#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const size_t SIZE = 10;
int points = 0;

void printMenu() {
	cout << "MENU" << endl;
	cout << "Start game (enter 's' to start new game)" << endl;
	cout << "Leaderboard (enter 'l' to see leaderboard)" << endl;
	cout << "Quit (enter 'q' to quit)" << endl;
}

void interactWithMenu(char ch) {

	//start game
	if (ch == 's') {
		cout << "game" << endl;
	}
	//ask for size and then show top 5
	else if (ch == 'l') {
		cout << "top 5" << endl;
	}
	//end game
	else if (ch == 'q') {
		cout << "end of game" << endl;
	}
	//to enter valid command
	else {
		cout << "enter valid command" << endl;
	}
}

int returnOnRandomTwoOrFour() {
	srand(static_cast<unsigned int>(time(nullptr)));

	return (rand() % 2 == 0) ? 2 : 4;
}

int returnPoints(int points) {
	points += returnOnRandomTwoOrFour();
	return points;
}

bool checkSize(int SIZE) {
	if (SIZE < 4 || SIZE > 10) {
		return false;
	}
	return true;
}

void printMatrix(int matrix[][SIZE], const size_t SIZE, int points) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << setw(4) << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Score: " << returnPoints(points) << endl;
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

bool canMakeMove(int matrix[][SIZE], const size_t SIZE) {
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			if (matrix[i + 1][j] == matrix[i][j] || matrix[i][j + 1] == matrix[i][j]) {
				return true;
			}
		}
	}
	return false;
}

void randomGenerator(int matrix[][SIZE], const size_t SIZE) {

	if (!hasFreePosition(matrix, SIZE)) {
		return;
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
	printMatrix(matrix, SIZE, points);
}

bool validCommand(char command) {
	if (command == 'w' || command == 'a' || command == 's' || command == 'd' || command == 'q') {
		return true;
	}

	return false;
}

void makeMoveRight(int matrix[][SIZE], const size_t SIZE) {
	for (int i = 0; i < SIZE; i++) {
		int nextRow = i;
		int nextCol = SIZE - 1;

		for (int j = SIZE - 2; j >= 0; j--) {
			int curr = matrix[i][j];

			if (curr != 0) {
				if (matrix[i][j + 1] == 0 || matrix[i][j + 1] == curr) {
					if (matrix[nextRow][nextCol] == curr) {
						matrix[nextRow][nextCol] *= 2;
						matrix[i][j] = 0;
					}
					else {
						if (matrix[nextRow][nextCol] == 0) {
							matrix[nextRow][nextCol] = curr;
							matrix[i][j] = 0;
						}
						else {
							matrix[nextRow][--nextCol] = matrix[i][j];
							matrix[i][j] = 0;
						}
					}
				}
				else {
					nextCol--;
				}
			}
		}
	}
}

void makeMoveLeft(int matrix[][SIZE], const size_t SIZE) {
	for (int i = 0; i < SIZE; i++) {
		int nextRow = i;
		int nextCol = 0;

		for (int j = 1; j < SIZE; j++) {
			int curr = matrix[i][j];

			if (curr != 0) {
				if (matrix[i][j - 1] == 0 || matrix[i][j - 1] == curr) {
					if (matrix[nextRow][nextCol] == curr) {
						matrix[nextRow][nextCol] *= 2;
						matrix[i][j] = 0;
					}
					else {
						if (matrix[nextRow][nextCol] == 0) {
							matrix[nextRow][nextCol] = curr;
							matrix[i][j] = 0;
						}
						else {
							matrix[nextRow][++nextCol] = matrix[i][j];
							matrix[i][j] = 0;
						}
					}
				}
				else {
					nextCol++;
				}
			}
		}
	}
}

void makeMoveDown(int matrix[][SIZE], const size_t SIZE) {
	for (int i = 0; i < SIZE; i++) {

		int nextCol = i;
		int nextRow = SIZE - 1;

		for (int j = SIZE - 2; j >= 0; j--) {
			int curr = matrix[j][i];

			if (curr != 0) {
				if (matrix[j + 1][i] == 0 || matrix[j + 1][i] == curr) {
					if (matrix[nextRow][nextCol] == curr) {
						matrix[nextRow][nextCol] *= 2;
						matrix[j][i] = 0;
					}
					else {
						if (matrix[nextRow][nextCol] == 0) {
							matrix[nextRow][nextCol] = curr;
							matrix[j][i] = 0;
						}
						else
						{
							matrix[--nextRow][nextCol] = curr;
							matrix[j][i] = 0;
						}

					}
				}
				else {
					nextRow--;
				}
			}

		}
	}
}

void makeMoveUp(int matrix[][SIZE], const size_t SIZE) {
	for (int i = 0; i < SIZE; i++) {          //col

		int nextCol = i;
		int nextRow = 0;

		for (int j = 1; j < SIZE; j++) {      //row

			int curr = matrix[j][i];

			if (curr != 0) {

				if (matrix[j - 1][i] == 0 || matrix[j - 1][i] == curr) {

					if (matrix[nextRow][nextCol] == curr) {
						matrix[nextRow][nextCol] *= 2;
						matrix[j][i] = 0;
					}

					else {

						if (matrix[nextRow][nextCol] == 0) {
							matrix[nextRow][nextCol] = curr;
							matrix[j][i] = 0;
						}
						else {
							matrix[++nextRow][nextCol] = curr;
							matrix[j][i] = 0;
						}
					}
				}
				else {
					nextRow++;
				}
			}
		}
	}
}


void commandsMovement(char command, int matrix[][SIZE], const size_t SIZE) {
	if (!validCommand(command)) {
		return;
	}

	if (command == 'w') {
		makeMoveUp(matrix, SIZE);
	}
	else if (command == 'a') {
		makeMoveLeft(matrix, SIZE);
	}
	else if (command == 's') {
		makeMoveDown(matrix, SIZE);
	}
	else if (command == 'd') {
		makeMoveRight(matrix, SIZE);
	}
	else {
		return;
	}
}

void playGame(int matrix[][10], const int SIZE, char command) {

	if (checkSize(SIZE) && hasFreePosition(matrix, SIZE)) {
		commandsMovement(command, matrix, SIZE);
		randomGenerator(matrix, SIZE);
	}
}

void safeInfoAboutPlayer(string nickname, const int SIZE, int points) {
	//check if result is in top 5


	if (SIZE >= 4 && SIZE <= 10) {
		ofstream file(to_string(SIZE) + "Dimension.txt", ios::app);
		file << nickname << " - " << returnPoints(points) << endl;
		file.close();
	}
}

void showLeaderboard(const int SIZE) {
	string text;

	if (SIZE >= 4 && SIZE <= 10) {

		ifstream file(to_string(SIZE) + "Dimension.txt");

		while (getline(file, text)) {
			cout << text;
		}

		file.close();
	}
}

int main()
{
	printMenu();

	char ch;
	cin >> ch;
	interactWithMenu(ch);

	string nickname;
	size_t dimension;
	int points = 0;
	char command;

	int board[SIZE][SIZE] = { 0 };

	if (ch == 's') {
		cout << "Enter your nickname: " << endl;
		cin >> nickname;

		cout << "Enter dimension: " << endl;
		cin >> dimension;

		safeInfoAboutPlayer(nickname, dimension, points);

		randomGenerator(board, dimension);
		while (hasFreePosition(board, dimension)) {
			cin >> command;
			playGame(board, dimension, command);
		}
	}
	else if (ch == 'l') {

		cout << "Enter dimension: ";
		cin >> dimension;
		showLeaderboard(dimension);
	}
}
