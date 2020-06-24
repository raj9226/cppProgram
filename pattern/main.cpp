#include <iostream>

using namespace std;
/*1.To print
*
**
***
****
*****
There are various way to print such pattern but we will work on a generalized
Way which work in every situation
int main()
{
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(j<=i)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }

        }
        cout<<"\n";
    }
    return 0;
}
*/

/*2.To print pattern
    *
   **
  ***
 ****
*****


int main()
{

    int i,j;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            if(j>5-i)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
*/

/* 3.To print the pattern
*****
 ****
  ***
    **
     *


int main()
{
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(j>=i)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }

        }
        cout<<"\n";
    }
    return 0;
}
*/

/*4. to print
*****
****
***
**
*


int main()
{
    for(int i=1;5;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(j<=6-i)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }

        }
        cout<<"\n";
    }
    return 0;
}
*/
/*5. To print
    *
   ***
  *****
 *******
*********

*/

 int main()
 {
     int i,j;
     for( i=1;i<=5;i++)
     {
         for( j=1;j<=9;j++)
         {
             if(j>=6-i && j<=4+i)
             {
                 cout<<"*";
             }
             else
             {
                 cout<<" ";
             }

         }
         cout<<"\n";
     }

      return 0;
 }


