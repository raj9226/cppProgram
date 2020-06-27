#include <iostream>

using namespace std;
/*To find a^b mod 10^9+7 s.t 0<a<10^9 and 0<b<10^9*/

//Using recursion

/*
int pow(int a,int b,int c)
{

    if(b==0)
        return 1;

    if(b%2==0)
    {
        //even
        return pow((a*a)%c,b/2,c);
    }
    else
    {
        //odd
        return ((a%c)*(pow((a*a)%c,b/2,c)))%c;
    }


}
*/

// using iteration

int pow(int a,int b,int c)
{
    int ans=1;
    while(b!=0)
    {
        if(b&1==1)
        {
            ans=(ans%c*a%c)%c;
        }
        a=(a%c*a%c)%c;
        b=b/2;

    }
    return ans;
}
int main()
{
    int a,b;
    cin>>a>>b;
    int ans=pow(a,b,10000007);
    cout << ans << endl;
    return 0;
}
