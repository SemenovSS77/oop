#include <iostream>
using namespace std;

void process(int*& arr, int size) {
    
    // Находим первый отрицательный элемент
    int negIndex = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            negIndex = i;
            break;
        }
    }

    // Если нашли, то создаем новый массив до отрицательного
    if (negIndex != -1) {
        int newSize = negIndex;
        int* newArr = new int[newSize]{};

        for (int i = 0; i < newSize; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }
}

int main() {
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

    int originalN = N;

    process(arr, N);

    int actualSize = originalN;
    for (int i = 0; i < originalN; i++) {
        if (arr[i] < 0) {
            actualSize = i;
            break;
        }
    }

    cout << "Результат: ";
    for (int i = 0; i < actualSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Освобождаем память
    delete[] arr;
    arr = nullptr;

    // Безопасная проверка nullptr
    if (arr != nullptr) {
        cout << "Значение по указателю: " << *arr << endl;
    }
    else {
        cout << "Указатель равен nullptr, безопасно" << endl;
    }

    return 0;
}