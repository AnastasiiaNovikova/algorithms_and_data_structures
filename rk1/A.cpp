//A - Далёкие произведения
#include <stdio.h>
#include <queue>

using namespace std;
int main(){
    int N1,N2;
    int x;
    scanf("%d %d", &N1,&N2);
    queue<int> a;
    
    for (int i=0;i<N1;i++){
        scanf("%d",&x);
        a.push(x);
    }
    
    
    int k=0;
    for (int i=0;i<N2;i++ ){
        scanf("%d",&x);
        while(!(a.empty())&&(a.front()<x))a.pop();
        if (!(a.empty())&&(a.front()==x)){
            k++;
            a.pop();
        }
    }
    
    printf("%d\n", k);
    
    return 0;
}
