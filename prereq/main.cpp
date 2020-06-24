/*Bubble sort
#include <iostream>
#include <chrono>

using namespace std::chrono;

using namespace std;
void Bubblesort(int arr[],int s)
{

    for(int round=1;round<s;round++)
    {
        for(int j=0;j<s;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }

        }
    }
    for(int k=0;k<s;k++)
    {

        cout<<arr[k]<<endl;
    }
}
int main()
{
    int arr[]={5,4,6,7,1};
    int s=sizeof(arr)/sizeof(arr[0]);
    auto start = high_resolution_clock::now();

    Bubblesort(arr,s);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<<endl<<duration.count();
    return 0;
}
*/
//Modified Buuble sort
/*
#include <iostream>
#include <chrono>

using namespace std::chrono;

using namespace std;
void Bubblesort(int arr[],int s)
{

    for(int round=1;round<s;round++)
    {
        int flag=0;
        for(int j=0;j<s;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;

            }

        }
        if(flag==0)
            break;
    }
    for(int k=0;k<s;k++)
    {

        cout<<arr[k]<<endl;
    }
}
int main()
{
    int arr[]={5,4,3,2,1};
    int s=sizeof(arr)/sizeof(arr[0]);
    auto start = high_resolution_clock::now();

    Bubblesort(arr,s);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<<endl<<duration.count();
    return 0;
}
*/
//Selection Sort->Same as our brain works
/*
#include<iostream>

using namespace std;
int minimum(int arr[],int index,int s)
{
    int mini=arr[index];
    int j;
    for(int i=index;i<s;i++)
    {
        if(arr[i]<=mini)
        {
            mini=arr[i];
            j=i;
        }

    }
    return j;
}
void selectionSort(int arr[],int s)
{
    for(int i=0;i<s;i++)
    {
        int pos=minimum(arr,i,s);
        int temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
    }

}
int main()
{
    int arr[]={1,2,6,4,5,0};
    int s=sizeof(arr)/sizeof(arr[0]);
    cout<<"starts"<<endl;
    selectionSort(arr,s);
    for(int k=0;k<s;k++)
        cout<<arr[k]<<"\t";

    return 0;
}
*/
//Insertion sort  :A deck of card
/*
#include<iostream>
using namespace std;
void InsertionSort(int arr[],int s)
{
    for(int i=1;i<s;i++)
    {
        int j;
        int temp=arr[i];
        for(j=i-1;j>=0&& temp<arr[j];j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;

    }

}
int main()
{
    int arr[]={1,2,6,4,5,0};
    int s=sizeof(arr)/sizeof(arr[0]);
    cout<<"starts"<<endl;
    InsertionSort(arr,s);
    for(int k=0;k<s;k++)
        cout<<arr[k]<<"\t";

    return 0; 0;
}

*/
//Quick sort: Divide and conquer find pivot point
/*
#include<iostream>
using namespace std;

int partitionFn(int arr[],int low,int high)
{
    int temp;
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;//swap to extend the region

        }

    }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;//swap to fit pivot
    return(i+1);
}
void quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partitionFn(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}
int main()
{
    int arr[]={44,33,11,55,77,90,40,60,99,22,88,66};
    int s=sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,s-1);
    for(int k=0;k<s;k++)
        cout<<arr[k]<<" ";

    return 0;
}
*/
//Merge sort
/*
#include<iostream>
using namespace std;
void mergeSort(int arr[],int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[1000];
    while(i<=mid &&j<=e)
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid)
        temp[k++]=arr[i++];
    while(j<=e)
        temp[k++]=arr[j++];
    for(int i=s;i<=e;i++)
    {
        arr[i]=temp[i];
    }


}
int split(int arr[],int s,int e)
{
    if(s>=e)
    {
        return 0;
    }

    int mid=(s+e)/2;
    split(arr,s,mid);
    split(arr,mid+1,e);

    mergeSort(arr,s,e);



}
int main()
{
    int arr[]={1,2,4,3,6,8,7,5};
    split(arr,0,7);
    for(int i=0;i<7;i++)
        cout<<arr[i]<<" ";

    return 0;
}

*/

//BinarySearch
#include<iostream>
using namespace std;
int binary_Search(int arr[],int s,int e,int v)
{
    int mid;
    if(e>=s){
        mid=(s+e)/2;
        if(v==arr[mid])
            return 1;
        if(v<arr[mid])
            return binary_Search(arr,s,mid-1,v);
        if(v>arr[mid])
            return binary_Search(arr,mid+1,e,v);
    }
    return 0;

}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8};
    int x=binary_Search(arr,0,7,10);
    if(x==1)
        cout<<"Found";
    else
        cout<<"not found";
    return 0;
}
