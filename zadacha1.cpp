#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


int count_words(string s) //функция подсчитывает слова в строке
{
    s += ' ';
    int a = 0;
    for (size_t i = 0; i < s.length(); i++)
        if (s[i] == ' ') a++;
    return a;
}

string* cut_words(string s) //функция разрезает строку на слова и возвращает массив
{
    s += ' ';
    int c = 0;
    int p = 0;
    int i = 0;
    string* s_return = new string[count_words(s)];
    while (s.length() != 0)
    {
        if (s[i] != ' ')
        {
            c++;
            i++;
        }
        else
        {
            i = 0;
            s_return[p] = s.substr(0, c);
            s.erase(0, c + 1);
            c = 0;
            p++;
        }
    }
    return s_return;
}



int main()
{
    int n = 1;
    setlocale(LC_ALL, "Russian");
    string words = "привет пока корма акоп приевт пако купало опка комра тевирп копа амкор попкоре земля ыкпыуим гтглтодл рокма ямлез";
    string* result = new string[count_words(words)];

    string* cut = new string[count_words(words)];
    for (int i=0; i < count_words(words); i++) {
        cut[i] = (cut_words(words))[i];
    }

    for (int l = 0; l < count_words(words); l ++) {
        int* code = new int[cut[l].length()];
        for (int i = 0; i < (cut[l]).length(); i++) { //записывает коды в новый массив
            code[i] = (int)cut[l][i];
        }
        int length = cut[l].length();
        for (int startIndex = 0; startIndex < length - 1; ++startIndex) //принимает массив и сортирует его
        {
            int smallestIndex = startIndex;
            for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
            {
                if (code[currentIndex] < code[smallestIndex])
                    smallestIndex = currentIndex;
            }
            swap(code[startIndex], code[smallestIndex]);
            swap(cut[l][startIndex], cut[l][smallestIndex]);
        }
        string end;
        for (int i = 0; i < cut[l].length(); i++) {  //выводит массив        
           
            end += cut[l][i];
        }
        result[l] = end;
        
    }


    int ech = 0;
    for (int i = 0; i < count_words(words); i++) {    
        int key = 1;
        for (int j = i+1; j < count_words(words); ++j) {
            if (result[i] == result[j]) {
                if (key == 1) {
                    cout <<"("<< cut_words(words)[i] << " ";
                    key = 0;
                }
                cout << cut_words(words)[j] << " ";
                result[j] = ech;
                ech++;
                
            }

            
        }
      
    }
    

}
    
