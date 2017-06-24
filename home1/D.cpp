//
//  set.cpp
//  home1
//
//  Created by Roman Degtyarev on 25.09.16.
//  Copyright © 2016 Roman Degtyarev. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<cstdlib>
#include <set>
using namespace std;

int main(){
    set <int> set;
    int k=0;
    int x;
    pair<std::set<int>::iterator,bool> ret;
    
    while(k!=2){
        
        scanf("%d", &x);
        if (x==0) k++;
        ret=set.insert(x);
        if (ret.second == false) set.erase(x);
        
        
    };
    
    if (set.size()==0) cout<<0;
        else{
            for (const auto &i:set)
            {
                cout << i << ' ';
            };
        };
    
    return 0;
}
