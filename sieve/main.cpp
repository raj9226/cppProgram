#include <iostream>
using namespace std;
/*To find the number of prime numbers upto n*/
//1.Method 1-o(n2)
/*
int primes(int n)
{
    int i,j,primesn=0;
    for(int i=2;i<=n;i++)
    {
        int c=0;
        for(int j=1;j<=n;j++)
        {
            if(i%j==0)
            {
                c+=1;
            }
            else
                continue;
        }
        if(c==2)
            primesn+=1;
        else
            continue;
    }
    return primesn;

}*/
//2.method o(n*n^1/2);
/*
int checkprime(int n)
{
    int primes=0;
    for(int j=1;j<=n;j++)
    {
        int count=0;
        for(int i=1;i*i<=j;i++)//optimization
        {
            if(j%i==0)
            {
                if(i*i==j)
                {
                    count+=1;
                }
                else
                {
                    count+=2;
                }
             }
            }
            if(count==2)
                primes+=1;
    }

    return primes;
}*/
//3.method O(N log logN)
int seive(int n)
{
    bool arr[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=true;
    }
    arr[0]=false;
    arr[1]=false;
    for(int i=2;i*i<=n;i++) //optimization
    {
        if(arr[i]==true)
        {
            for(int j=i*i;j<=n;j+=i) //optimization
            {
                arr[j]=false;
            }

        }
    }
    int c=0;
    for(int x=0;x<=n;x++)
    {
        if(arr[x]==true)
            c++;
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    cout<<seive(n)<<endl;
    return 0;
}
