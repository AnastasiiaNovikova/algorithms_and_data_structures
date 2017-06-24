/*
 На вход подаются числа N, M ≤ 105 и последовательности целых чисел x и y длины N и M соотвествтенно. Необходимо проверить, является ли последовательность y подпоследовательностью последовательности x.
 Input format
 N
 M
 x1 x2 ... xN
 y1 y2 ... yM
 Output format
 yes/no
 Examples
 Input	Output
 3
 2
 0 1 2
 0 2
 yes
 */
 

#include <iostream>
#include <vector>
using namespace std;

void res(vector<int>&A, vector<int>&B){
    int a = A.size()-1;int b = B.size()-1;
    while ((a >= 0) && (b >= 0)){
        if (A[a] == B[b]){a--;b--;}
            else a--;
    }
    if (b == -1) {cout<<"yes"; return;}
    cout<<"no";
    return;
}

int main(){
    int a,b=0;
    cin>>a>>b;
    vector <int> A(a);
    vector <int> B(b);
    for (int i=0;i<a;i++)cin>>A[i];
    for (int i=0;i<b;i++)cin>>B[i];
    res(A,B);
    return 0;
}
