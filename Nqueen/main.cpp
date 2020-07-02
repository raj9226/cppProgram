#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int board[11][11];
bool isplace(int n,int row,int col)
{
    for(int i=row-1;i>=0;i--)
    {
        if(board[i][col]==1)
            return false;
    }
    // upper left diagonal
    for(int j=row-1,k=col-1 ;j>=0 && k>=0;j--,k--)
    {
        if(board[j][k]==1)
            return false;
    }

    //upper right diagonal
    for(int j=row-1, k=col+1;j<n&& k<n;j++,k++)
    {
        if(board[j][k]==1)
            return false;
    }
    return true;
}
void nqueenHelper(int n,int row)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"===========================================================================\n";
        return;
    }

    for(int j=0;j<n;j++)
    {
        if(isplace(n,row,j))
        {
            board[row][j]=1;
            nqueenHelper(n,row+1);
            board[row][j]=0;
        }
    }
    return;
}
void placeQueen(int n)
{
    memset(board,0,11*11*sizeof(int));
    nqueenHelper(n,0);


}
int main()
{
    int n;
    cin>>n;
    placeQueen(n);
}
