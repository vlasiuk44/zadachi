#include <iostream>
#include <bitset> //для отображения двоичного кода
using namespace std;
int main() {

    for (int num=1;num<1000;num++){
        int num2=((num<<32-int(log2(num))-2)>>(32-int(log2(num))-3) | (num>>int(log2(num))))-((num>>int(log2(num)))<<int(log2(num))+1);
        cout<<num<<" - "<<num2<<"\n";
        cout << bitset<sizeof(num) * CHAR_BIT>(num) << " - " << bitset<sizeof(num2) * CHAR_BIT>(num2)<<"\n";
    }
    return 0;
}
