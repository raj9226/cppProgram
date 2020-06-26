#include <iostream>

using namespace std;
/*simple integer Fibonacci is 0112358....*/
/*1.simple using recursion*/
/*
int fib(int n)
{
    if(n<=1)
        return 0;
    if(n==2)
        return 1;
    else
        return fib(n-2)+fib(n-1);
}*/
//Using Dynamic Programming
/*
int fib(int n)
{
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
        //cout<<dp[i];
    }
    return dp[n];
}
*/

/*To check wether a number is fibonacii or not*/
//1.method :To find all the number upto the given numbeer using fibonacii series and if is present
//is a fibonacci otherwise not

/*
#include<vector>
bool fib(int n)
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    bool fibo=true;
    {
        while(*(v.end()-1)<n)
        {
            v.push_back(*(v.end()-1)+*(v.end()-2));
            if(*(v.end()-1)==n)
            {
                fibo=true;
                break;
            }
            fibo=false;
        }
    }
    return fibo;
}

int main()
{
    int n;
    cin>>n;
    if(fib(n))
        cout<<n << " is a fibonaccii"<<endl;
    else
        cout<<n <<" is not a fibonnacci"<<endl;
    return 0;
}

*/

/*Method 2: If a number is fibonacci if either (5n^2-4) or(5n^2+4) is a perfect square*/
#include<cmath>
bool perfectsqrt(int n)
{
    int s=sqrt(n);
    return (s*s==n);
}
bool isfib(int n)
{
    if(perfectsqrt(5*n*n+4)|| perfectsqrt(5*n*n-4))
        return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    if(isfib(n))
        cout<<n << " is a fibonaccii"<<endl;
    else
        cout<<n <<" is not a fibonnacci"<<endl;
    return 0;
}
