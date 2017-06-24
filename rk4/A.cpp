/*
 Наибольшее расстояние
 Имеется ориентированный взвешенный граф из N вершин, представленный матрицей смежности C[N][N], положительные элементы которой Cij представляют веса связей i-й и j-й вершин.
 Найти наибольшее из кратчайших расстояний между всеми достижимыми парами вершин.
 Гарантируется, что ответ не превышает 109.
 Input format
 N
 C11 C12 ... C1N
 C21 C22 ... C2N
 ...
 CN1 CN2 ... CNN
 Output format
 MaximumShortestPath
 Examples
 Input	Output
 4
 0 5 9 0
 0 0 2 8
 0 0 0 7
 4 0 0 0
 16
 
 */

#include <iostream>
#include <vector>
using namespace std;
int n=0;
int max_pass=0;
void floyds(vector<vector<int> > &b)
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((b[i][k] * b[k][j] != 0) && (i != j))
                {
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                    {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (b[i][j]>max_pass)max_pass=b[i][j];
        }
        
    }
}
int main()
{
    cin>>n;
    vector<vector<int> > w(n);
    for (int i=0;i<n;i++){
        w[i].resize(n);
        for (int j=0;j<n;j++){
            cin>>w[i][j];
        }
    }
    floyds(w);
    cout<<max_pass<<endl;
}
