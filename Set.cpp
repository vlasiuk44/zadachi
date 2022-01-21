#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm> 
using namespace std;



class MySet {
public:

	void getSort() {
		sort(CharStr.begin(), CharStr.end());
		unique(CharStr.begin(), CharStr.end());
	}



	int getSize() {
		return this->CharStr.size();
	}

	int coincidences(MySet set) { //совпадения
		int counter = 0;
		for (char ch : this->CharStr) {
			bool inStr = find(set.CharStr.begin(), set.CharStr.end(), ch) != set.CharStr.end();
			if (inStr) {
				counter++;
			}
		}
		return counter;
	}

	MySet remove(int i) {
		this->CharStr.erase(this->CharStr.begin() + i);
		return *this;
	}

	MySet remove(char ch) {
		vector<char>::iterator it = find(this->CharStr.begin(), this->CharStr.end(), ch);
		int index = it - this->CharStr.begin();
		this->CharStr.erase(this->CharStr.begin() + index);
		return *this;
	}

	MySet append(char ch) {
		//if((ch >= 'А' && ch <= 'я') || ch == 'ё' || ch == 'Ё')
			this->CharStr.push_back(ch);
		return *this;
	}

	MySet append(string str) {
		for (char ch : str)
			//if ((ch >= 'А' && ch <= 'я') || ch == 'ё' || ch == 'Ё')
				this->CharStr.push_back(ch);
		return *this;
	}

	void clear() {
		this->CharStr.clear();
	}

	MySet& operator<<(string str) {
		for (int i = 0; i < str.length(); i++) {
			//if ((str[i] >= 'А' && str[i] <= 'я') || str[i] == 'ё' || str[i] == 'Ё')
				this->CharStr.push_back(str[i]);
		}
		return *this;
	}

	MySet& operator<<(char ch) {
		//if ((ch >= 'А' && ch <= 'я') || ch == 'ё' || ch == 'Ё')
			this->CharStr.push_back(ch);

		return *this;
	}

	MySet& operator- (MySet set) {
		while (coincidences(set) != 0) {
			for (char ch : this->CharStr) {
				bool inStr = find(set.CharStr.begin(), set.CharStr.end(), ch) != set.CharStr.end();
				if (inStr)
					this->remove(ch);
			}
		}
		return *this;
	}

	bool operator== (MySet set) {
		return this->CharStr == set.CharStr;
	}

	MySet& operator+ (MySet set) {

		for (char ch : set.CharStr) {
			bool inStr = find(this->CharStr.begin(), this->CharStr.end(), ch) != this->CharStr.end();
			if (inStr)
				continue;
			else
				append(ch);
		}
		return *this;
	}

	MySet& operator& (MySet set) {
		MySet buf = *this;
		MySet buf2;
		for (char ch1 : buf.CharStr) {
			for (char ch2 : set.CharStr) {
				if (ch1 != ch2)continue;
				else {
					vector<char>::iterator it = find(buf.CharStr.begin(), buf.CharStr.end(), ch1);
					int index = it - buf.CharStr.begin();
					buf2 << buf[index];
				}
			}
		}
		*this = buf2;
		return *this;
	}

	char& operator[](const int index)
	{
		return CharStr[index];
	}
	vector<string> Strr;


private:
	vector<char> CharStr;

};

ostream& operator<<(ostream& stream, MySet set) {
	for (int i = 0; i < set.getSize(); i++) {
		stream << "[" << set[i] << "] ";
	}
	return stream;
}





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