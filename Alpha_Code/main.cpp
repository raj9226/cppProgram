#include <iostream>

using namespace std;
int n_code(int arr[],int n)
{
    if(n==0||n==1)
        return 1;
    int f=n_code(arr,n-1);
    if(arr[n-2]*10+arr[n-1]<=26)
    {
         f+=n_code(arr,n-2);
    }

    return f;
}
int n_code2(int *arr,int n,int *ans)
{
    if(n==0||n==1)
        return 1;
    if(ans[n]>0)
        return ans[n];
    int output=n_code2(arr,n-1,ans);
    if(arr[n-2]*10+arr[n-1]<=26)
        output+=n_code2(arr,n-2,ans);
    ans[n]=output;
    return output;
}

int n_code3(int arr[],int n)
{
    int ans[n+1];
    ans[0]=ans[1]=1;

    for(int i=2;i<=n;i++)
    {
        ans[i]=ans[i-1];
        if(arr[i-2]*10+arr[i-1]<=26)
            ans[i]+=ans[i-2];
    }
    int output=ans[n];
    delete [] ans;
    return output;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    //cout<<n_code(arr,n);

    //int ans[n+1];
    //for(int i=0;i<=n;i++)
      //  ans[i]=0;
    //cout<<n_code2(arr,n,ans);

    cout<<n_code3(arr,n)<<endl;
    delete [] arr;
    return 0;
}
