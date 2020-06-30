#include<iostream>
using namespace std;

#define MAX 500

void factorial(int n)
{
    int res[MAX];

    res[0] = 1;
    int res_size = 1;
    int carry;
    int q=2;
    while(q<=n)
    {
        int x=0;
        carry=0;
        while(x<res_size)
        {
            res[x]=res[x]*q+carry;

            carry=res[x]/10;

            res[x]=res[x]%10;

            x++;
        }
        q++;
        while(carry)
        {
            res[res_size]=carry%10;
            carry/=10;
            res_size++;

        }
    }
    cout << res_size <<endl;
}
int main()
{
    factorial(120);
    return 0;
}
