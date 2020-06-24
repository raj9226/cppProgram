#include <iostream>
#include<vector>
using namespace std;
//String
/*int main()
{
    string s1="Hello";
    cout<<s1<<endl;

    string s2(s1);
    cout<<s2<<endl;

    string s3(s1,1,3);
    cout<<s3<<endl;

    string s4("Hello",3);
    cout<<s4<<endl;

    string s5(5,'*');
    cout<<s5<<endl;

    string s6("Raj");
    cout<<s6<<endl;

    string s7(s1.begin(),s1.begin()+3);
    cout<<s7<<endl;

    s1.append("world");
    cout<<s1<<endl;

    cout<<*(s1.begin())<<endl;

    s1.clear();
    cout<<s1<<endl;

    string s8("Hello");
    string s9("Hello");
    cout<<s8.compare(s9)<<endl;

   /* string s10;
    s10.copy(s8,1,3);
    cout<<s10<<endl;
*/
  /*  cout<<s9.empty()<<endl;

    s8.erase(1,3);
    cout<<s8<<endl;

    cout<<s9.find('l')<<endl;

    s8.insert(2,"e");
    cout<<s8<<endl;

    cout<<s8.length()<<endl;

    cout<<s8.size()<<endl;

    string s11=s9.substr(1,3);
    cout<<s11<<endl;



    return 0;
}
*/
//vector
/*
int main()
{

    vector <int> v1;//empty vector
    vector <int> b(5,10);//vector of size 5 having each value 10

    vector <int>c(b.begin(),b.end());//iterating through vector b
    cout<<*(c.begin())<<endl;
    cout<<*(b.begin())<<endl;

    vector <int>d(c);//copy of vector c in b
    cout<<*(d.begin())<<endl;

    cout<<d.at(4)<<endl;
    cout<<d[544]<<endl;

    cout<<d.back()<<endl;

    cout<<*(d.begin())<<endl;

    b.clear();
   // cout<<b.at(2)<<endl;

   cout<<b.empty()<<endl;

   cout<<*(d.end())<<endl;

   vector <int> e;
   for(int i=0;i<5;i++)
    e.push_back(i);
   e.erase(e.begin());
   cout<<e[0]<<endl;

   cout<<e.front()<<endl;

   e.insert(e.begin(),5);
   cout<<e.front()<<endl;
   cout<<e.at(4)<<endl;
   cout<<e.size()<<endl;

   e.resize(3);
   cout<<e.front()<<endl;
   //cout<<e.at(4)<<endl;
   cout<<e.size()<<endl;









    return 0;
}
*/
//List: constant time in insetion and deletion ,generally implement dll
/*
#include<list>
int main()
{
    list <int>l;//empty list
    list <int>a(5,10);
    cout<<*(a.begin())<<endl;

    cout<<*(a.end())<<endl;

    cout<<l.empty()<<"\n";
    cout<<a.empty()<<endl;

    cout<<a.back()<<endl;

    a.assign(5,20);
    cout<<*(a.begin())<<endl;

    a.erase(a.begin());
    cout<<*(a.begin())<<endl;

    cout<<a.front()<<endl;

    a.push_front(30);
    cout<<a.front()<<endl;

    a.remove(20);
    cout<<a.front()<<endl;

    a.insert(a.begin(),20);
    a.push_front(10);


    a.reverse();
    cout<<a.front()<<endl;
    cout<<a.back()<<endl;

    a.pop_back();
    cout<<a.back()<<endl;
    cout<<a.size()<<endl;

    return 0;
}
*/
/*
int main()
{
    pair<int,char>p;//empty pair
    pair<int,char>a(1,'a');
    pair<int,char>b(a);//copy
    p=make_pair(2,'b');
    cout<<b.first<<" "<<b.second<<endl;
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}
*/
#include<set>
#include<algorithm>
#include<iterator>
int main()
{
    set<int>s;//empty set
    int a[]={1,2,3,4,5,5};
    set<int>b(a,a+6);
    set <int > :: iterator i;

    for(i=b.begin();i!=b.end();i++)
        cout<<" "<<*(i);

    cout<<"\n";
    set <int, greater<int> >c(a,a+6);
    set <int ,greater<int> > :: iterator j;
    for(j=c.begin();j!=c.end();j++)
        cout<<" "<<*(j);
    cout<<"\n";
    multiset<int>m(a,a+6);
    multiset<int>::iterator k;
    for(k=m.begin();k!=m.end();k++)
        cout<<" "<<*(k);
    cout<<"\n";
    cout<<*(c.find(4))<<endl;
    cout<<c.count(6);


    return 0;
}
