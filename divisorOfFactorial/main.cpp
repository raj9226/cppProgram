#include <iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define mod 1000000007
/*To find the mnumber of divisor of a factorial* and print mod10^9+7*/
//Method 1: worst case
/*
int Factorial(int n)
{
    if(n==1)
        return 1;
    return n*Factorial(n-1);
}
int factors(int n)
{
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
            c+=1;
    }
    return c;

}*/

vector<int>* Seive()
{
    bool InPrime[50001];
    vector<int>* v=new vector<int>();
    for(int i=2;i<=50001;i++)
    {
        InPrime[i]=true;
    }
    for(int i=2;i*i<=50001;i++)
    {
        if(InPrime[i])
        {
            for(int j=i*i;j<=50001;j++)
                {
                    InPrime[j]=false;
                }
        }
    }
    v->push_back(2);
    for(int i=3;i<=50001;i+=2)
    {
        if(InPrime[i])
        {
            v->push_back(i);
        }
    }
    return v;
}
ll divisors(int n,vector<int>* &primes)
{
    ll result=1;
    for(int i=0;primes->at(i)<=n;i++)
    {
        ll c=0;
        int k=primes->at(i);
        while((n/k)!=0)
        {
            c=(c+(n/k))% mod;
            k=k*primes->at(i);
        }
        result=(result*(c+1)%mod)%mod;
    }
    return result;

}
int main()
{
    int n=4;
    vector<int>* primes=Seive();
    cout<<divisors(n,primes);
    return 0;

}
