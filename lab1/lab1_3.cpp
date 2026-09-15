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

int main() {
    setlocale(LC_ALL, ".UTF-8");

    SafeArray myArr = createArray(5);

    delete[] myArr.data;
    myArr.data = nullptr;

    return 0;
}