#include <iostream>
#include<map>
using namespace std;
//map stored key-value pair, sorted according to key
/*
int main()
{
    map<int,string>m1;
    map<int,char>m2;
    map<int,char>::iterator i;
    m2[1]='R';
    m2[2]='s';
    m2[1]='t';

    cout<<m2.at(1)<<endl;//return t
    cout<<m2[1]<<endl;

    cout<<m2.count(1)<<endl;//always return 1 in case of map

    cout<<m1.empty()<<endl;//return 1
    cout<<m2.empty()<<endl;//return 0
    for( auto i:m2)
        cout<<i.first<< " "<<i.second<<endl;;


   m1.insert(m1.begin(),{3,"Rajeev"});
   cout<<m1.at(3)<<endl;;

   m1.insert({2,"Rohan"});
   cout<<(m1.begin()->first);

   return 0;
}
*/
//Unorderd map is a key value pair with unorderd ,insert ,search nad erase takes O(1)
/*
#include<unordered_map>
int main()
{
    unordered_map<string,int>a;
    a["mango"]=100;//insert
    cout<<a["mango"]<<endl;

    a["mango"]=80;//Update
    cout<<a["mango"]<<endl;

    if(a.count("mango")!=0)//return 1
        cout<<a["mango"]<<endl;

    a.insert(make_pair("Apple",100));//Insertion
    cout<<a["Apple"]<<endl;


    //searching for given fruit cost
    string s;
    cout<<"Enter Fruit name to know the Price : ";
    cin>>s;
    if(a.count(s)==1)
        cout<<"The cost of "<<s<<" is "<< a[s]<<endl;
    else
        cout<<"sorry "<<s <<" is not available"<<endl;

    a.erase("mango");//to delete mango

    for(auto i:a)
        cout<<i.first<<" "<<i.second<<endl;

    return 0;
}
*/
//Stack is a LIFO orderd Data Structure container
/*
#include<stack>
int main()
{
    stack<int>s;
    for(int i=1;i<5;i++)
        s.push(i);
    int x=s.top();
    cout<<x<<endl;

    s.pop();
    cout<<s.top()<<endl;

    while(s.empty()!=1)
    {
        cout<<s.top()<<endl;
        s.pop();

    }
    cout<<s.size()<<endl;
    return 0;
}
*/
//queue is a FIFO type container
/*
#include<queue>
int main()
{
    queue<int>q;
    for(int i=1;i<5;i++)
        q.push(i);
    cout<<q.front()<<endl;

    cout<<q.size()<<endl;
    cout<<"The queue is:\n";
    while(q.empty()!=1)
    {
        cout<<q.front()<<endl;
        q.pop();

    }
    return 0;
}
*/
//priority_queue is the datastructure which find the largest element in constant time and O(log(n)) for insertion
#include<functional>
#include<queue>
int main()
{
    priority_queue<int,vector<int>,greater<int>> a;//min priority_queue
    for(int i=1;i<10;i+=2)
        a.push(i);
    cout<<a.top()<<endl;

    cout<<a.size()<<endl;

    cout<<"Elements in priority_queue are \n";
    while(a.empty()!=1)
    {
        cout<<a.top()<<endl;
        a.pop();
    }
    return 0;
}
