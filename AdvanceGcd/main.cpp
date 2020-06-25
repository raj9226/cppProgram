#include <iostream>
#include<string>
#include<algorithm>
typedef long long ll;
using namespace std;
/*to find gcd(a,b) s.t 0<=a<=10^25 and 0<=b<10^3*/
int Euclidgcd(int a,int b)
{
    if(b==0)
        return a;
    return Euclidgcd(b,a%b);
}
int gcd(char a[],int b)
{
    int i=0,number=0,ans;
    while(a[i]!='\0')
    {
        int x=(int)(a[i]);
        number=number*10+x;
        number=number%b;
        i++;

    }
    return Euclidgcd(b,number);
}
int main()
{

    char a[]="23567758555512454545451245451215451215454545555555555555555555555555555555555555555555555";
    int b=12;
    int ans=gcd(a,b);
    cout<<ans<<endl;
    return 0;
}
