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

int main() {
    setlocale(LC_ALL, ".UTF-8");

    SafeArray myArr = createArray(5);

    // Запись слева от знака равенства
    getElement(myArr, 2) = 999;
    getElement(myArr, 4) = 42;

    printSafe(myArr);

    // Проверка выхода за границы
    getElement(myArr, 10) = 777;
    printSafe(myArr);

    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}