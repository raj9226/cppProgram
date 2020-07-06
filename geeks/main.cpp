#include <iostream>
#define maxm 100000001
#include<string>
bool arr[maxm];
using namespace std;
void seive(long long n)
{
    for(int i=0;i<maxm;i++)
    {
        arr[i]=true;
    }
    arr[0]=arr[1]=false;
    for(int i=2;i*i<maxm;i++)
    {
        if(arr[i]==true)
        {
            for(int j=2*i;j<maxm;j+=i)
            {
                arr[j]=false;
            }
        }
    }
}
string smallestK(long long n)
{
    string s;
    if(n/10!=0)
    {
      if(arr[n]==true)
      {
          return s+to_string(-1);
      }
      else if(n%2==0)
      {
          s+=to_string(2);
          cout<<"ghghghghghjghgh\n";
      }
      int q=0;
      int product=1;
      while(q!=1)
      {
          for(int i=2;i*i<=n;)
          {
              if(arr[i]==true)
              {
                  while(q/i!=1)
                  {
                    product*=i;
                    n/=i;
                    q/=i;
                  }
                  i++;

              }
          }
      }
      s+=to_string(product);
      return s;
    }
    return s+to_string(n);


}

int main()
{
    string s=smallestK(26);
    cout<<s;
    return 0;
}

