/*
 
 Эйлеров цикл
 Определить, существует ли в графе, содержащем N вершин, путь, содержащий все M рёбер, который проходит по каждому из них ровно один раз.
 Input format
 N M
 S1 D1
 S2 D2
 ...
 SN DN
 Output format
 YES
 или
 NO
 Examples
 Input	Output
 6 6
 1 2
 2 3
 3 1
 4 5
 5 6
 6 4
 NO
 6 6
 1 4
 2 6
 3 5
 4 2
 5 1
 6 3
 YES

 
 
 */



#include <iostream>
#include<stdlib.h>
#include<cstdio>
#include<list>
using namespace std;
list<int>adjlist[100005];
void dfs(int u,bool visited[])
{
    visited[u]=true;
    list<int>::iterator i;
    for(i=adjlist[u].begin();i!=adjlist[u].end();i++)
    {
        if(visited[*i]==false)
        {
            dfs(*i,visited);
        }
    }
}
bool is_connected(int n)
{
    bool visited[100005];
    int i;
    for( i=0;i<100005;i++)
    {
        visited[i]=false;
    }
    for (i = 1;i<=n; i++)
        if (adjlist[i].size() != 0)
            break;
    
    if (i == n)
        return true;
    dfs(i,visited);
    for(i=1;i<=n;i++)
    {
        if(visited[i]==false && adjlist[i].size()>0)
            return false;
    }
    return true;
}
bool is_eulerian(int n)
{
    if(is_connected(n)==false)
        return false;
    int odd=0;
    for(int i=1;i<=n;i++)
    {
        if(adjlist[i].size()&1)
        {
            odd++;
        }
    }
    if(odd==2||odd==0)
        return true;
    return false;
}

int main()
{
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n;i++)
        {
            adjlist[i].clear();
        }
        
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            adjlist[x].push_back(y);
            adjlist[y].push_back(x);
        }
        if(is_eulerian(n)==true)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    return 0;
}
