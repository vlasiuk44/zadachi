using namespace std;
#include <typeinfo>
#include <fstream>
#include <iostream>
#include <ctime>

float radius = 0;
int counter = 0;
int top_y = 500;
int bot_y = 0;
int left_x = 500;
int right_x = 0;
int key = 0;
char buff;
char matrix[400][400];
ifstream fin("input3.dat"); // открыли файл для чтения
ofstream fout("output3_newMatrix.txt");
ofstream fout1("output3.txt");



void inp_krug()
{
    for (int i = 0; i < 400; i += 1) {
        for (int j = 0; j < 400; j += 1) {
            fin >> buff;
            matrix[i][j] = buff;

        }
    }
}

void filtacia() {
    for (int i = 0; i < 400; i += 1) {
        for (int j = 0; j < 400; j += 1) {
            if ((matrix[i][j] == '1') && ((matrix[i][j + 1] == '0') && (matrix[i][j - 1] == '0') && (matrix[i + 1][j] == '0') && (matrix[i - 1][j] == '0') &&
                (matrix[i + 1][j + 1] == '0') && (matrix[i - 1][j - 1] == '0') && (matrix[i - 1][j + 1] == '0') && (matrix[i + 1][j - 1] == '0')) || (i == 0 && j == 0) || (i == 399 && j == 399) ||
                (((i == 0) || (i == 399)) && (matrix[i][j + 1] == '0') && (matrix[i][j - 1] == '0')) ||
                (((j == 0) || (j == 399)) && (matrix[i + 1][j] == '0') && (matrix[i - 1][j] == '0'))) {
                matrix[i][j] = '0';
            }
        }
    }
}

void out_krug() {
    for (int i = 0; i < 400; i += 1) {
        for (int j = 0; j < 400; j += 1) {
            fout << matrix[i][j];
        }
        fout << "\n";
    }
}

void koord() {
    for (int i = 0; i < 400; i += 1) {
        for (int j = 0; j < 400; j += 1) {
            if (matrix[i][j] == '1' && i < top_y) {
                top_y = i;
            }
        }
    }
    for (int i = 0; i < 400; i += 1) {
        for (int j = 0; j < 400; j += 1) {
            if (matrix[i][j] == '1' && i > bot_y) {
                bot_y = i;
            }
        }
    }
    for (int i = 0; i < 400; i += 1) {
        for (int j = 0; j < 400; j += 1) {
            if (matrix[i][j] == '1' && j < left_x) {
                left_x = j;
            }
        }
    }
    for (int i = 0; i < 400; i += 1) {
        for (int j = 0; j < 400; j += 1) {
            if (matrix[i][j] == '1' && j > right_x) {
                right_x = j;
            }
        }
    }


    radius = ceil((float)(right_x - left_x) / 2);
    cout << "radius = " << radius << "\n"
        << "center (" << left_x + radius << ";" << top_y + radius << ")" << "\n";
}

void line() {
    for (int i = 0; i < 400; i += 1) {
        for (int j = 0; j < 400; j += 1) {
            if (i == top_y) {
                matrix[i - 1][j] = '2';
            }
        }
    }
    for (int i = 0; i < 400; i += 1) {
        for (int j = 0; j < 400; j += 1) {
            if (i == bot_y) {
                matrix[i + 1][j] = '2';
            }
        }
    }
    for (int i = 0; i < 400; i += 1) {
        for (int j = 0; j < 400; j += 1) {
            if (j == left_x) {
                matrix[i][j - 1] = '2';
            }
        }
    }
    for (int i = 0; i < 400; i += 1) {
        for (int j = 0; j < 400; j += 1) {
            if (j == right_x) {
                matrix[i][j + 1] = '2';
            }
        }
    }
}

int main(int argc, char* argv[])
{

    inp_krug(); //функция принимает файл и записывает его в массив (путь к файлу указывается програмно)
    filtacia();//фильтрация массива от всех единиц, у которых нет соседних единиц
    koord();//расчитывание крайних точек окружности, опрделение радиуса с учетом оставшихся шумов
    line();//накладываем рисунок прямых, в которые вписана окружность
    out_krug();// вывод нового изображения в файл output.txt
    unsigned int end_time = clock();
    cout << "end time - 0." << end_time << " sec";
    fout1<< "end time - 0." << end_time << " sec"<<"\n"
        << "radius = " << radius << "\n"
        << "center (" << left_x + radius << ";" << top_y + radius << ")" << "\n";

}

