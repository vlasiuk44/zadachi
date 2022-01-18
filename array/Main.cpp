#include <iostream>
#include <istream>
#include "Array.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    Array arr(4);

    for (int i = 0; i < 4; i++)
        arr.insert(i + 1);
    arr.remove(0); //удаляет 0 элемнт arr
    cout << arr << endl;

    Array arr2(2);

    for (int i = 0; i < 2; i++)
        arr2.insert(i * 2);

    cout << arr2 << endl;

    arr.pop();
    arr.insert(arr2, 1); //вставляет arr2 в arr после 1 элемента
    cout << arr == arr;
    
    
    return 0;
}