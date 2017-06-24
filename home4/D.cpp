/*
 Submit a solution for D-Повторяющаяся строка
 Time limit:	2 s
 Real time limit:	5 s
 Memory limit:	64M
 Повторяющаяся строка
 Была исходная строка длины 2 ≤ L ≤ 150000. К ней многократно приписали её же справа и из полученной строки в произвольном месте вырезали фрагмент. Нужно найти наименьшую из возможных длину исходной строки.
 Input format
 S
 S.size() <= 150000
 Output format
 L
 Examples
 Input	Output
 dabcdab
 4

 
 */



#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function (string s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}


int main(){
    string s;
    int m=0;
    vector <int> res;
    int *arr=new int [256];
    
    for (int i=0;i<256;i++ ){arr[i]=0;}
    cin>>s;
    
    for(int i=0;i<s.length();i++)arr[(int)s[i]] += 1;
    
    res=prefix_function(s);
        
    m=res[res.size()-1];
    
   cout<<s.length()-m<<endl;
        

    
    return 0;
}
