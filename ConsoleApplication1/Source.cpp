#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale>
#include <conio.h>
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	const int matrix_A_Columns = 12000;
	const int matrix_A_Rows = 25000;
	const int matrix_B_Columns = 36000;
	const int matrix_B_Rows = 12000;

	float matrix_A[matrix_A_Rows][matrix_A_Columns];
	float matrix_B[matrix_B_Rows][matrix_B_Columns];
	vector<vector<float>> matrix_Result(matrix_A_Rows, vector<float>(matrix_B_Columns));

	for (int i = 0; i < matrix_A_Rows; i++) {
		for (int j = 0; j < matrix_A_Columns; j++) {
			matrix_A[i][j] = (rand() % 4000 - 1900) / 100.0;
			cout << matrix_A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//second matrix init
	for (int i = 0; i < matrix_B_Rows; i++) {
		for (int j = 0; j < matrix_B_Columns; j++) {
			matrix_B[i][j] = (rand() % 4000 + 100) / 100.0;
			cout << matrix_B[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//matrix multiplication
	for (int i = 0; i < matrix_A_Rows; i++)
		for (int j = 0; j < matrix_B_Columns; j++)
		{
			matrix_Result[i][j] = 0;
			for (int k = 0; k < matrix_A_Columns; k++)
			{
				matrix_Result[i][j] += matrix_A[i][k] * matrix_B[k][j];
			}
		}

	for (int i = 0; i < matrix_A_Rows; i++) {
		for (int j = 0; j < matrix_B_Columns; j++)
			cout << matrix_Result[i][j] << " ";
		cout << endl;
	}

	cout << "Нажмите любую клавишу...";
	_getch();
	return 0;
}