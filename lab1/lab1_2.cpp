#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".UTF-8");

    int N{};
    cout << "Введите размер массива N: ";
    cin >> N;

    // Выделяем память
    int* arr{ new int[N]{} };

    cout << "Введите " << N << " элементов массива: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Освобождаем память
    delete[] arr;
    arr = nullptr;

    return 0;
}