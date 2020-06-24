#include <iostream>
using namespace std;
/*
int elementSearch(int arr[],int n,int element)
{
    for(int pos=0;pos<n;pos++)
    {
        if(arr[pos]==element)
            return pos+1;
    }
    return -1;

}
int main()
{
    int arr[]={1,2,3,4,5};
    cout<<elementSearch(arr,5,5);
    return 0;
}
*/
/*This above code works only on integer
generic programming help to work with any container
and any data
*/
/*
template <class T>
int searchElement(T arr[],int n,T element)
{
    for(int i=0;i<n;i++)
    {

        if(arr[i]==element)
            return i+1;
    }
    return -1;

}
int main()
{
    int arr[]={1,2,3,4,5};
    cout<<searchElement(arr,5,4)<<endl;
    char arr1[]={'a','b','c'};
    cout<<searchElement(arr1,3,'b')<<endl;
    char arr2[]="Rajeev";
    cout<<searchElement(arr2,6,'e');
    Book
    return 0;

}
*/
//sepearting algorithm to compare book class
/*
template<class T,class Compare>
int searchElement(T arr[],int n,T element,Compare obj)
{
    for(int pos=0;pos<n;++pos)
    {
        if(obj(arr[pos],element)==true)
            return pos+1;
    }
    return -1;

}
class CompareInt{
public:
    bool operator()(int a,int b)
    {
        return a==b ? true:false;
    }
};

int main()
{
    int arr[]={1,2,3,4,5};
    CompareInt obj;
    cout<<searchElement(arr,5,4,obj);



}
*/
/*Iterator is used to get Freedom from the underlying dataStructure (Container)*/

template <class ForwardIterator ,class T,class Compare>
ForwardIterator searchElement(ForwardIterator beginOf,ForwardIterator endof,T element,Compare obj)
{
    while(beginOf!=endof)
    {
        if(obj((*beginOf),element)==true)
            break;
        beginOf++;
    }
    return beginOf;

}
class CompareInt{
public:
    bool operator()(int a,int b)
    {
        return a==b ? true:false;
    }
};

int main()
{
    int arr[]={1,2,3,9,4};
    CompareInt obj;
    cout<<*(searchElement(arr,arr+5,2,obj));

}
