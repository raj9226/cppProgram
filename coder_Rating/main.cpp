#include <iostream>
#include<algorithm>
using namespace std;
int bits[100001];
struct coder
{
    int x,y,index;
};
bool operator <(coder c1,coder c2)
{
    if(c1.x==c2.x)
    {
        return c1.y<c2.y;
    }
    return c1.x<c2.y;
}
void update(int y)
{
    for(y;y<100001;y+=y&(-y))
    {
        bits[y]++;
    }
}
int query(int y)
{
    int value=0;
    for(y;y>0;y-=y&(-y))
    {
        value+=bits[y];
    }
    return value;
}
int main()
{
    int n;
    cin>>n;
    coder arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].x;
        cin>>arr[i].y;
        arr[i].index=i;
    }
    sort(arr,arr+n);
    int ans[n];
    for(int i=0;i<n;)
    {
        int endvalue=i;
        while(endvalue<n && arr[endvalue].x==arr[i].x && arr[endvalue].y==arr[i].y)
        {
            endvalue++;
        }
        for(int j=i;j<endvalue;j++)
        {
            //query
            ans[arr[j].index]=query(arr[j].y);
        }
        for(int j=i;j<endvalue;j++)
        {
            //update
            update(arr[i].y);
        }
        i=endvalue;


    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}
