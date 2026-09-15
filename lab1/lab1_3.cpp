#include <iostream>
using namespace std;

struct SafeArray {
    int* data;
    int size;
};

SafeArray createArray(int size) {
    SafeArray arr;
    arr.size = size;
    arr.data = new int[size]{};
    return arr;
}

int& getElement(SafeArray& arr, int index) {
    // 3.1 Проверяеем границы
    if (index < 0 || index >= arr.size) {
        cout << "Ошибка. Индекс " << index << " вне диапозона [0, " << arr.size - 1 << "]" << endl;

        static int dummy = 0;
        return dummy;
    }
    // 3.2 Корректный индекс
    return arr.data[index];
}

void printSafe(const SafeArray& arr) {
    cout << "SafeArray[" << arr.size << "]: ";
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
    cout << endl;
}

void reSizeArray(SafeArray& arr, int M) {
    int N = arr.size;

    if (M == N) {
        return;
    }

    int* newData = new int[M]{};

    if (M < N) {
        // 6.1 При уменьшении массива выводим удаленные элементы
        cout << "Удалены элементы: ";
        for (int i = M; i < N; i++) {
            cout << arr.data[i] << " ";
        }
        cout << endl;

        // Копируем только первые M
        for (int i = 0; i < M; i++) {
            newData[i] = arr.data[i];
        }
    }
    else {
        // 6.2 При увеличении массива новые элементы равны 0
        for (int i = 0; i < N; i++) {
            newData[i] = arr.data[i];
        }
    }

    delete[] arr.data;
    arr.data = newData;
    arr.size = M;
}

int main() {
    setlocale(LC_ALL, ".UTF-8");

    SafeArray myArr = createArray(5);

    // Запись слева от знака равенства
    getElement(myArr, 2) = 999;
    getElement(myArr, 4) = 42;

    cout << "Исходный массив: " << endl;
    printSafe(myArr);

    cout << "\nУменьшаем с 5 до 3: " << endl;
    reSizeArray(myArr, 3);
    printSafe(myArr);

    cout << "\nУвеличиваем с 3 до 7: " << endl;
    reSizeArray(myArr, 7);
    printSafe(myArr);

    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}