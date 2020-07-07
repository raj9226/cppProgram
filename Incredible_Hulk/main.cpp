#include <iostream>

using namespace std;
/*In this problem there is a hulk and an enemy ,the enemy is present at n-level above the hulk
the hulk can only take steps in the power of 2..We have to find the minimum number of steps required
by hulk to catch the enemy*/

//The solution is the number of set bits in the level
int steps(int n)
{
    int c=0;
    while(n>0)
    {
        if(n&1==1)
        {
            c++;
            n=n>>1;
        }
        else
        {
            n=n>>1;
        }
    }
    return c;

}
int main()
{
    int level;
    cin>>level;
    cout<<steps(level);
    return 0;
}
