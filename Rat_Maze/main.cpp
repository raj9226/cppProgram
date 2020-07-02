#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int solution[11][11];
void printsol(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<solution[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"====================================================\n";
}

void mazehelp(int maze[][3],int n,int r,int c)
{
    if(r==n-1 && c==n-1)
    {
        solution[r][c]=1;
        printsol(n);

    }
    if(r>=n || r<0 || c>=n || c<0 || solution[r][c]==1 || maze[r][c]==0)
    {
        return;
    }

    solution[r][c]=1;
    mazehelp(maze,n,r-1,c);
    mazehelp(maze,n,r+1,c);
    mazehelp(maze,n,r,c-1);
    mazehelp(maze,n,r,c+1);
    solution[r][c]=0;
}
void rat_maze(int maze[][3],int n)
{
    memset(solution,0,11*11*sizeof(int));
    mazehelp(maze,n,0,0);
}
int main()
{
    int maze[][3]={{1,1,0},{1,1,1},{1,1,1}};
    rat_maze(maze,3);
}
