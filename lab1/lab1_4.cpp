#include <iostream>
using namespace std;

/**
 * @brief Выделяет память под двумерный массив (матрицу), заполненный нулями
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @return Указатель на массив указателей (int**)
 * @warning Освобождать через freeMatrix()
 */
int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows]{};
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}

/**
 * @brief Заполняет матрицу с клавиатуры
 * @param matrix Указатель на матрицу
 * @param rows Количество строк
 * @param cols Количество столбцов
 */
void fillMatrix(int** matrix, int rows, int cols) {
    cout << "Введите " << rows * cols << " элементов матрицы (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j]; 
        }
    }
}

/**
 * @brief Красиво выводит матрицу на экран
 * @param matrix Указатель на матрицу
 * @param rows Количество строк
 * @param cols Количество столбцов
 * @param showBorders Рисовать ли рамку из '*' (по умолчанию true)
 * @param title Заголовок над матрицей (по умолчанию "Matrix")
 */
void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, string title = "Matrix") {
    cout << "\n ||| " << title << " |||\n";

    if (showBorders) {
        cout << "*";
        for (int j = 0; j < cols; ++j) {
            cout << "*****";
        }
        cout << "*\n";
    }

    for (int i = 0; i < rows; ++i) {
        if (showBorders) cout << "*";
        for (int j = 0; j < cols; ++j) {
            cout << " " << matrix[i][j];

            int len = to_string(matrix[i][j]).length();
            for (int k = len; k < 4; ++k) cout << " ";
            if (showBorders) cout << "*";
        }
        if (showBorders) cout << "*";
        cout << "\n";
    }

    if (showBorders) {
        cout << "*";
        for (int j = 0; j < cols; ++j) {
            cout << "*****";
        }
        cout << "*\n";
    }
    cout << endl;
}

/**
 * @brief Освобождает память, занятую матрицей
 * @param matrix Указатель на матрицу
 * @param rows Количество строк
 * @note Сначала удаляются вложенные массивы, затем массив указателей
 */
void freeMatrix(int** matrix, int rows) {
    if (matrix == nullptr) {
        return;
    }
    
    for(int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

/**
 * @brief Точка входа
 * @return 0 при успешном завершении
 */
int main() {
    setlocale(LC_ALL, ".UTF-8");

    int rows = 3, cols = 4;
    int** myMatrix = allocateMatrix(rows, cols);
    
    fillMatrix(myMatrix, rows, cols);

    printMatrix(myMatrix, rows, cols);

    printMatrix(myMatrix, rows, cols, true, "Bebebe");

    printMatrix(myMatrix, rows, cols, false, "Без рамки");

    freeMatrix(myMatrix, rows);
    myMatrix = nullptr;

    return 0;
}