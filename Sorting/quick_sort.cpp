#include<bits/stdc++.h>
using namespace std;
int partition(int* arr,int low,int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j)
    {
        while(arr[i]<=pivot && i<high)
        {
            i++;
        }
        while(arr[j]>pivot && j>low)
        {
            j--;
        }
        if(i<j)
        swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(int* arr,int low,int high)
{
    if(low<high)
    {
        int pIndex = partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}
void sort(int* arr,int n)
{
    qs(arr,0,n-1);
}
int main()
{
    int n;
    cin>>n;
    int *arr= new int[n];
    cout<<"Enter the elements of the array\n";
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,n);
    cout<<"The sorted array is\n";
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}