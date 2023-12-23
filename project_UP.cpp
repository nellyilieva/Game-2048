#include <iostream>
#include <string>
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

bool checkSize(int SIZE) {
	if (SIZE < 4 || SIZE > 10) {
		return false;
	}
	return true;
}

void returnPoints(int points) {

}

void printMatrix(int matrix[][SIZE], const size_t SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void commandsMovement(char command) {
	//logic for game	
}

void randomGenerator() {
	//check if free position
	//add 2 or 4 on random free postion
}

void safeInfoAboutPlayer(string nickname, const int SIZE) {
	//check if result is in top 5
	//safe in specific file (result and nickname)
}

void playGame(const int matrix[][10], const int SIZE, char command) {

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

	if (ch == 's') {
		cout << "Enter your nickname: " << endl;
		cin >> nickname;

		cout << "Enter dimension: " << endl;
		cin >> dimension;

		if (checkSize(dimension)) {
			int board[SIZE][SIZE] = { 0 };
			printMatrix(board, dimension);

			cout << points;
		}
	}
}