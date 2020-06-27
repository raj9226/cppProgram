#include <iostream>
using namespace std;
/*To find a^b int o(b)*/
/*
int pow(int a,int b)
{
    int ans=1;
    int x=a;
    /*while(b>=1)
    {
        ans*=a;
        b-=1;
    }*/
    /*in O(b/2)
    for(int i=1;i<=b/2;i++)
    {
        a*=a;
    }
    if(b%2==0)
        return a;
    else
        return (x*a);

}*/
/*Using recursion in O(ln b) */

int pow(int a,int b)
{
    int ans=1;
    if(b==1)
        return a;

    if(b%2==0)
        return pow(a*a,b/2);
    else
        return a*pow(a*a,b/2);

}
int main()
{
    int a,b;
    cin>>a>>b;
    int ans=pow(a,b);
    cout << ans<< endl;
    return 0;
}
