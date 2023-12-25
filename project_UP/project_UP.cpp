#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const size_t SIZE = 10;

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

void returnPoints(int points) {
	//???
}

bool checkSize(int SIZE) {
	if (SIZE < 4 || SIZE > 10) {
		return false;
	}
	return true;
}

void printMatrix(int matrix[][SIZE], const size_t SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
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

int returnOnRandomTwoOrFour() {
	srand(static_cast<unsigned int>(time(nullptr)));

	return (rand() % 2 == 0) ? 2 : 4;
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
	printMatrix(matrix, SIZE);
}

bool validCommand(char command) {
	if (command == 'w' || command == 'a' || command == 's' || command == 'd') {
		return true;
	}

	return false;
}

void makeMoveRight(int matrix[][SIZE], const size_t SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			int curr = matrix[i][j];
			int nextCoordinate = j + 1;

			if (curr == 0) {
				continue;
			}

			if (matrix[i][nextCoordinate] == 0) {
				matrix[i][nextCoordinate] = curr;
				matrix[i][j] = 0;
			}

			else if (curr == matrix[i][nextCoordinate]) {
				matrix[i][nextCoordinate] += curr;
				curr = 0;
			}
		}
	}

	printMatrix(matrix, SIZE);
}

void makeMoveLeft(int matrix[][SIZE], const size_t SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = SIZE - 1; j > 0; j--) {
			int curr = matrix[i][j];
			int nextCoordinate = j - 1;

			if (curr == 0) {
				continue;
			}

			if (matrix[i][nextCoordinate] == 0) {
				matrix[i][nextCoordinate] = curr;
				matrix[i][j] = 0;
			}

			else if (curr == matrix[i][nextCoordinate]) {
				matrix[i][nextCoordinate] += curr;
				curr = 0;
			}
		}
	}

	printMatrix(matrix, SIZE);
}

void makeMoveDown(int matrix[][SIZE], const size_t SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			int curr = matrix[j][i];
			int nextCoordinate = j + 1;

			if (curr == 0) {
				continue;
			}

			if (matrix[nextCoordinate][i] == 0) {
				matrix[nextCoordinate][i] = curr;
				matrix[j][i] = 0;
			}

			else if (curr == matrix[nextCoordinate][i]) {
				matrix[nextCoordinate][i] += curr;
				curr = 0;
			}
		}
	}

	printMatrix(matrix, SIZE);
}

void makeMoveUp(int matrix[][SIZE], const size_t SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = SIZE - 1; j > 0; j--) {
			int curr = matrix[j][i];
			int nextCoordinate = j - 1;

			if (curr == 0) {
				continue;
			}

			if (matrix[nextCoordinate][i] == 0) {
				matrix[nextCoordinate][i] = curr;
				matrix[j][i] = 0;
			}

			else if (curr == matrix[nextCoordinate][i]) {
				matrix[nextCoordinate][i] += curr;
				curr = 0;
			}
		}
	}

	printMatrix(matrix, SIZE);
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
	else {
		makeMoveRight(matrix, SIZE);
	}
}

void playGame(const int matrix[][10], const int SIZE, char command) {

}

void safeInfoAboutPlayer(string nickname, const int SIZE) {
	//check if result is in top 5
	//safe in specific file (result and nickname)
}

void showLeaderboard(const int SIZE) {
	//ask for size
	//go to file for size and show top 5
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

		if (checkSize(dimension)) {
			randomGenerator(board, dimension);

			cin >> command;

			commandsMovement(command, board, dimension);

		}
	}


}