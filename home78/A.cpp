/*
 Игра выведи фишку
 Два игрока играют в следующую игру. На поле из N + 1 × N + 1 клетки (нумерация клеток от 0 до N) в клетке (0, 0) стоит фишка. Её разрешено разрешено двигать из клетки (x, y) в клетку с координатами (x + ai, y + bi), где пары (ai, bi) обговорены перед началом игры. Выигрывает тот игрок, который вывел фишку первым в клетку, которая находится на расстоянии не менее чем R от (0, 0). Необходимо определить кто из игроков выигрывает, при безошибочных действиях соперника. Игроки ходят по очереди, пропускать ход нельзя.
 Input format
 N ≤ 300 – граница поля
 R ≤ 300 – минимальное расстояние на которое нужно вывести фишку
 M ≤ 30 – число допустимых ходов
 a1 b1
 a2 b2
 ...
 aM bM
 0 ≤ ai, bi ≤ 1000
 Output format
 1 или 2
 Examples
 Input	Output
 5
 5
 3
 1 2
 2 1
 1 1
 1
 
 */


#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

struct Point
{
    int x;
    int y;
    Point(int _x,int _y){
        x=_x;
        y=_y;
    
    }
    Point(){
        x=0;
        y=0;
        
    }
};

bool wrong(Point one,int R)
{
    return ((one.x)*(one.x) + (one.y)*(one.y))>R*R;
}


int res(vector<vector<int> > &w, int x,int y, vector<Point> &step, int R, int M)
{
    Point temp(x,y);
    if (wrong(temp,R))return -1;
    if (w[temp.x][temp.y] != 0) return w[temp.x][temp.y];
    for (int i = 0; i < M; i++)
    if (res(w, temp.x + step[i].x,temp.y + step[i].y, step, R, M) == -1) return w[temp.x][temp.y]= 1;
    w[temp.x][temp.y] = -1;
    return -1;
}

int main()
{
    int N, R, M;
    scanf("%d %d %d",&N,&R,&M);
    vector<Point> step(M);
    for (int i = 0; i < M; ++i)
    {
        scanf("%d %d",&(step[i].x),&(step[i].y));
    }
    vector<vector<int> > w(N+1);
    for (int i=0;i<=N;i++){
        w[i].resize(N+1);
        for (int j=0;j<=N;j++){
            w[i][j]=0;
        }
    }
    if (res(w, 0,0, step, R, M) != 1) printf("2\n");
    else printf("1\n");
    return 0;
}

