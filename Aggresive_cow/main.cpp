#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

bool check(int c,long long stall[],int n,long long distance)
{
    int co=1;
    long long prev=stall[0];
    for(int i=1;i<n;i++)
    {
        if(stall[i]-prev>=distance)
        {
            prev=stall[i];
            co++;
        }
    }
    if(co==c)
    {
        return true;
    }
    return false;
}
int main()
{
    int n,c;
    cin>>n>>c;

    long long stall[n];
    for(int i=0;i<n;i++)
    {
        cin>>stall[i];
    }
    sort(stall,stall+n);
    long long start=0;
    long long last=stall[n-1]-stall[0];
    long long ans=-1;
    while(start<=last)
    {
        long long mid=start+(last-start)/2;
        if(check(c,stall,n,mid))
        {
            ans=mid;
            start=mid+1;
        }
        else
        {
            last=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}

