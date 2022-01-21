
#ifndef MYSET_H
#define MYSET_H
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm> 
using namespace std;



class MySet{
public:
	void getSort();
	int getSize();
	int coincidences(MySet set);
	MySet remove(int i);
	MySet remove(char ch);
	MySet append(char ch);
	MySet append(string str);
	void clear();
	MySet& operator<<(string str);
	MySet& operator<<(char ch);
	MySet& operator- (MySet set);
	bool operator== (MySet set);
	MySet& operator+(MySet set);
	MySet& operator& (MySet set);
	char& operator[](const int index);
private:
	vector<char> CharStr;
};
#endif
