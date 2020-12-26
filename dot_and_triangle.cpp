#include <fstream>
#include <iostream>
#include <cmath>
#include <String>
using namespace std;


void z2()
{
    int x1 = 3;
    int y1 = 1;

    int x2 = 10;
    int y2 = 6;

    int x3 = 10;
    int y3 = 0;

    int x0 = 10;
    int y0 = 1;

    int D1 = (x0 - x1) * (y2 - y1) - (y0 - y1) * (x2 - x1);
    int D2 = (x0 - x2) * (y3 - y2) - (y0 - y2) * (x3 - x2);
    int D3 = (x0 - x3) * (y1 - y3) - (y0 - y3) * (x1 - x3);

    if(D1>=0 && D2>=0 && D3>=0)cout << "Точка входит в треугольник" << "\n";
    else cout << "Точка не входит в треугольник" << "\n";
}
int main(){
 setlocale(LC_ALL, "Russian");
 z2();
}
