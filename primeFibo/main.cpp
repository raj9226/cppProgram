#include <iostream>
#include<cmath>
using namespace std;
/*To print the number upton which is fibonnacci and prime also*/
//We will approach this problem using Seive and then printing the value from the seive which is fibo*/

bool isperfectSquare(int n)
{
    int s=sqrt(n);
    return(s*s==n);
}
bool isFibo(int n)
{
    if(isperfectSquare(5*n*n+4)||isperfectSquare(5*n*n-4))
        return true;
    return false;

}
bool *seive(int n)
{
    bool* arr=new bool[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=true;
    }
    arr[0]=false;
    arr[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)//optimization
            {
                arr[j]=false;
            }
        }
    }
    return arr;
}
int main()
{
    int n;
    cin>>n;
    bool* arr;
    arr=seive(n);

    for(int i=2;i<=n;i++)
    {
        if(*(arr+i)==true)
        {
            if(isFibo(i))
            {
                cout<<i<<" ";
            }
        }
    }
    cout<<"\n";
    return 0;
}
