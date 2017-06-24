//
//  stack.hpp
//  prepare
//
//  Created by Roman Degtyarev on 21.09.16.
//  Copyright © 2016 Roman Degtyarev. All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <cstdlib>//нужно для exit(1); по сути завершает программу с предупреждением.


char * resize(const char * str,unsigned size,unsigned new_size ){
    char * new_field=new char[new_size];
    int true_size=(size<new_size ? size: new_size);
    for (int i=0;i<true_size;i++){
        new_field[i] = str[i];
    };
    delete[] str;
    return new_field;
    
};




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
    void show_back();//показ всех элементов в обратном порядке
    void show_straight();//показ всех элементов в прямом порядке
    void push(type x);//занесение элемента в стек
    type * resize(const type *old);//увеличение памяти с сохранением текущего стека.
    type pop();//Вытащить элемент, находящийся в вершине
    type peek();//Получить значение элемента, находящегося в вершине, не изменяя стека
    bool empty();//проверяет пуст ли стек
    void destroy();
    unsigned ssize();//возвращает размер стека
    bool right_bracket();//правильная ли скобочная последовательность?
    
    
    //операторы класса______________________________________________________________________
    type operator=(type x);
    type &operator[](int index);
    
};

//перегрузка операторов______________________________________________________________________
template<class type, unsigned size>
type &stack<type,size>::operator[](int index){

    if (index<0 && index>size) exit(1);
    else return a[index];
}



template<class type, unsigned size>
type stack<type,size>::operator=(type x){
    a=x;
    return *this;
}


//перегрузка функций______________________________________________________________________
template<class type, unsigned size>
unsigned stack<type,size>::ssize(){
    return top;

};

template<class type, unsigned size>
bool stack<type,size>::right_bracket(){
    static int length=top-1;
    static int i=0;
    if ((a[i]=='(') && a[length]==')'){
        i++;
        length--;
        return right_bracket();
    }
    return ((length+1)==i);
    
}


template<class type, unsigned size>
void stack<type,size>::show_back(){
    if (top==0) cout<<"Стек пуст"<<endl;
    else{
        cout<<endl;
    for (int i=top-1;i>=0;i--){
        cout<<a[i]<<' ';
    };
    }
}

template<class type, unsigned size>
void stack<type,size>::show_straight(){
    if (top==0) cout<<"Стек пуст"<<endl;
    else{
        cout<<endl;
        for (int i=0;i<top;i++){
            cout<<a[i]<<' ';
        };
    }
}


template<class type, unsigned size>
type * stack<type,size>::resize(const type *old){
    static int counter=0;
    counter++;
    unsigned new_size=size*counter;
    type * new_field=new type[new_size];
    for (int i=0;i<size;i++){
        new_field[i] = old[i];
    };
    delete[] old;
    return new_field;
    
}

template<class type, unsigned size>
void stack<type,size>::push(type x){
    if (top>size) a=resize(a);
    a[top]=x;
    top++;
}

template<class type, unsigned size>
type stack<type,size>::pop(){
    --top;
    if (top<0) exit(1);
    return a[top];

}

template<class type, unsigned size>
type stack<type,size>::peek(){
    int temp=top;
    if (top<0) exit(1);
    return a[--temp];
    
}

template<class type, unsigned size>
bool stack<type,size>::empty(){
    cout<<top;
    return (top==0);
}


#endif /* stack_hpp */
