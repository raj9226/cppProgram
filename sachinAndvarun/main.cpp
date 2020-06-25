/*The problem is to find the total number of pair of(x,y) which satisfy the equation a*x+b*y=d  a,b,d are given*/
#include <iostream>
#include<cmath>
using namespace std;
typedef long long ll;
/*Method 1:Worst method having o(d/a*d/b) which is not acceptable as we do in graph to find the intersection points*/
/*
int possible(int a,int b,int d)
{
    int c=0;
    int x,y;
    for(x=0;x<=d/a;x++)
    {
        for(y=0;y<=d/b;y++)
        {
            int ins=a*x+b*y;
            if(ins==d)
            {
                c+=1;
            }
        }
    }
    return c;
}*/
/*Method2: Here also the complexity is O(d/b) which is not acceptable*/
/*
int possible(int a,int b,int d)
{
    int c=0;
    int y;
    for(y=0;y<=d/b;y++)
    {
        int ins=d-b*y;
        if(ins%a==0)
            c+=1;
    }
    return c;
}
*/
/*best case in complexity O(max(a,b))*/
class triplet
{
public:

    ll x;
    ll y;
    ll gcd;
};
triplet MultiplicativeModuloInverse(ll A,ll m)
{
      triplet t;
      if(m==0)
      {
          t.gcd=A;
          t.x=1;
          t.y=0;
          return t;
      }
      triplet smallans=MultiplicativeModuloInverse(m,A%m);
      t.gcd=smallans.gcd;
      t.x=smallans.y;
      t.y=smallans.x-(A/m)*smallans.y;

      return t;
}

int main()
{
    ll a=pow(10,5);
    ll b=pow(10,8);
    ll d=10;
    triplet t;
    t=MultiplicativeModuloInverse(b,a);
    if(d%t.gcd)
    {
        cout<<"0"<<endl;
        return 0;
    }
    if(d==0)
    {

        cout<<"0"<<endl;
        return 0;
    }
    a/=t.gcd;
    b/=t.gcd;
    d/=t.gcd;
    ll y1=(d%a*t.x)%a;
    ll n=((d/b)-y1)/a;
    ll all=n+1;
    cout << all<<endl;
    return 0;
}
