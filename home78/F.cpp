/*
 
 Одноколейная железная дорога
 В стране начали строить железную дорогу, но в процессе постройки деньги внезапно кончились, из-за чего строительство было прервано, а через пару лет опять внезапно появились, из-за чего строительство решили возобновить, но с меньшим размахом. Успели построить только одноколейные дороги (дороги в одну сторону из пункта A в пункт B), при этом если из города A можно попасть в город B, то обратно по системе железных дорог попасть нельзя. Необходимо добавить минимальное число дорог так, чтобы из любого города можно было добраться до другого.
 Input format
 N ≤ 1000 – число городов
 N строк вида
 ai, 1 ai, 2 ... ai, N, где ai, j = 1, если из города i есть дорога в город j, иначе ai, j = 0
 Output format
 M – число дорог, которое необходимо добавить.
 Examples
 Input	Output
 4
 0 1 1 0
 0 0 1 0
 0 0 0 1
 0 0 0 0
 1
 */
#include <string>
#include <iostream>
using namespace std;



int main() {
    int N;
    scanf("%d", &N);
    int sum_str = 0;//is_visited
    int sum_stlb = 0;//n_visited
    bool *stlb = new bool[N];//visited
    memset(stlb, 0, sizeof(bool)*N);
    for (int i = 0; i < N; ++i) {
        bool sum = 0;//number_of_result_verticles
        for (int j = 0; j < N; ++j) {
            int tmp;//new_edge
            scanf("%d", &tmp);
            stlb[j] = stlb[j] | tmp;
            sum = sum | tmp;
        }
        sum_str += sum;
    }
    for (int i = 0; i < N; ++i) {
        sum_stlb += stlb[i];
    }
    printf("%d", std::max(N-sum_stlb, N-sum_str));
    delete[] stlb;
    return 0;
}
