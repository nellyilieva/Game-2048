#include <iostream>
#include "moveFunctions.h"
using namespace std;

const size_t SIZE = 10;
int points = 0;

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
	for (int i = 0; i < SIZE; i++) {

		int nextCol = i;
		int nextRow = 0;

		for (int j = 1; j < SIZE; j++) {

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