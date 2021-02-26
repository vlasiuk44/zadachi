#include<iostream>
#include <fstream>
#include <string>
using namespace std;

bool prostoe(long long num) {
    for (int i = 2; i < sqrt(num); i++) {
        if (num % i == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream fin("enew.txt");
    string chislo, buffer, str;


    while (fin >> buffer) {
        chislo += buffer;
    }

    for (int k = 9; k < chislo.length(); k++) {
        str = "";
        for (int i = k - 9; i <= k; i++) {
            if (int(chislo[i] > 58 || chislo[i] < 48)){ 
                continue;
            }
            str += chislo[i];
        }

        long long l = stoll(str);
        if (!prostoe(l)) {
            cout << l;
            break;
        }
    }

}
