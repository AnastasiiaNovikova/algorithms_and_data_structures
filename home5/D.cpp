#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 Подстроки
 Входной файл состоит из одной строки I, содержащей малые буквы английского алфавита.
 Назовём подстрокой длиной L с началом S множество непрерывно следующих символов строки.
 Например, строка
 
 abcab
 содержит подстроки
 
 длины 1: a, b, c, a, b
 длины 2: ab, bc, ca, ab
 длины 3: abc, bca, cab
 длины 4: abca, bcab
 длины 5: abcab
 
 В строках длины 1 есть два повторяющихся элемента - a и b. Назовём весом подстрок длины L произведение максимального количества повторяющихся подстрок этой длины на длину L.
 В нашем случае вес длины 1 есть 2 (2·1), длины 2 есть 4 (2·2), длины 3 - 3 (1·3), длины 4 - 4 и длины 5 - 5.
 Требуется найти наибольший из всех весов различных длин.
 Input format
 Output format
 Examples
 Input	Output
 aabaabaabaabaa
 24
 abcab
 5

 */


#include<stdio.h>
#include<string.h>


#define d 256



int search(string &pat, string &txt, int q)
{
    int k=0;
    int M = pat.size();
    int N = txt.size();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    

    for (i = 0; i < M-1; i++)
        h = (h*d)%q;
    

    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }

    for (i = 0; i <= N - M; i++)
    {
 
        if ( p == t )
        {
 
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
            

            if (j == M)
                k++;
        }
        

        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
            

            if (t < 0)
                t = (t + q);
        }
    }
    return k;
}

int main()
{
    int max = 0;
    string text;
    string pattern;
    int q = 101;
    cin>>text;
    for (int i=0;i<text.size();i++){
        pattern=text.substr(i);
        if (search(pattern, text, q)*pattern.size()>max)
            max=search(pattern, text, q)*pattern.size();
        
    }
    //char txt[] = "aabaabaabaabaa";
    //char pat[] = "aabaabaa";
    cout<<max<<endl;
    return 0;
}
