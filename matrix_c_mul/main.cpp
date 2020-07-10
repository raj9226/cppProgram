#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
int mincost(int *a,int i,int j)
{
    if(i==j)
        return 0;
    int ans=  INT_MAX;
    for(int k=i;k<j;k++)
    {
         int temp=mincost(a,i,k)+mincost(a,k+1,j)+a[i-1]*a[j]*a[k];
         ans=min(ans,temp);
    }
    return ans;
}

//using dp
int dp[100][100];
int mincost2(int *a,int i,int j)
{

    int ans=INT_MAX;

    if(i==j)
    {
        dp[i][j]=0;
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    for(int k=i;k<j;k++)
    {
        int temp=mincost2(a,i,k)+mincost2(a,k+1,j)+a[i-1]*a[j]*a[k];
        ans=min(ans,temp);

    }
    dp[i][j]=ans;
    return ans;

}
*/
// iteratively
int mincost3(int *a,int n)
{
    int res[n][n];
    for(int i=1;i<n;i++)
    {

        res[i][i]=0;
    }
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<=n-l;i++)
        {
            int j=i+l-1;
            res[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                int temp=res[i][k]+res[k+1][j]+a[i-1]*a[k]*a[j];
                res[i][j]=min(res[i][j],temp);
            }
        }
    }
    return res[1][n-1];

}

int main()
{
    int a[]={1,2,3,4};
    int n=sizeof(a)/sizeof(int);
    //cout<<mincost(a,1,n-1)<<endl;
    //memset(dp,-1,100*100*sizeof(int));
    //cout<<mincost2(a,1,n-1)<<endl;

    cout<<mincost3(a,n);
}
