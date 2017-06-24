/*
 Кввдрат из единиц
 Дана матрица размера N × N, состоящая из нулей и единиц.
 Найти наибольшую квадратную подматрицу, состоящую из единиц.
 Input format
 
 N
 A11 A12 A13 ... A1N
 A21 A22 A23 ... A2N
 ...
 AN1 AN2 AN3 ... ANN
 N < 10000
 
 Output format
 GreatestSubmatrixSize
 
 Examples
 Input	Output
 5
 0 1 1 0 1
 1 1 1 1 1
 1 1 1 1 1
 1 1 1 1 1
 1 0 0 0 0
 3

 */


#include <vector>
#include <iostream>
using namespace std;


int main ()
{
    int n;
    cin>>n;
    vector < vector<int> > a (n, vector<int> (n));
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < n; ++j )
            cin>>a[i][j];
    int ans = 0;
    int temp=0;
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < n; ++j )
        {
            if ( i && j )
            {
                if ( a[i][j] == 1 )
                {
                    temp= a[i][j - 1]<a[i - 1][j]?a[i][j - 1]:a[i - 1][j];
                    temp =temp<a[i - 1][j - 1]?temp:a[i - 1][j - 1];
                    a[i][j] = temp + 1;
                }
                if ( a[i][j] > ans )
                { ans = a[i][j]; }
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
