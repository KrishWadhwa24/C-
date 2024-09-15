#include<bits/stdc++.h>
using namespace std;
void sort(int* arr,int size)
{
    for(int i = 0;i<size-1;i++)
    {
        bool swap = false;
        for(int j = 0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap = true;
            }
        }
        if(!swap)
        {
            break;
        }
    }
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