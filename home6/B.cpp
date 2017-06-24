/*
 Слова без двух единиц подряд
 На вход подаётся число N — необходимо вывести число слов длины N над алфавитом {0, 1}, в которых нет двух единиц подряд. Например все такие строки длины 3:
 000, 001, 010, 100, 101
 Input format
 N – длина строки
 Output format
 M – число слов длины N без двух единиц подряд
 Examples
 Input	Output
 3
 5
*/


#include <iostream>
#include <vector>
using namespace std;

unsigned long long fib(unsigned long long n) {
    static std::vector<unsigned long long> t;
    if (n <= 1) {
        return n;
    }
    else if (n >= t.size()) {
        t.resize(n+1);
    }
    
    if (t[n] == 0) {
        t[n] = fib(n-1) + fib(n-2);
    }
    return t[n];
}
int main()
{
    unsigned long long n;
    
    cin >> n;
    cout<<fib(n+2);
    
    return 0;
}

