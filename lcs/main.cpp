#include <iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
//to find length of longest common subsequence

int lcs(char *s1,char *s2)
{
    if(s1[0]=='\0' || s2[0]=='\0')
        return 0;
    if(s1[0]==s2[0])
        return (1+lcs(s1+1,s2+1));
    int option1=lcs(s1,s2+1);
    int option2=lcs(s2+1,s1);
    return max(option1,option2);
}
int lcs2helper(char *s1,char* s2,int m,int n,int** dp)
{
    if(m==0 || n==0)
        return 0;
    if(dp[m][n]>-1)
        return dp[m][n];
    int ans;
    if(s1[0]==s2[0])
        ans=1+lcs2helper(s1+1,s2+1,m-1,n-1,dp);
    else
    {
        int option1=lcs2helper(s1,s2+1,m,n-1,dp);
        int option2=lcs2helper(s1+1,s2,m-1,n,dp);
        ans=max(option1,option2);
    }
    dp[m][n]=ans;
    return ans;
}
int lcs2(char *s1,char *s2)
{
    int m=strlen(s1);
    int n=strlen(s2);
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }

    }
    int ans=lcs2helper(s1,s2,m,n,dp);
    for(int i=0;i<=m;i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}
int main()
{
    char s1[100];
    char s2[100];
    cin>>s1>>s2;
    cout<<lcs2(s1,s2)<<endl;
    cout<<lcs(s1,s2)<<endl;
    return 0;
}
