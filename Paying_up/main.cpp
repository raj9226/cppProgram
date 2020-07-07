#include <iostream>
/*There is a person and a robber .The robber demand some money
the person has a given set of denomination .Is it possible for him to pay
the robber from the subset of denomination if yes print Yes and the notes else Print No*/
using namespace std;
bool output(int *d,int i,int rs)
{
    int j=0;
    int sum=0;
    while(i>0)
    {
        if(i&1)
        {
            sum+=d[j];
            j++;
            i=i>>1;
            if(sum==rs)
            {
                return true;
                break;
            }

        }
        else
        {
            j++;
            i=i>>1;
        }
    }
    return false;
}
void possible(int *d,int n,int rs)
{
    int range=(1<<n)-1;
    for(int i=0;i<=range;i++)
    {
        if(output(d,i,rs))
        {
            cout<<"Yes!!!!!!!!!!!!!!!"<<endl;
            int j=0;
            while(i>0)
            {
                (i&1)?cout<<d[j]<<" ":cout<<"";
                j++;
                i=i>>1;

            }
            break;
        }
    }

}
int main()
{
    int d[]={10,15,20,25,30};
    int rs;
    cin>>rs;
    possible(d,5,rs);
    return 0;
}
