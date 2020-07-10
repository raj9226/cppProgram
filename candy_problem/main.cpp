#include <iostream>

using namespace std;
//Given n candy and n person we have to assign each person a candy according to their likes
long long ways(int like[3][3],int n)
{
    long long dp[(1<<n)];
    dp[(1<<n)-1]=1;
    for(int mask=(1<<n)-2;mask>=0;mask--)
    {
        int k=0;
        int temp=mask;
        while(temp>0)
        {
            int lastbit=temp&1;
            k=k+lastbit;
            temp=temp/2;
        }
        for(int i=0;i<n;i++)
        {
            if(like[k][i] && !(mask &(1<<i)))
            {
                dp[mask]+=dp[mask | (1<<i)];
            }
        }
    }
    return dp[0];
}
int main()
{
    int like[3][3]={{1,1,1},{1,0,1},{1,1,1}};
    cout<<ways(like,3);

    return 0;
}
