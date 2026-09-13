#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Заполнение массива рандом числами 
void fillArray(int (&arr)[10]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
}

// Выводим на экран массив
void printArray(const int(&arr)[10]) {
    for (const auto& x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

// Меняем местами два элемента массива по индексам
void swapElements(int (&arr)[10], int i, int j) {
    if (i < 0 || i >= 10 || j < 0 || j >= 10) {
        cerr << "Ошибка. Индекс вне диапазона [0, 9]" << endl;
        return;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Умножаем каждый элемент массива на 2
void multiplyByTwo(int (&arr)[10]) {
    for (int& x : arr) {
        x *= 2;
    }
}

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