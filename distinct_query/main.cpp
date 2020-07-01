#include <iostream>
#include<unordered_map>
using namespace std;
/*
int distinct_element(int arr[],int n,int start,int last)
{
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    int c=0;
    for(int i=start-1;i<last;i++)
    {
        if(m[i]>=1)
        {
            c++;
        }
    }
    return c;
}
*/
/*
#include<set>
#include<algorithm>
int distinct_element(int arr[],int s,int l)
{
    set<int>s1(arr+s-1,arr+l);
    set<int>::iterator itr;
    int c=0;
    for(itr=s1.begin();itr!=s1.end();itr++)
    {
        c++;
    }
    return c;
}

int main()
{
    int arr[7]={2,3,1,3,2,5,1};
    int start,endi;
    cin>>start>>endi;
    cout<< distinct_element(arr,start,endi)<<endl;

    return 0;
}
*/


#include<string.h>
#include<algorithm>
struct event
{
    int first,second,index;
}query[100001];

int arr[100001];

int bit[1000001];
bool operator < (event x,event y)
{
    return x.second<y.second;
}
void update(int index,int value,int n)
{
    for(;index<=n;index+=index&(-index))
    {
        bit[index]+=value;
    }
}
int value(int index)
{
    int result=0;
    for(;index>0;index-=index&(-index))
        result+=bit[index];
    return result;
}
int main()
{
    int last[1000];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int q;
    cin>>q;
    int ans[q];
    for(int i=0;i<q;i++)
    {
        cin>>query[i].first>>query[i].second;
        query[i].index=i;
    }
    sort(query,query+q);
    memset(last,-1,sizeof(last));
    int total=0;
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(last[arr[i]]!=-1)
        {
            update(last[arr[i]],-1,n);
        }
        else
        {
            total++;
        }
       update(i,1,n);
       last[arr[i]]=i;

       while(k<q && query[k].second==i)
       {
           ans[query[k].index]=total-value(query[k].first-1);
           k++;

       }
    }
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<endl;
    }

}
