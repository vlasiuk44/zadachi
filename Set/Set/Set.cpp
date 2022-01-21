#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm> 
#include "MySet.h"
using namespace std;









//пересечение

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	
	MySet v;
	MySet f;
	v << "мой текст для v";
	f << "мой текст для f";

	cout << "MySet v: " << v << "\n";
	v.remove('д');
	cout << "MySet v after remove 'д': " << v << "\n";

	v.remove(0);
	cout << "MySet v after remove 0 element: " << v << "\n";


	v.append('c');
	cout << "MySet v after append 'c': " << v << "\n";

	v.append("bb");
	cout << "MySet v after append 'b' 'b': " << v << "\n";

	v << 'a';
	cout << "MySet v after append 'a': " << v << "\n";


	cout << "MySet v size: " << v.getSize() << "\n";
	cout << "MySet v 0 element: " << v[0] << "\n";



	cout << "v: " << v << "\n";
	cout << "f: " << f << "\n";

	cout << "совпадений (v, f): " << v.coincidences(f) << "\n";

	v = v - f;

	cout << "v - f = " << v << "\n";

	v.clear();
	f.clear();
	v << "1234";
	f << "3456";
	MySet x;
	x << "3456";


	cout << "new v: " << v << "\n";
	cout << "new f: " << f << "\n";
	v = v + f;
	cout << "v + f = " << v << "\n";

	cout << "x: " << x << "\n";

	if (x == f)
		cout << "x == f: " << "true\n";


	v.clear();
	f.clear();
	v << "12347";
	f << "3456";
	cout << "new v: " << v << "\n";
	cout << "new f: " << f << "\n";

	v = v & f;
	cout << "v & f: " << v << "\n";
	
	vector<string> AllTextVector;
	string line;


	ifstream fin("text.txt");
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			AllTextVector.push_back(line);
		}
	}
	fin.close();

	string AllTextInLine = "";

	for (std::vector<std::string>::const_iterator i = AllTextVector.begin(); i != AllTextVector.end(); ++i)
		AllTextInLine += *i; //весь текст в одной строке

	//cout << AllTextInLine;

	MySet* array = new MySet[AllTextInLine.size()];


	string append;
	int count = 0;

	for (int i = 0; AllTextInLine != ""; i++) {

		char* char_array = new char[line.length()]; //массив символов всего текста

		strcpy(char_array, AllTextInLine.c_str()); //заполняем массив


		char* istr = strtok(char_array, ".!?"); //первое предложение в массиве символов 
		string append = string(istr);

		if (append[0] == ' ') {
			append = append.substr(1);
			array[i] << append;
			AllTextInLine = AllTextInLine.substr((append.length() + 2));

		}

		else {
			array[i] << append;
			AllTextInLine = AllTextInLine.substr((append.length() + 1));
		}
		count++;
		(array[i]).getSort();
		//cout << i << ": " << array[i] << "\n";

	}

	bool key = false;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (i == j)continue;
			if (array[j] == array[i]) {
				cout << i << " " << j << " одинаковые\n";
				key = true;
				break;
			}
		}
		if (key)break;
	}
	key = false;


	/*for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (i == j)continue;
			MySet test = array[i] & array[j];
			cout << i << " " << j << "\n";
			if (test.getSize() == 0) {
				cout << i << " " << j << " нет совпадений\n";


				key = true;
				break;

			}
		}
		if (key)break;
	}
	key = false;*/



	delete[] array;

	return 0;
}