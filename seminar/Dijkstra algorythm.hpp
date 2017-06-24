//
//  Dijkstra algorythm.hpp
//  prepare
//
//  Created by Roman Degtyarev on 20.09.16.
//  Copyright © 2016 Roman Degtyarev. All rights reserved.
//

#ifndef Dijkstra_algorythm_hpp
#define Dijkstra_algorythm_hpp
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
#define SIZE2 5

void dij(){
    
    int a[SIZE][SIZE2]; // матрица связей
    int d[SIZE]; // минимальное расстояние
    int v[SIZE]; // посещенные вершины
    int temp;
    int minindex, min;
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE2;j++) {
            printf("Введите расстояние %d - %d: ", i+1, j+1);
            scanf("%d",&temp);
            a[i][j] = temp;
        }
    }
    // Вывод матрицы связей
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE2;j++)
            printf("%5d ",a[i][j]);
        printf("\n");
    }
    //Инициализация
    for(int i=0;i<SIZE;i++) {
        d[i] = 10000;
        v[i] = 1;
    }
    d[0] = 0;
    // Шаг алгоритма
    do {
        minindex = 10000;
        min = 10000;
        for(int i=0; i<SIZE;i++) {
            if((v[i] == 1) && (d[i]<min)) {
                min = d[i];
                minindex = i;
            }
        }
        if(minindex != 10000) {
            for(int i=0;i<SIZE2;i++) {
                if(a[minindex][i] > 0) {
                    temp = min+a[minindex][i];
                    if(temp < d[i])
                        d[i] = temp;
                }
            }
            v[minindex] = 0;
        }
    } while(minindex < 10000);
    // Вывод матрицы связей
    for(int i=0;i<SIZE;i++)
        printf("%5d \n",d[i]);
    getchar(); getchar();

}


#endif /* Dijkstra_algorythm_hpp */
