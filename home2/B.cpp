//
//  СoatedPoints.cpp
//  home2
//
//  Created by Roman Degtyarev on 03.10.16.
//  Copyright © 2016 Roman Degtyarev. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;


//_______________________class point________________________________
struct point{
    double x;
    bool t;//покрыт или нет
    point(){
        x=0;
        t=0;
    }
    
};


void bubble(point *x,int n){
    for(int i=0;i<n;i++)
        for(int j=i;j>0 && x[j-1].x>x[j].x;j--)
            swap(x[j-1].x,x[j].x);
};


//_______________________class stack________________________________




template <class type, unsigned size=10>
class stack{
private:
    type *a;
    int top;
public:
    
    //конструктор и деструктор______________________________________________________________________
    stack(){
        a=new type[size];
        top = 0;
    };
    
    ~stack(){
        delete[](a);
    };
    
    //функции класса______________________________________________________________________
    void push(type x);//занесение элемента в стек
    type pop();//Вытащить элемент, находящийся в вершине
    type peek();//Получить значение элемента, находящегося в вершине, не изменяя стека
    bool empty();//проверяет пуст ли стек

    
};


//перегрузка функций______________________________________________________________________




template<class type, unsigned size>
void stack<type,size>::push(type x){
    if (top>size) return;
    a[top++]=x;
}

template<class type, unsigned size>
type stack<type,size>::pop(){
    if (top<0) return 1;
    return a[--top];
    
}


template<class type, unsigned size>
type stack<type,size>::peek(){
    int temp=top;
    if (top<0) return 1;
    return a[--temp];
    
}

template<class type, unsigned size>
bool stack<type,size>::empty(){
    return (top==0);
}




//__________________________________main_________________________________________________________






int main(){
    unsigned N;//число точек
    double x;
    int number=0;
    
    ifstream in;
    in.open("B-СoatedPoints.txt");
    
    //scanf("%d",&N);
    in>>N;
    
    
    
    point *p=new point[N];//выделяем массив точек
    
    /* for (int i=0;i<N;i++){
     scanf("%lf",&x);
     p[i].x=x;
     };*/
    
    
    for (int i=0;i<N;i++){
        in>>x;
        p[i].x=x;
    };
    
    
    
    bubble(p,N);
    stack<double,1000> s;
    
    int j=0;
    
   for (int i=0;i<N;i++){//циклом проходимся по прямой
        j=i+1;
        double temp=0;//временный элемент для хранения текущего значения, относительно которого рассчитываем расстояние
        if (p[i].t==0){
            temp=p[i].x;
            s.push(p[i].x);//засовываем текущий элемент в стек
            }
            else continue;
        while(!(s.empty())){
            if(j<N){
                if(((p[j].x-temp)<=1)&&(p[j].t==0)){
                s.push(p[j].x);
                    j++;
                }
                else{
                    for(int k=i;k<j;k++){
                    s.pop();
                    p[k].t=1;
                    }
                    number++;
                    }//закрываем else
            }
            else break;
            
    
        }//закрываем цикл while
    }//закрываем цикл for
    
    
    
    printf("%d\n",number+1);
    
    

    return 0;
    }
