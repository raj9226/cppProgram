#include <iostream>

using namespace std;
/*given an array having all the elements repeated twice only two elements are presents
single time we have to find those elements*/
int pos_setbit(int x)
{
    int c=0;
    while(x)
    {
        if(x&1)
        {
            return c;
            break;
        }
        else{
            c++;
            x=x>>1;
        }
    }

}
void unique2(int arr[],int n)
{
    int ans=arr[0];
    for(int i=1;i<n;i++)
    {
        ans^=arr[i];
    }
    int pos=pos_setbit(ans);
    int ans1=ans,ans2=ans;
    for(int i=0;i<n;i++)
    {
        if((arr[i]>>pos)&1)
        {
            ans1^=arr[i];
        }
        else
        {
            ans2^=arr[i];
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
}
int main()
{
    int arr[]={1,1,2,3,3,4,5,5};
    unique2(arr,8);
    return 0;
}
