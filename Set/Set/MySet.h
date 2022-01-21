#pragma once
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

	int coincidences(MySet set) { //ñîâïàäåíèÿ
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
		//if((ch >= 'À' && ch <= 'ÿ') || ch == '¸' || ch == '¨')
		this->CharStr.push_back(ch);
		return *this;
	}

	MySet append(string str) {
		for (char ch : str)
			//if ((ch >= 'À' && ch <= 'ÿ') || ch == '¸' || ch == '¨')
			this->CharStr.push_back(ch);
		return *this;
	}

	void clear() {
		this->CharStr.clear();
	}

	MySet& operator<<(string str) {
		for (int i = 0; i < str.length(); i++) {
			//if ((str[i] >= 'À' && str[i] <= 'ÿ') || str[i] == '¸' || str[i] == '¨')
			this->CharStr.push_back(str[i]);
		}
		return *this;
	}

	MySet& operator<<(char ch) {
		//if ((ch >= 'À' && ch <= 'ÿ') || ch == '¸' || ch == '¨')
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