#include <iostream>
#include<cmath>
using namespace std;
int digitsInFactorial(int N)
{
    double digits=0;
    for(int i=2;i<=N;i++)
    {
        digits+=log10(i);
    }

    return floor(digits)+1;

}
int main()
{
    cout << digitsInFactorial(120) << endl;
    return 0;
}
