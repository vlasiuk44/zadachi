#include <iostream>
#include <limits.h>
#include <cmath>
#include <string>
using namespace std;

void metod()
{
    string h;
    int len;
    cout << "Enter k : ";
    cin >> len;
    
    float k = 1;
    for (int n = 0; n <= len;n++) {
        k = (pow(k, 3));
        h += to_string((int)k);
        k = (pow(k, 1.0/3));
        k++;

    }
    cout << h[len-1];
}

int main() {
    metod();
}
