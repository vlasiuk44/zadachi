#include <iostream>
using namespace std;

int checkNumber(__int64 number) {
    int arr[10];
    
    if (number % 8 == 0) {
        for (int i = 0; i < 10; ++i) {
            arr[i] = 0;
        }

        while (number > 0) {

            if (arr[number % 10] == 1) {
                return 0;
            }

            arr[number % 10] = 1;

            number /= 10;
        }

        number /= 8;

        while (number > 0) {

            if (arr[number % 10] == 2) {
                return 0;
            }

            arr[number % 10] = 2;

            number /= 10;
        }
        return 1;
    }
    return 0;
}

int main() {
    int max = 0;
    for (__int64 i = 9876543210; i >= 0; i--) {
        if (checkNumber(i) == 1) {
            cout << (i / 8);
            break;
        }
    }
    return 0;
}
