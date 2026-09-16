#include <iostream>
using namespace std;

/**
 * @struct SafeArray
 * @brief Безопасный массив с контролем границ
 */
struct SafeArray {
    int* data;      ///< Указатель на данные
    int size;       ///< Количество элементов
};

/**
 * @brief Создаёт массив заданного размера, заполненный нулями
 * @param size Размер массива
 * @return Структура SafeArray
 */
SafeArray createArray(int size) {
    SafeArray arr;
    arr.size = size;
    arr.data = new int[size]{};
    return arr;
}

/**
 * @brief Возвращает ссылку на элемент по индексу
 * @param arr Ссылка на SafeArray
 * @param index Индекс элемента
 * @return Ссылка на элемент; при выходе за границы  ссылка на заглушку
 * @note Позволяет писать: getElement(arr, 2) = 999;
 */
int& getElement(SafeArray& arr, int index) {
    if (index < 0 || index >= arr.size) {
        cout << "Ошибка. Индекс " << index << " вне диапозона [0, " << arr.size - 1 << "]" << endl;

        static int dummy = 0;
        return dummy;
    }
    return arr.data[index];
}

/**
 * @brief Выводит массив на экран
 * @param arr Константная ссылка на SafeArray
 */
void printSafe(const SafeArray& arr) {
    cout << "SafeArray[" << arr.size << "]: ";
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Изменяет размер массива
 * @param arr Ссылка на SafeArray
 * @param M Новый размер
 * @note При уменьшении удалённые элементы выводятся на экран,
 *       при увеличении новые заполняются нулями
 */
void reSizeArray(SafeArray& arr, int M) {
    int N = arr.size;

    if (M == N) {
        return;
    }

    int* newData = new int[M]{};

    if (M < N) {
        cout << "Удалены элементы: ";
        for (int i = M; i < N; i++) {
            cout << arr.data[i] << " ";
        }
        cout << endl;

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

/**
 * @brief Точка входа
 * @return 0 при успешном завершении
 */
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