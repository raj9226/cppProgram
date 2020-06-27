#include <iostream>

using namespace std;
/*To find nthe fibonacii number in O(ln n)
*/

void multiply(int A[][2],int m[][2])
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
void pow(int m[][2],int n)
{
    if(n==0|| n==1)
        return ;
    pow(m,n/2);
    multiply(m,m);
    if(n%2!=0)
    {
        int A[2][2]={{1,1},{1,0}};
        multiply(m,A);
    }
}
int fibo(int n)
{
    if(n==0)
        return 0;
    int m[2][2]={{1,1},{1,0}};

    pow(m,n-1);
    return m[0][0];
}
int main()
{
    int n;
    cin>>n;
    cout<<fibo(n);
    return 0;
}
