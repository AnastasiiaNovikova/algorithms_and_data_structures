/*Расстояние редактирования
 На вход подаются два слова длины не более 1000, необходимо найти расстояние редактирования между ними. Расстояние редактирования определяется следующим образом: два слова записывают одно под другим и добиваются их выравнивания путём добавления разделителя использование разделителя и несовпадение двух букв в одной позиции считается за штраф, — таким образом, расстояние редактирования — это минимальная величина штрафа.
 Пример
 S - N O W Y
 S U N - N Y
 Input format
 первое слово второе слово
 Output format
 расстояние редактирования
 Examples
 Input	Output
 sunny
 snowy
 3

*/

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in, out;
    cin>>in;
    cin>>out;
    
    const int n = in.size(), m = out.size();
    
    int** D = new int*[2];
    D[0] = new int[n+1];
    D[1] = new int[n+1];
    int currRow = 0;
    int absRowCount = 1;
    for (int i = 0; i < n + 1; ++i)
    {
        D[currRow][i] = i;
    }
    
    for(int i = 1; i < m + 1; ++ i)
    {
        currRow = (currRow + 1) % 2;
        D[currRow][0] = i;
        for (int j = 1; j < n + 1; ++j)
        {
            D[currRow][j] = min(
                                D[(currRow + 1) % 2][j] + 1,
                                min(
                                    D[currRow][j - 1] + 1,
                                    D[(currRow + 1) % 2][j-1] + (int)(in[j-1] != out[i-1])
                                    )
                                );
        }
    }
    
    cout << D[currRow][n];
    //system("pause");
    return 0;
}
