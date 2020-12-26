#include <fstream>
#include <iostream>
#include <cmath>
#include <String>
using namespace std;



int main()
{
    int a[] = { 1,2,1,3,2,3,4,5,6,5,5,6,7,4,8,1 };
    int n = 16;
    for (int startIndex = 0; startIndex < n - 1; ++startIndex) //принимает массив и сортирует его
    {
        int smallestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < n; ++currentIndex)
        {
            if (a[currentIndex] < a[smallestIndex])
                smallestIndex = currentIndex;
        }
        swap(a[startIndex], a[smallestIndex]);
        
    }

    cout << a[0] << " ";
    for (int last = a[0], i = 1; i < sizeof(a) / sizeof(a[0]); ++i)
    {
        if (a[i] == last) continue;
        cout << (last = a[i]) << " ";
    }
    cout << endl;
}

