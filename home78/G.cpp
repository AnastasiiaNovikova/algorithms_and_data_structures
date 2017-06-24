/*
 
 Двудольный граф
 Двудольный граф — неориентированный граф, множество вершин которого можно разбить на два непустых подмножества таких, что не существует рёбер, соединяющих пару вершин, принадлежащих одному подмножеству.
 Задан неориентированный граф с N вершинами и M рёбрами. Требуется определить, является ли он двудольным.
 Input format
 N M
 U1 V1
 U2 V2
 ...
 UN VN
 Вершины нумеруются с 0.
 Output format
 YES или NO
 Examples
 Input	Output
 4 4
 0 1
 1 2
 2 3
 3 0
 YES
 4 4
 0 1
 1 2
 2 3
 0 2
 NO

 */


#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int INF = 1e9;
typedef vector<int> vi;

vector<vi> AdjList;
vi color;
bool isBipartite;

void dfs(int u, int clr){
    color[u] = clr;
    for(int i = 0; isBipartite && i < (int)AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if(color[v] == INF)
            dfs(v, 1 - clr);
        else if(color[u] == color[v]){
            isBipartite = false;
            break;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
        AdjList.assign(n, vi());
        color.assign(n, INF);

    
    
        int m;
        scanf("%d", &m);
        while(m--){
            int a, b;
            scanf("%d %d", &a, &b);
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        
        isBipartite = true;
        for(int i = 0; i < n && isBipartite; i++){
            if(color[i] == INF){
                dfs(i, 0);
            }
        }
        
        
        if(isBipartite)
            printf("YES\n");
        else
            printf("NO\n");
    return 0;
}
