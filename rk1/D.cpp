//D-Два массива

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int main(){
    queue<int> q;
    int x=0;
    int m=0;//максимальный элемент
    int m_s=0;//максимальное произведение
    
    for (int i=0;i<8;i++){
        cin>>x;
        q.push(x);
    }
    
    while(1){
         cin>>x;
        if (x<0) break;
        m= max(q.front(),m);
        
        m_s=max(m_s,m*x);
        
        q.pop();
        q.push(x);
    }
    
    cout<<m_s<<endl;
    
    
    return 0;
}
