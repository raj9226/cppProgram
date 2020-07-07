#include <iostream>
#include<cmath>
#include<string>
using namespace std;
/*Find the position of a lucky number in a sorted array if only 4 and 7 are allowed in the number
eg:4,7,47,74,447,477..........*/
int lucky_number(int n)
{
    int m=1;
    int t=0;
    while(n)
    {
        if(n%10==4)
            t+=m;
        else
            t+=2*m;
        n=n/10;
        m=2*m;
    }
   return t;
}
int main()
{
    long long  n;
    cin>>n;
    cout<<lucky_number(n);
}
