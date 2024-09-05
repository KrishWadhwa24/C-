#include<iostream>
using namespace std;
void bubbleSort(int *arr,int n)
{
    if(n==1)
    return;
    for(int j=0;j<=n-2;j++)
    {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
        }
    }
    bubbleSort(arr,n-1);
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
    bubbleSort(arr,n);
    cout<<"The sorted array is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}