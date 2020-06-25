#include <iostream>
/*To find the multiplicative modulo inverse*/
using namespace std;
class triplet
{
public:

    int x;
    int y;
    int gcd;
};
triplet MultiplicativeModuloInverse(int A,int m)
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
    int A,m;
    cin>>A>>m;
    triplet t;
    t=MultiplicativeModuloInverse(A,m);
    if(t.gcd==1)
    {
        cout<<"The modulo inverse is: "<<t.x<<endl;
    }
    else
    {

        cout<<"Inverse doesn't exist as the number is not co-prime to each other"<<endl;
        cout<<"It's gcd is:"<<t.gcd<<endl;
    }
    return 0;
}
