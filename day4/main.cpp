/*There are different algorithm for stl
let's discuss them one by one
*/
#include <iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
/*
int main()
{

    //int arr[]={1,2,3,4,5,6,7,7,8};
    vector<int> v={1,2,3,4,5,6,7,7,8};

    //cout<<binary_search(arr,arr+8,7)<<endl;//returns 1 if present otherwise 0
    cout<<binary_search(v.begin(),v.end(),7)<<endl;

    //int arr1[]={1,2,3,4,5,6,9,5,0};
    vector<int> v1={1,2,4,5,6,8,9};
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    //cout<<*(find(arr1,arr1+6,6))<<endl;//returns poniter to the first value if present otherwise pointer to the end
    cout<<*(find(v1.begin(),v1.end(),6))<<endl;
    cout<<"============================================================"<<endl;
    //cout<<*(lower_bound(arr1,arr1+6,6))<<endl;//pointer to the first element not less than 5
    cout<<*(lower_bound(v1.begin(),v1.end(),8))<<endl;

    cout<<"------------------------------------------------------------------"<<endl;
    //cout<<*(upper_bound(arr1,arr1+6,5))<<endl;//pointer to the first element greater than 5
    cout<<*(upper_bound(v1.begin(),v1.end(),8))<<endl;

    cout<<"**********************************************************************"<<endl;

    cout<<max(8,8)<<endl;//return largest in case of equal return first element


    cout<<"+++++++++++++++++++++++ Reverse ++++++++++++++++++++++++++++++++++++++++"<<endl;
    /*reverse(arr,arr+9);
    for(int i=0;i<9;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";*/
  /*  reverse(v.begin(),v.end());

    for( auto i=v.begin();i!=v.end();i++)
        cout<<*i<<" ";
    cout<<endl<<"------------------------- Rotate ---------------------------------------"<<endl;

    rotate(v.begin(),v.begin()+3,v.end());//rotate making v.begin()+3 as first element

    for( auto i=v.begin();i!=v.end();i++)
        cout<<*i<<" ";
    cout<<"\n";
    int a[]={3,4,7,6,9,5,1,3};
    vector<int> v4={3,4,6,8,9,5,3};
    sort(a,a+8);
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    cout<<"\n";

    sort(v4.begin(),v4.end());
    for( auto i=v4.begin();i!=v4.end();i++)
        cout<<*i<<" ";
    cout<<"\n";

    sort(a,a+8,greater<int>());
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    cout<<"\n";

    sort(v4.begin(),v4.end(),greater<int>());

    for(auto i=v4.begin();i!=v4.end();i++)
        cout<<*i<<" ";
    cout<<"\n================================================="<<endl;

    vector<int>b={1,2,3,4};
    vector<int>c={4,5,6,7};
    swap(b,c);

    cout<<"After swapping b is \n";
    for(auto i=b.begin();i!=b.end();i++)
        cout<<*i<<" ";

    cout<<"\nAfter swapping c is \n";
    for(auto i=c.begin();i!=c.end();i++)
        cout<<*i<<" ";

    cout<<"\n";
    vector<char> e={'a','b','c','d','e'};
    next_permutation(e.begin(),e.end());//next permutation according to the lexilogical order

    vector<int>f={2,3,5,6,8,4,3};
    next_permutation(f.begin(),f.end());

    for(auto i=e.begin();i!=e.end();i++)
        cout<<*i<<" ";

    cout<<"\n";
    for(auto i=f.begin();i!=f.end();i++)
        cout<<*i<<" ";
    return 0;
}

*/

//Problem 1:
bool myComapartor(pair <string,int> p, pair <string,int> q)
{
   if(p.second==q.second)
        return p.first < q.first;
   return p.second <q.second ;
}
int main()
{
    int x,y,salary;
    string name;
    cin>>x;
    cin>>y;
    pair<string,int> emp[1000];
    for(int i=0;i<y;i++)
    {
        cin>>name>>salary;
        emp[i].first=name;
        emp[i].second=salary;
    }

    sort(emp,emp+y,myComapartor);
    for(auto i=0;i<y;i++)
        if(emp[i].second>=x)
    {

            cout<<emp[i].first<<" "<<emp[i].second<<endl;
    }
    return 0;
}
