#include <iostream>

using namespace std;
// Method 1: o(n2)--Not acceptable
/*
int inversion(int arr[],int n)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
                c++;
        }
    }
    return c;
}*/
//Method 2 we can solve it using Merge sort
int mergetwo(int arr[],int left,int mid,int right)
{
    int i=left;
    int j=mid;
    int k=0;
    int c=0;
    int temp[right-left+1];
    while(i<=mid && j<=right)
    {
        if(arr[i]>arr[j])
        {
            temp[k++]=arr[j++];
            c+=mid-i;
        }
        else
        {
            temp[k++]=arr[i++];
        }
    }
    while(i<mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=right)
    {
        temp[k++]=arr[j++];
    }
    for(int i=left,k=0;i<=right;i++,k++)
    {
        arr[i]=temp[k];
    }
    return c;
}
int merge_sort(int arr[],int left,int right)
{
    int c=0;
    if(right>left)
    {
        int mid=(left+right)/2;
        int ans1=merge_sort(arr,left,mid);
        int ans2=merge_sort(arr,mid+1,right);

        int mergecount=mergetwo(arr,left,mid+1,right);

        return ans1+ans2+mergecount;

    }
    return c;

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int ans=merge_sort(arr,0,4);
    cout<<ans<<endl;
    return 0;
}
