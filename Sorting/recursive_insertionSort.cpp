#include<iostream>
using namespace std;
void insertion(int *arr,int n)
{
    if(n<=1)
    return;
    insertion(arr,n-1);

    int key = arr[n-1];
    int j=n-2;
    while(j>=0 && arr[j]>key)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements into the array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertion(arr,n);
    cout<<"The sorted array is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}