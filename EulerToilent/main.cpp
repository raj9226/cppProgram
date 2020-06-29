#include <iostream>

using namespace std;
int coprime(int n)
{

    int arr[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=i;
    }
    for(int j=2;j<=n;j++)
    {
        if(arr[j]==j)
        {
            arr[j]=j-1;
            for(int k=2*j;k<=n;k+=j)
            {
                arr[k]=(arr[k]*(j-1))/j;
            }
        }
    }
    return arr[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<coprime(n);
}
