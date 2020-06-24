#include <iostream>
#include<cmath>
using namespace std;
//To find all possible balanced Binary Search Tree Of height H return result as mod m where m=10^9+7
/*
int BbinaryTH(int h)
{
    if(h==0|| h==1)
        return 1;
    int m=pow(10,9)+7;
    int x=BbinaryTH(h-1);

    int y=BbinaryTH(h-2);

    long long result1=(long long)x*x;

    long long result2=(long long )x*y*2;

    int ans1=(int)(result1%m);
    int ans2=(int)(result2%m);


    int ans=(result1+result2)%m;
    return ans;
}
int main()
{
    int h;
    cin>>h;
    int ans=BbinaryTH(h);
    cout<<ans<<endl;
    return 0;
}
*/

//Euclid's theorem gcd
/*
int gcdwoEuc(int a,int b)
{
    int gcd=0;
    for(int i=1;i<=min(a,b);i++)
    {
        if(a%i==0 && b%i==0)
            gcd=i;
    }
    return gcd;//O(min(a,b));
}*/
/*
int EuclidwLoop(int a,int b)
{

    if(b>a)
    {
       return EuclidwLoop(b,a);
    }

    if(a>b)
    {
        while(b!=0)
        {
            int temp=a;
            a=b;
            b=temp%b;
        }

    }

    return a;
}*/

//Euclid with rec
/*
int EuclidRec(int a,int b)
{
    if(b>a)
        return EuclidRec(b,a);
    if(b==0)
        return a;
    return EuclidRec(b,a%b);
}
*/

/* Extended Euclid's Theorem: According to this there exist a equation ax+by=gcd(a,b)
we have to find the x and y and also find gcd*/

class triplet
{
public:
    int gcd;
    int x;
    int y;
};
/*
triplet ExtendedEuclid(int a,int b)
{

    if(b>a)
    {
        triplet ans= ExtendedEuclid(b,a);
        int temp=ans.x;
        ans.x=ans.y;
        ans.y=temp;
        return ans;
    }
    triplet smallans,ans;
    if(b==0)
    {

        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;


    }
    smallans=ExtendedEuclid(b,a%b);
    ans.gcd=smallans.gcd;
    ans.x=smallans.y;
    ans.y=smallans.x- (a/b)*smallans.y;
    return ans;

}*/

triplet ExtendedEuclidLoop(int a,int b)
{
    triplet myans;
    myans.x=1;
    myans.y=0;
    if(b>a)
    {
        triplet ans=ExtendedEuclidLoop(b,a);
        int temp=ans.x;
        ans.x=ans.y;
        ans.y=temp;
        return ans;
    }

    while(b!=0)
    {
        int t=a;
        a=b;
        myans.gcd=a;
        int z=myans.x;
        myans.x=myans.y;
        myans.y=z-(a/b)*myans.y;
        b=t%b;

    }
    return myans;
}
 int main()
{
    int a,b;
    cin>>a>>b;
    //int ans=gcdwoEuc(a,b);
    //cout<<ans<<endl;

    //int ans2=EuclidwLoop(a,b);
    //cout<<ans2<<endl;

    //int ans3=EuclidRec(a,b);
    //cout<<ans3<<endl;

    triplet ans;
    ans=ExtendedEuclidLoop(a,b);
    cout<<"gcd is: "<<ans.gcd<<"\nThe value of x is : "<<ans.x<<"\nThe value of y is : "<<ans.y<<endl;
}

