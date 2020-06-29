#include <iostream>
#include<cmath>
#include<vector>
#define maxm 100001
using namespace std;
vector<int>* seive()
{
    bool arr[maxm];
    for(int i=0;i<maxm;i++)
    {
        arr[i]=true;
    }
    for(int j=2;j*j<maxm;j++)
    {
        if(arr[j])
        {
            for(int k=j*j;k<maxm;k+=j)
            {
                arr[k]=false;
            }
        }
    }
    vector<int>*v=new vector<int>();
    v->push_back(2);
    for(int i=3;i<maxm;i+=2)
    {
        if(arr[i]==true)
        {
            v->push_back(i);
        }
    }
    return v;
}
void segSeive(long long l,long long r, vector<int>*&primes)
{
    bool isprime[r-l+1];
    for(int i=0;i<=r-l;i++)
    {
        isprime[i]=true;

    }
    for(int j=0;primes->at(j)*(long long)primes->at(j)<=r;j++)
    {
        int curprime=primes->at(j);
        long long base=(l/curprime)*curprime;
        //Just smaller or equal value to l
        if(base<l)
        {
            base+=curprime;
        }


        //Mark all the multiple from l to r as false
        for(long long k=base;k<=r;k+=curprime)
        {
            isprime[k-l]=false;

        }
            //There is a case when base itself is a prime
        if(base==curprime)
        {
            isprime[base-l]=true;
        }

    }
    for(int i=0;i<=r-l;i++)
    {
        if(isprime[i]==true)
        {
            cout<<i+l<<endl;
        }
    }

}
int main()
{
    long long l, r;
    cin>>l>>r;
    vector<int>*s=seive();
    segSeive(l,r,s);
}
