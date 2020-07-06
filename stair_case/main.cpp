#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*No. of ways To go upto n stairs if either 1,2 or 3 steps can be taken at a time*/
int ways(int n)
{
    if(n==0)
        return 1;
    if(n==1||n==2)
        return n;
    return ways(n-1)+ways(n-2)+ways(n-3);
}
int ways2(int n,int *ans)
{
    if(n==0)
        return 1;
    if(n==1||n==2)
        return n;
    if(ans[n]!=0)
        return ans[n];
    int output=ways2(n-1,ans)+ways2(n-2,ans)+ways2(n-3,ans);
    ans[n]=output;
    return output;
}
int ways3(int n) //iteratively
{
    int *w=new int[n+1];
    w[0]=1;
    w[1]=1;
    w[2]=2;

    for(int i=3;i<=n;i++)
    {
        w[i]=w[i-1]+w[i-2]+w[i-3];
    }
    int output=w[n];
    delete []w;
    return output;
}
int main()
{
    int n;
    cin>>n;
    cout<<ways(n)<<endl;
    cout<<ways3(n)<<endl;

    int ans[n+1];
    memset(ans,0,sizeof(ans));
    /*for(int i=0;i<=n;i++)
    {
        ans[i]=0;
    }*/

    cout<<ways2(n,ans);
    return 0;
}
