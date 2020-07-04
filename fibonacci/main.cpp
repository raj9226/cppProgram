#include <iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll fib(ll n)
{
    if(n==0|| n==1)
        return 1;
    else
        return fib(n-1)+fib(n-2);//For lager value of n exponential time consuming is not acceptable
}
ll fib2(ll n,ll arr[])
{
    if(n==0 || n==1)
        return 1;
    if(arr[n]>0)
        return arr[n];
    arr[n]=fib2(n-1,arr)+fib2(n-2,arr);;
    return arr[n];
}

ll fib3(ll n)//Iteratively
{
    ll *arr=new ll[n+1];
    arr[0]=arr[1]=1;

    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    ll output= arr[n];
    delete [] arr;
    return output;
}
int main()
{
    ll n;
    cin>>n;
    //ll arr[n+1];
    //memset(arr,0,sizeof(arr));
    //cout<<fib(n)<<endl;
    cout<<fib3(n)<<endl;
    return 0;
}
