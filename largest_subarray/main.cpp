#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//naive approach o(n^2)
int largest(int *arr,int n)
{
    int res[n][n];

    memset(res,INT_MIN,n*n*sizeof(int));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        res[i][i]=arr[i];
        for(int j=i+1;j<n;j++)
        {
            res[i][j]+=res[i][j-1]+arr[j];
            if(ans<res[i][j])
                ans=res[i][j];
        }
    }
    return ans;
}
//Kadane's Algorithm
int largest2(int arr[],int n)
{
    int current_max=0;
    int best=0;

    for(int i=0;i<n;i++)
    {
        current_max+=arr[i];
        if(best<current_max)
            best=current_max;
        if(current_max<0)
            current_max=0;
    }
    return best;
}

int main()
{
    int arr[]={-5,6,7,-20,3,5,8,-9};
    cout<<largest(arr,8)<<endl;
    cout<<largest2(arr,8)<<endl;
    return 0;
}
