#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//o(m^n)
/*int minimum_cost(int** grid,int curi,int curj,int desi,int desj)
{
    if((curi==desi && curj==desj-1 )|| (curi==desi-1 && curj==desj) || (curi==desi-1&& curj==desj-1))
    {
        return grid[curi][curj]+grid[desi][desj];
    }
    if(curi>desi || curj>desj)
        return INT_MAX;
    int f=minimum_cost(grid,curi+1,curj,desi,desj);
    int s=minimum_cost(grid,curi,curj+1,desi,desj);
    int t=minimum_cost(grid,curi+1,curj+1,desi,desj);
    return grid[curi][curj]+min(f,min(s,t));


}*/
//using Dp
/*int minimum_cost2(int** grid,int curi,int curj,int desi,int desj,int **out)
{
    if(curi==desi && curj==desj )
    {
        return grid[desi][desj];
    }
    if(curi>desi || curj>desj)
        return INT_MAX;
    if(out[curi][curj]!=-1)
        return out[curi][curj];
    int f=minimum_cost2(grid,curi+1,curj,desi,desj,out);
    int s=minimum_cost2(grid,curi,curj+1,desi,desj,out);
    int t=minimum_cost2(grid,curi+1,curj+1,desi,desj,out);
    out[curi][curj]= grid[curi][curj]+min(f,min(s,t));
    return out[curi][curj];


}*/
//Iteratively
int minimum_cost3(int **grid,int n)
{
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
        dp[i]=new int[n];
    dp[n-1][n-1]=grid[n-1][n-1];

    for(int i=n-2;i>=0;i--)
        dp[i][n-1]=dp[i+1][n-1]+grid[i][n-1];

    for(int j=n-2;j>=0;j--)
    {
        dp[n-1][j]=dp[n-1][j+1]+grid[n-1][j];
    }

    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            dp[i][j]=grid[i][j]+min(dp[i][j+1],min(dp[i+1][j+1],dp[i+1][j]));
        }
    }
    int out= dp[0][0];
    for(int i=0;i<n;i++)
    {
        delete [] dp[i];
    }
    delete []dp;
    return out;

}
int main()
{
    int n;
    cin>>n;
    int **grid=new int*[n];
    for(int i=0;i<n;i++)
        grid[i]=new int[n];
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>grid[i][j];
            }
        }
    /*int **out=new int*[n];
    for(int i=0;i<n;i++)
        out[i]=new int[n];
    memset(out,-1,n*n*sizeof(int));
    //cout<<minimum_cost(grid,0,0,n-1,n-1)<<endl;
    cout<<minimum_cost2(grid,0,0,n-1,n-1,out)<<endl;
    */
    cout<<minimum_cost3(grid,n);



}
