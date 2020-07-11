#include <iostream>

using namespace std;
void dfs(int **matrix,bool *visted,int v,int src)
{
    cout<<src<<" ";
    visted[src]=true;
    for(int i=0;i<v;i++)
    {
        if(matrix[src][i]==1)
        {
            if(visted[i])
                continue;
            dfs(matrix,visted,v,i);
        }
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    int **matrix=new int*[v];
    for(int i=0;i<v;i++)
    {
        matrix[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            matrix[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        matrix[f][s]=1;
        matrix[s][f]=1;
    }
    bool *visted=new bool[v]{0};
    dfs(matrix,visted,v,0);

    return 0;
}
