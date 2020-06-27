#include <iostream>
#define Mod 1000007
using namespace std;
/*Sum of fibonacci number from m to n*/
void multiply(int A[2][2],int m[2][2])
{
    int fvalue=A[0][0]*m[0][0]+A[0][1]*m[1][0];
    int svalue=A[0][0]*m[0][1]+A[0][1]*m[1][1];
    int tvalue=A[1][0]*m[0][0]+A[1][1]*m[1][0];
    int fovalue=A[1][0]*m[0][1]+A[1][1]*m[1][1];

    A[0][0]=fvalue;
    A[0][1]=svalue;
    A[1][0]=tvalue;
    A[1][1]=fovalue;
}
void pow(int m[2][2],int n)
{
    if(n==0 || n==1)
        return;
    pow(m,n/2);
    multiply(m,m);
    if(n%2!=0)
    {
        int a[2][2]={{1,1},{1,0}};
        multiply(m,a);
    }
}
int fib(int n)
{
    int m[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
    pow(m,n-1);
    return m[0][0];
}
int main()
{
    int a,b,c;
    cin>>a>>b;
    int first=fib(a+2);
    int second=fib(b+1);
    cout<<first<<endl;
    cout<<second<<endl;
    c=(first%Mod - second%Mod)%Mod;
    cout<<c;
    return 0;
}
