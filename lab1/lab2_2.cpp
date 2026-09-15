#include <iostream>
using namespace std;

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

    cout << "Массив создан. Размер: " << N << endl;

    // Освобождаем память
    delete[] arr;
    arr = nullptr;

    return 0;
}