#include <iostream>

using namespace std;
//matrix multiplication O(k3)
int ** mul(int a[][2],int b[][1])
{
    int **c=new int*[1];
    for(int i=0;i<2;++i)
        c[i]=new int[2];
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<1;j++)
            {
                c[i][j]=0;
                for(int k=0;k<2;k++)
                {
                    c[i][j]+=a[i][k]*b[k][j];
                }

            }
        }
    }
    return c;
}
int main()
{
    int a[2][2]={{1,2},{2,3}};
    int b[2][1]={{1},{3}};
    int **c;
    c=mul(a,b);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<1;j++)
        {
            cout<<c[i][j]<<" ";
        }
    }
    return 0;
}
