#include <iostream>

using namespace std;
int longest_Increasing_Subsequence(int arr[],int n)
{
    int *output=new int[n];
    output[0]=1;
    for(int i=1;i<n;i++)
    {
        output[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]>arr[i])
                continue;
            else
            {
                int ans=output[j]+1;
                if(ans > output[i])
                {
                    output[i]=ans;
                }
            }
        }
    }
    int best=0;
    for(int i=0;i<n;i++)
    {
        if(best < output[i])
            best=output[i];
    }
    delete []output;
    return best;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<longest_Increasing_Subsequence(arr,n);
    delete [] arr;
}
