/*
 Submit a solution for C-Анаграмма
 Time limit:	2 s
 Real time limit:	5 s
 Memory limit:	64M
 Анаграмма
 Задано слово, состоящее из строчных букв латинского алфавита. Рассмотрим набор всех перестановок букв этого слова (например, "abc" имеет всего 6 перестановок — «abc», «acb», «bac», «bca», «cab», «cba», а слово «abb» — три перестановки, «abb», «bab», «bba»). Требуется выбрать из этого множества слово, следующее за заданным по алфавиту.
 Input format
 Во входной строке записано слово, состоящее не более чем из 100 строчных букв латинского алфавита, не последнее в множестве перестановок.
 Output format
 Вывести строку, содержащую слово, следующее за данным по алфавиту.
 Examples
 Input	Output
 qwerty
 qweryt

 
 */



#include <string>
#include <iostream>
using namespace std;

bool next(string &s)
{
    int n = s.length() - 1;
    int i = n;
    do
    {
        i--;
    } while (i >= 0 && s[i] >= s[i + 1]);
    if (i < 0)
        return false;
    int j = n;
    while (s[j] <= s[i])
        j--;
    swap<char>(s[i], s[j]);
    i++;
    for (int j = 0; j <= (n - i + 1) / 2 - 1; j++)
        swap<char>(s[i + j], s[n - j]);
    return true;
}

int main(){

    string s;
    cin>>s;
    bool b;
    b=next(s);
    
    cout<<s;
    

}

