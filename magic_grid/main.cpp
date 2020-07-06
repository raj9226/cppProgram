#include <iostream>

using namespace std;
//player problem

int min_health(int **r,int n)
{
    int dp[n][n];
    dp[n-1][n-1]=1;

    for(int i=n-2;i>=0;i--)
    {
        dp[i][n-1]=(dp[i+1][n-1]-r[i+1][n-1]);
        if(dp[i][n-1]<=0)
            dp[i][n-1]=1;
    }
    for(int j=n-2;j>=0;j--)
    {
        dp[n-1][j]=(dp[n-1][j+1]-r[n-1][j+1]);
        if(dp[n-1][j]<=0)
            dp[n-1][j]=1;

    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            dp[i][j]=min(dp[i+1][j]-r[i+1][j],dp[i][j+1]-r[i][j+1]);
            if(dp[i][j]<=0)
                dp[i][j]=1;
        }
    }

     int out=dp[0][0]-r[0][0];
     if(out<=0)
        return 1;
     return out;


}
int main()
{
    int n;
    cin>>n;
    int **route=new int*[n];
    for(int i=0;i<n;i++)
        route[i]=new int[n];
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>route[i][j];
            }
        }
    cout << min_health(route,n) << endl;
    return 0;
}
