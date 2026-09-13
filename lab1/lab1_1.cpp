#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillArray(int (&arr)[10]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
}

int main() {
    setlocale(LC_ALL, ".UTF-8");
    srand(time(nullptr));
    
    int arr[10];
    
    fillArray(arr);

    return 0;
}