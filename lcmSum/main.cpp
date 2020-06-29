#include<iostream>
#include<cmath>
using namespace std;
#define maxm 100001
int phi(int n)
{
    int arr[maxm];
    for(int i=0;i<maxm;i++)
    {
        arr[i]=i;
    }
    for(int j=2;j*j<maxm;j++)
    {
        if(arr[j]==j)
        {
            arr[j]=j-1;
            for(int k=j*2;k<maxm;k+=j)
            {
                arr[k]=((arr[k]*(j-1))/j);
            }
        }
    }
    return arr[n];
}

int lcmsum(int n)
{
    int s=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            s+=(phi(i)*i);
        }
    }
    s+=1;
    int res=(n*s)/2;
    return abs(res);

}

int main()
{
    int n;
    cin>>n;
    cout<<lcmsum(n)<<endl;
    return 0;
}
