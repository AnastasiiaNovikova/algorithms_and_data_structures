/*
 Компоненты сильной связности
 На вход подаётся описание ориентированного графа — необходимо найти число его компонент сильной связности. Компонентой сильной связности называется максимальное по включению множество вершин, каждые две вершины которого достижимы друг из друга.
 Input format
 N ≤ 1000 – число вершин
 N строк вида
 ai, 1 ai, 2 ... ai, N, где ai, j = 1, если в графе есть ребро из вершины i в вершину j.
 Output format
 M – число компонент сильной связности
 Examples
 Input	Output
 3
 0 1 1
 1 0 1
 0 0 0
 2

 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <vector>
using namespace std;

vector<int> result;
int k=0;
vector <string>s;

class Graph
{
    int V;
    list<int> *AdList;
    
    void DFSwithStack(int V, bool visited[], stack<int>	&Stack);
    void DFS(int &V, bool visited[]);
    
public:
    Graph(int v);
    void AddEdge(int V, int E);
    
    void SSC(int S);
    Graph getTranspose();
};

Graph::Graph(int v)
{
    this->V = v;
    this->AdList = new list<int>[v];
}

void Graph::AddEdge(int V, int E)
{
    AdList[V].push_back(E);
}

void Graph::SSC(int S)
{
    bool *visited = new bool[V];
    memset(visited, 0, V);
    
    stack<int>	Stack;
    
    for(int v=0; v<V; v++)
        if( !visited[v])
            DFSwithStack(v, visited, Stack);
    
    Graph G = getTranspose();
    
    memset(visited, 0, V);
    
    while ( !Stack.empty())
    {
        
        int v = Stack.top();
        Stack.pop();
        
        if ( !visited[v])
            G.DFS(v, visited);
        
        //cout<<endl;
        s.push_back("-");
        
    }
}


Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        list<int>::iterator i;
        for(i = AdList[v].begin(); i != AdList[v].end(); ++i)
        {
            g.AdList[*i].push_back(v);
        }
    }
    return g;
}


void Graph::DFSwithStack(int V, bool visited[], stack<int>	&Stack)
{
    visited[V] = true;
    
    list<int> :: iterator i;
    for(i = AdList[V].begin(); i!= AdList[V].end(); i++)
    {
        if( !visited[*i] )
            DFSwithStack(*i, visited, Stack);
    }
    
    Stack.push(V);
}
int sqp=0;
void Graph::DFS(int &V, bool visited[])
{
    k++;
    visited[V] = true;
    
    s.push_back("+");
    //cout<<V<<' ';
    sqp=V;
    
    list<int> :: iterator i;
    for(i = AdList[V].begin(); i!= AdList[V].end(); i++)
    {
        if( !visited[*i] )
            DFS(*i, visited);
    }
}


int main()
{
    int p=0;
    int n;
    
    cin>>n;
    Graph G(n);
    int x;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>x;
            if (x==1){
                G.AddEdge(i, j);
                
            }
            
        }
    }
    
    int result=0;
    
    G.SSC(result);
    
    bool state=false;
    
    for (int i;i<s.size();i++){
        if(s[i]=="+") {
            state=true;
            continue;
        };
        if ((s[i]=="-") && (state==true)){
            state=false;
            p++;
        }
        
    }
   cout<<n-sqp<<endl;
    
    
    
    return 0;
}
