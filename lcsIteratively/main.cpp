#include <iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int lcs(char *s1,char*s2)
{
    int m=strlen(s1);
    int n=strlen(s2);

    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=0;
    }
    for(int j=0;j<=n;j++)
    {
        dp[0][j]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[m-i]==s2[n-j])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }

        }
    }
    return dp[m][n];
}
int main()
{
    char s1[100];
    char s2[100];
    cin>>s1>>s2;
    cout<<lcs(s1,s2);
    return 0;
}
