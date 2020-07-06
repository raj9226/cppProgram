#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int coin_exchange(int n,int coins[],int numCoins)
{
    if(n==0)
        return 1;
    if(numCoins==0)
        return 0;
    if(n<0)
        return 0;
    int first=coin_exchange(n-coins[0],coins,numCoins);
    int second=coin_exchange(n,coins+1,numCoins-1);
    return first+second;

}
int coin_exchange2(int n,int coins[],int numcoins,int out[][3])
{
    if(n==0)
        return 1;
    if(numcoins==0)
        return 0;
    if(n<0)
        return 0;
    if(out[n][numcoins]!=-1)
        return out[n][numcoins];
    int first=coin_exchange2(n-coins[0],coins,numcoins,out);
    int second=coin_exchange2(n,coins+1,numcoins-1,out);
    out[n][numcoins]=first+second;
    return out[n][numcoins];


}
int main()
{
    int n;
    cin>>n;
    int coins[]={1,2};
    cout << coin_exchange(n,coins,2) << endl;

    int res[n+1][3];
    memset(res,-1,(n+1)*3*sizeof(int));
    cout<<coin_exchange2(n,coins,2,res);
    return 0;
}
