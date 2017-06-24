//B - Коды Грея

#include <stdio.h>
#include <string>
using namespace std;


void greyone(int n,string s);


void greyone_inverse(int n, string s1);


int main(){
    string s;
    s="";
    int n;
    scanf("%d",&n);
    greyone(n,s);
}


void greyone(int n,string s){
    
    if (n==s.length()) {
      printf("%s\n",s.c_str());
        return;
    }
    greyone(n,s+"0");
    greyone_inverse(n,s+"1");
}

void greyone_inverse(int n,string s){
    
    if (n==s.length()) {
        printf("%s\n",s.c_str());
        return;
    }
    
    greyone(n,s+"1");
    greyone_inverse(n,s+"0");
}

