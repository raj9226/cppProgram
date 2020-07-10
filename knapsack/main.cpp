#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*Naive Knapsack problem by generating all the subset of weight and selecting the one whose
weight sum is less than the given maxm allowed weight and which also has the maximum value*/
/*
int maxvalue(int *w,int *v,int maxw,int n,int i)
{
    int value=0;
    int currweight=0;
    int j=n-1;
    while(i)
    {
        if(i&1)
        {
            currweight+=w[j];
            value+=v[j];
            i=i>>1;
            j--;
        }
        else{
            j--;
            i=i>>1;
        }
    }
    if(currweight<=maxw)
    {
        return value;
    }
    return 0;
}
int knapsackNaive(int *w,int *v ,int maxw,int n)
{
    int range=(1<<n)-1;
    int ans=0;
    for(int i=1;i<=range;i++)
    {
        int tvalue=maxvalue(w,v,maxw,n,i);
        ans=max(ans,tvalue);
    }
    return ans;
}*/
//  Recursively

/*int knapsack(int *w,int *v,int maxw,int n)
{
    int ans=0;
    if(n==0)
        return 0;
    if(w[n-1]<=maxw)
        ans=v[n-1]+knapsack(w,v,maxw-w[n-1],n-1);
    int temp=knapsack(w,v,maxw,n-1);
    ans=max(ans,temp);
    return ans;

}*/
// Iteratively

int knapsack(int *w,int *v,int maxw,int n)
{
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=new int[maxw+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=maxw;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=maxw;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(w[i-1]<=j)
                dp[i][j]=max(dp[i][j],v[i-1]+dp[i-1][j-w[i-1]]);
        }
    }
    int out= dp[n][maxw];
    for(int i=0;i<=n;i++)
       delete [] dp[i];
    delete [] dp;
    return out;
}
int main()
{
    int v[]={60,100,120};
    int w[]={10,20,30};
    int W=50;
    //cout<<knapsackNaive(w,v,W,3);
    cout<<knapsack(w,v,W,3);
    return 0;
}
