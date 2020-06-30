#include <iostream>

using namespace std;
void update(int index,int value,int *bits,int n)
{
    for(;index<=n;index+=index&(-index))
    {
        bits[index]+=value;
    }
}
int query(int index,int *bits)
{
    int sum=0;
    for(index;index>0;index-=index &(-index))
    {
        sum+=bits[index];
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n+1]();
    int *bits=new int[n+1]();
    for(int i=1;i<n+1;i++)
    {
        cin>>arr[i];
        update(i,arr[i],bits,n);
    }
    cout<<"The sum of first 5 elements are: "<<query(5,bits)<<endl;

    cout<<"The sum from 2nd to 6th elements are: "<<query(6,bits)-query(1,bits)<<endl;


    return 0;
}
