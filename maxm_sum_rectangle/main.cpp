#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int kadnes(int* arr,int n,int *start,int *finish)
{
    int cursum=INT_MIN;
    int sum=0;
    *finish=-1;
    int local_start=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<0)
        {
            sum=0;
            local_start=i+1;
        }
        else if(sum>cursum)
        {
            cursum=sum;
            *start=local_start;
            *finish=i;
        }
     }
        if(*finish!=-1)
            return cursum; //When there is atleast  one non negative number

        //When all numbers are negative
        cursum=arr[0];
        *start=0;
        *finish=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>cursum)
                {
                    cursum=arr[i];
                    *start=i;
                    *finish=i;
                }

        }
    return cursum;
}
int max_rec(int **inp,int m,int n)
{
    int left,right,maxsum=INT_MIN;
    int maxleft,maxright,maxup,maxdown;
    int arr[m];
    int start,finish;
    for(left=0;left<n;left++)
    {
        memset(arr,0,sizeof(int));
        for(right=left;right<n;right++)
        {
            for(int i=0;i<m;i++)
            {
                arr[i]+=inp[i][right];
            }
            int cursum=kadnes(arr,m,&start,&finish);
            if(cursum>maxsum)
            {
                maxsum=cursum;
                maxleft=left;
                maxright=right;
                maxup=start;
                maxdown=finish;
            }
        }
    }
    return maxsum;
}

int main()
{
    int m,n;
    cin>>m>>n;
    int** inp=new int*[m];
    for(int i=0;i<n;i++)
        inp[i]=new int[n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>inp[i][j];
    }


    cout << max_rec(inp,m,n)<< endl;
    return 0;
}
