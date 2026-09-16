#include <iostream>
using namespace std;

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows]{};
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}

void fillMatrix(int** matrix, int rows, int cols) {
    cout << "Введите " << rows * cols << " элементов матрицы (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j]; 
        }
    }
}

int main() {
    setlocale(LC_ALL, ".UTF-8");
    return 0;
}