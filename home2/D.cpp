#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
#include <iostream>


string rec1(int N){
if (N==1) return "()";
    return "("+rec1(N-1)+")";

}

string rec2(int N){
  if (N==1) return "()";
    return "()"+rec2(N-1);
    
}




int main()
{
    int k;
    int p;
    int N;
    cin>>N;
    string s=rec1(N);
    string s2=rec2(N);
    
    
   int n = (int) s.length();
    string ans = "No solution";
    
    while(s2!=ans){
        
    for (int i=n-1, depth=0; i>=0; --i) {
        if (s[i] == '(')
            --depth;
        else
            ++depth;
        if (s[i] == '(' && depth > 0) {
            --depth;
            int open = (n-i-1 - depth) / 2;
            int close = n-i-1 - open;
            ans = s.substr(0,i) + ')' + string (open, '(') + string (close, ')');
            p++;
            break;
        }
    }
        
        k++;
        s=ans;
        
    }
    
    cout<<p+1<<endl;
    
}
