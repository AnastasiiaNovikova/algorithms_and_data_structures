//
//  functions.hpp
//  prepare
//
//  Created by Roman Degtyarev on 14.09.16.
//  Copyright © 2016 Roman Degtyarev. All rights reserved.
//

#ifndef sort_hpp
#define sort_hpp

#include <stdio.h>
void swap(int *a, int *b){
    int *temp=0;
    temp=a;
    a=b;
    b=temp;
    
};


void bubble(int *p,int n){
    for (int i=1;i<=n; i++){
        for (int j=0;j<i;j++){
            if (*(p+j)<=*(p+i)){
                int temp=0;
                temp=*(p+j);
                *(p+j)=*(p+i);
                *(p+i)=temp;
            };
        };
        
    };
};

void show(int *p,int n){
    for (int i=0;i<=n;i++){
        
        cout<<*(p+i)<<' ';
    };
    
};




void insert_sort(int *a,int size){
    int tmp;
    for(int i=1,j;i<=size;i++){
        tmp=a[i];
        for (j=i-1; a[j]>tmp && j>=0; --j) a[j+1]=a[j];
        
        a[j+1]=tmp;
    };
};


#endif /* functions_hpp */
