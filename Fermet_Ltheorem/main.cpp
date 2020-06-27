#include <iostream>
#define Mod 10000007
using namespace std;
/*a^p mod p=a iff p is prime*/
//Application to find multiplicative modulo Inverse

//1.Method ::Extended Euclid's Theorem*/
/*
class triplet{
public:
    int x,y,gcd;
};
triplet Inverse(int a,int b)
{
    triplet t;
    if(b==0)
    {
        t.gcd=a;
        t.x=1;
        t.y=0;
        return t;
    }
    triplet smaller;
    smaller=Inverse(b,b%a);
    t.x=(smaller.y)%Mod ;
    t.y=((smaller.x)%Mod-((a/b)*smaller.y)%Mod)%Mod ;
    return t;
}*/

int Inverse(int a,int m)
{
    int ans=1;
    while(m!=0)
    {
        if(m&1==1)
        {
            ans=(ans %Mod *a% Mod)%Mod;
        }
        a=(a%Mod*a%Mod)%Mod;
        m=m/2;
    }
    return ans;

}
int main()
{
    int a,m;
    cin>>a>>m;
    int ans=Inverse(a,m-2);
    cout << ans<< endl;
    return 0;
}



