#include <iostream>

using namespace std;
//To find the number occuring only one time in the array
int number_ones(int arr[],int n)
{
    int ans=arr[0];
    for(int i=1;i<n;i++)
    {
        ans^=arr[i];
    }
    return ans;
}

//To check a number is odd or even
void odd_even(int n)
{
    if(n&1==1)
        cout<<"odd"<<endl;
    else
        cout<<"even"<<endl;
}

//Number of bits needs to be change to convert a into b
int bits_changed(int x ,int y)
{
    int c=0;
    int res=x^y;
    while(res)
    {
        if(res&1==1)
        {
            c++;
            res=res>>1;
        }
        res=res>>1;
    }
    return c;
}

//efiecient way
int bits_changed2(int x,int y)
{
    int c=0;
    int res=x^y;
    while(res)
    {
        c++;
        res=res&(res-1);
    }
    return c;
}

//swapping using xor
void xor_swaping(int *x,int* y)
{
    int c=(*x)^(*y);
    *x=c^(*x);
    *y=c^(*y);
}

//To find nth bit of a number
int find_bit(int y,int n)
{
    return (y&(1<<n))!=0?1:0;
}

//to set the ith bit
int set_bit(int x,int n)

{
    return (x|(1<<n));
}

//to reset the ith bit
int reset_bit(int x,int n)
{
    int mask=1<<n;
    mask=~(mask);
    return x&mask;
}
int main()
{
    //int a=8;
    //int b=a<<1; //a*2^1
    //cout<<b<<endl;

    //int c=a>>1; //a/2^1
    //cout<<c<<endl;

    //int arr[]={1,2,3,2,3,1,5,4,6,4,6};
    //cout<<number_ones(arr,11)<<endl;

    //int n;
    //cin>>n;
    //odd_even(n);

    int x=11;
    int y=15;
    //cout<<bits_changed(x,y)<<endl;
    //cout<<bits_changed2(x,y)<<endl;

    xor_swaping(&x,&y);
    cout<<x<<" "<<y<<endl;

    int z,n;
    cin>>z>>n;
    //cout<<find_bit(z,n)<<endl;

    //cout<<set_bit(z,n)<<endl;
    cout<<reset_bit(z,n)<<endl;

}
