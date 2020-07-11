#include <iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{
    int V;
public:
    list<int>*adjlist;
    Graph(int v)
    {
        V=v;
        adjlist=new list<int>[V];
    }
    void egde(int u,int v,bool bidir=true)
    {
        adjlist[u].push_back(v);
        if(bidir)
            adjlist[v].push_back(u);
    }
    void bfs(int src)
    {
        queue<int>q;
        bool *visited=new bool[V]{0};
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            int node=q.front();
            cout<<node<<" ";
            q.pop();
            for(int neighbour:adjlist[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    }
};
int main()
{
    Graph g(6);
    g.egde(0,1);
    g.egde(0,4);
    g.egde(1,2);
    g.egde(2,4);
    g.egde(2,3);
    g.egde(3,4);
    g.egde(3,5);
    g.bfs(0);
    return 0;
}
