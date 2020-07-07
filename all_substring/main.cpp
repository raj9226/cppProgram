#include <iostream>
#include<cstring>
using namespace std;
void print_substring(char *s,int n)
{
    int i=0;
    while(n>0)
    {
        (n&1)?cout<<s[i]:cout<<"";
        i++;
        n=n>>1;
    }
    cout<<endl;
}
void generate_subset(char * s)
{
    int n=strlen(s);
    int range=(1<<n)-1;
    for(int i=0;i<=range;i++)
    {
        print_substring(s,i);

    }
}
int main()
{
    char s[100];
    cin>>s;
    generate_subset(s);
}
