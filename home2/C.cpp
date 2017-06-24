//
//  C-Sliyanie2try.cpp
//  home2
//
//  Created by Roman Degtyarev on 04.10.16.
//  Copyright © 2016 Roman Degtyarev. All rights reserved.
//

#include <stdio.h>
const int MAX=999999999;

#include <iostream>
using namespace std;

int main(){
    int N=0;
    int *a,*b;
    int x=0;
    int sum=0;
    int size_a=0;
    int size_b=0;
    scanf("%d", &N);
    a=new int[N];
    b=new int[N];
    size_a=size_b=0;


    
 for(int i=0;i<N;i++){
     scanf("%d",&x);
        a[i]=x;
   };
    for(int i=0;i<N;i++){
        scanf("%d",&x);
        b[i]=x;
    };

    
    bool size1=false;
    bool size2=false;
    
    while((size_a+size_b)<2*N){
        if ((size_a<N)&&(size1==false)){
            if (a[size_a]<=b[size_b]){
                if (((size_a+size_b+1)%2)!=0){
                    sum+=a[size_a];
                    size_a++;
                }
                else size_a++;
            }
        }
        else size1=true;
            
            
        if ((size_b<N)&&(size2==false)){
            if (b[size_b]<=a[size_a]){
                if (((size_a+size_b+1)%2)!=0){
                    sum+=b[size_b];
                    size_b++;
                }
                else size_b++;
            }
        }
        else size2=true;
    
    }
    
    delete [](a);
    delete [](b);
    
    if (sum>MAX){
        sum=sum&1000000000;
        printf("%d",sum);
    }
    
    else printf("%d",sum);
    
    
    


    return 0;
}
