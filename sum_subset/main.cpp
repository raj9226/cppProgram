#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//naive approach ie exponential
/*
bool sumexist(int *arr,int n,int i,int s)
{
    int sum=0;
    int j=n-1;
    while(i>0)
    {
        if(i&1)
        {
            sum+=arr[j];
            j--;
            i=i>>1;
        }
        else
        {
            j--;
            i=i>>1;
        }
        if(sum==s)
        {
            return true;
            break;
        }


    }
    return false;
}
bool ispossible(int *arr,int n,int s)
{
    int range=(1<<n)-1;
    for(int i=0;i<=range;i++)
    {
        if(sumexist(arr,n,i,s))
            return true;
    }
    return false;
}
*/

/*Method 2: Using recursion*/
//same as knapsack problem
/*int ispossible(int *arr,int n,int s)
{
    if(s==0)
        return 1;
    if(n==0)
            return 0;
    else
    {
        int ans=ispossible(arr,n-1,s);
        if(arr[n-1]<=s)
            ans=ans|| ispossible(arr,n-1,s-arr[n-1]);
        return ans;
    }
}*/
//using dp
/*
int ispossible(int *arr,int n,int s)
{
    int dp[n+1][s+1];
    memset(dp,-1,(n+1)*(s+1)*sizeof(int));
    if(s==0)
        return 1;
    if(n==0)
            return 0;
    if(dp[n][s]>-1)
        return dp[n][s];
    else
    {
        int ans=ispossible(arr,n-1,s);
        if(arr[n-1]<=s)
            ans=ans|| ispossible(arr,n-1,s-arr[n-1]);
        dp[n][s]=ans;
        return ans;
    }
}
*/

//Iteratively
/*
bool ispossible(int *arr,int n,int s)
{
    bool **dp=new bool *[n+1];
    {
        for(int i=0;i<=n;i++)
        {
            dp[i]=new bool[s+1];
        }
    }
    for(int i=0;i<=s;i++)
    {
        dp[0][i]=false;
    }
    for(int j=0;j<=n;j++)
    {
        dp[j][0]=true;
    }
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=s;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=arr[i-1])
                dp[i][j]=dp[i][j]|| dp[i-1][j-arr[i-1]];

        }
    }
    bool ans=dp[n][s];
    for(int i=0;i<=n;i++)
        delete [] dp[i];
    delete []dp;
    return ans;
}
*/

/*Extended sum_subset since we are only using i-1 and i row for computation
we can reduce the space complexity by toggling between them and taking dp array of
size 2*[s+1];*/

bool ispossible(int *arr,int n,int s)
{
    bool **dp=new bool *[2];
    {
        for(int i=0;i<=1;i++)
        {
            dp[i]=new bool[s+1];
        }
    }
    for(int i=0;i<=s;i++)
    {
        dp[0][i]=false;
    }
    dp[0][0]=true;
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            dp[flag][j]=dp[flag^1][j];
            if(j>=arr[i-1])
                dp[flag][j]=dp[flag][j]|| dp[flag^1][j-arr[i-1]];

        }
        flag=flag^1;
    }
    bool ans=dp[flag^1][s];
    for(int i=0;i<=n;i++)
        delete [] dp[i];
    delete []dp;
    return ans;
}
int main()
{
    int arr[]={1,0,0,7,9};
    int s=12;
    cout<<ispossible(arr,5,s);
}
