#include <iostream>
#include<list>
#include<queue>
using namespace std;
/*Given a graph if we burn a fire at the 0th node find minimum time
taken by the fire to reach at every node,if it take only 1 sec.
to catch fire from one node to another*/
//This problem can be solved using the bfs since the bfs gives the shortest path in a graph

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
    void edge(int u,int v,bool bidir=true)
    {
        adjlist[u].push_back(v);
        if(bidir)
            adjlist[v].push_back(u);

    }
    void fire(int src)
    {
        queue<int>q;
        bool *visited=new bool[V]{0};
        int *time=new int[V];
        q.push(src);
        visited[src]=true;
        time[src]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int neighbour:adjlist[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                    time[neighbour]=time[node]+1;
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            cout<<"Time taken to reach at node "<<i<<" is "<<time[i]<<endl;
        }
        cout<<"\nThe shortest path is: ";
        for(int i=0;i<V-1;i++)
        {
            if(time[i]!=time[i+1])
            {
                cout<<i<<"->";
            }

        }
        cout<<V-1;
    }


 };
int main()
{
    Graph g(5);
    g.edge(0,1);
    g.edge(0,2);
    g.edge(1,2);
    g.edge(1,3);
    g.edge(2,3);
    g.edge(3,4);
    g.fire(0);
    return 0;
}
