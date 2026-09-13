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

int main() {
    setlocale(LC_ALL, ".UTF-8");
    srand(time(nullptr));
    
    int arr[10];
    
    fillArray(arr);
    cout << "Исходный массив: ";
    printArray(arr);

    return 0;
}