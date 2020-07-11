#include <iostream>
#include<list>
using namespace std;
/*Graph can be implemented using
1.Linked list*/
//not very good for getting neighbour generally used in krushkal's algo
/*
class Graph
{
    int V;
    list<pair<char,char>>ll;
public:
    Graph(int v)
    {
        V=v;
    }
    void Edge(char u,char v)
    {
        ll.push_back(make_pair(u,v));
    }
    void printG()
    {
        for(auto edge:ll)
        {

            cout<<edge.first<<" "<<edge.second<<endl;
        }
    }
} ;*/

//Matrix representation
#include<bits/stdc++.h>
/*
int g[20][20];
void egde(int u,int v,bool undirected=true)
{
    g[u][v]=1;
    if(undirected)
        g[v][u]=1;

}
void printg(int V)
{
    for(int i=0;i<V;i++)
    {

        for(int j=0;j<V;j++)
        {

            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}
*/
//Adjacency list
/*Representation for integer tree*/
/*
class Graph
{
    int V;
public:
    list<int>* adjlist;
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
    void printg()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"-> ";
            for(auto node:adjlist[i])
                cout<<node<<" ";
            cout<<endl;
        }
    }
};*/

//Weighted cities graph
#include<map>
#include<string>
template<typename T>
class Graph
{
public:
    map<T,list<T>>adjlist;
    void edge(T u,T v,bool bidir=true)
    {
        adjlist[u].push_back(v);
        if(bidir)
            adjlist[v].push_back(u);

    }
    void printg()
    {
        for(auto row:adjlist)
        {
            cout<<row.first<<"->";
            for(T element:row.second)
                cout<<element<<" ,";
            cout<<"\n";
        }
    }
} ;
int main()
{
    //int V;
    //cin>>V;
    /*for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            g[i][j]=0;
        }
    }*/
    //Graph g(V);
    Graph<string> g;
    g.edge("Amritsar","Delhi");
    g.edge("Amritsar","Agra");
    g.edge("Delhi","Mumbai");
    g.edge("Delhi","Agra");
    g.edge("Agra","Mumbai");
    g.printg();
    return 0;
}
