/*
 
 Верёвочки
 В ось X вбито N гвоздей. Требуется соединить эти гвозди верёвочками так, чтобы у каждого гвоздя была хотя бы одна верёвочка и чтобы сумма всех верёвочек была минимальной.
 2 <  = N <  = 10000  - 40000 <  = Xi <  = 40000
 Пример: для данных
 4
 5 3 8 9
 ответом будет 3, так как соединяются 5 и 3 а также 8 и 9.
 Input format
 N
 X1
 X2
 ...
 XN
 Output format
 Result
 Examples
 Input	Output
 4
 5 3 8 9
 3
 */


#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin>> N;
    int *a = new int[N];
    for (int i = 0; i < N; i++)
        cin>> a[i];
    sort(a, a + N);
    if (N == 2 || N == 3) {
        cout << a[N - 1] - a[0];
    } else {
        int *b = new int[N - 1];
        b[0] = a[1] - a[0];
        b[1] = a[2] - a[0];
        for (int j = 2; j < N - 1; ++j)
            b[j] = std::min(b[j - 1], b[j - 2]) + a[j + 1] - a[j];
        cout << b[N - 2];
        delete []b;
    }
    delete []a;
}
