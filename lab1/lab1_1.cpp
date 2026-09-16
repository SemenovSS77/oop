#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * @brief Заполняет массив случайными числами в диапазоне [0, 99]
 * @param arr Ссылка на массив из 10 элементов
 */
void fillArray(int (&arr)[10]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
}

/**
 * @brief Выводит массив на экран
 * @param arr Константная ссылка на массив из 10 элементов
 */
void printArray(const int(&arr)[10]) {
    for (const auto& x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

/**
 * @brief Меняет местами два элемента массива по индексам
 * @param arr Ссылка на массив из 10 элементов
 * @param i Индекс первого элемента
 * @param j Индекс второго элемента
 * @warning Если индекс вне диапазона [0, 9], выводится сообщение об ошибке и обмен не выполняется
 */
void swapElements(int (&arr)[10], int i, int j) {
    if (i < 0 || i >= 10 || j < 0 || j >= 10) {
        cerr << "Ошибка. Индекс вне диапазона [0, 9]" << endl;
        return;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/**
 * @brief Умножает каждый элемент массива на 2
 * @param arr Ссылка на массив из 10 элементов
 */
void multiplyByTwo(int (&arr)[10]) {
    for (int& x : arr) {
        x *= 2;
    }
}

/**
 * @brief Точка входа. Демонстрирует работу функций над массивом.
 * @return 0 при успешном завершении
 */
int main() {
    setlocale(LC_ALL, ".UTF-8");
    srand(time(nullptr));
    
    int arr[10];
    
    fillArray(arr);
    cout << "Исходный массив: ";
    printArray(arr);

    swapElements(arr, 2, 7);
    cout << "После обмена: ";
    printArray(arr);

    multiplyByTwo(arr);
    cout << "После умножения на 2: ";
    printArray(arr);

    return 0;
}