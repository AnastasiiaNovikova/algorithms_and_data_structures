#include<iostream>
#include<cstdlib>



using namespace std;
int main()
{
    int number;
    int x;
    int max=0;
    
    scanf("%d", &number);
    int *m=new int[10000000];
    for(int idx=0;idx<number;idx++){
        scanf("%d", &x);
        if(m[x])m[x]=x;
        else m[x]=1;
        
        if (x>max){ max=x;}
    };
    
    if (m[max]==max) {
        cout<<max;
        delete[](m);
        return 0;
        
    };
    
    for (int i=(max-1); i>=0; i--){
        if(m[i]) {
            cout<<i;
            break;
        
        }
    }
    
    delete[](m);
    return 0;
}
