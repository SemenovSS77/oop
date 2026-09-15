#include <iostream>
using namespace std;

// Вывод массива на экран
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, ".UTF-8");

    int N;
    cout << "Введите размер массива N: ";
    cin >> N;

    if (N <= 0) {
        cerr << "Ошибка. Размер массива должен быть положительным" << endl;
        return 1;
    }

    // Выделяем память под массив
    int* arr = new int[N]{};

    // Заменяем массив с клавиатуры
    cout << "Введите " << N << " целых чисел: " << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Исходный массив: ";
    printArray(arr, N);

    // Освобождаем память
    delete[] arr;
    arr = nullptr;

    return 0;
}