#include<bits/stdc++.h>
using namespace std;
int max(int arr[],int n)
{
    int max = arr[0];
    for(int i = 0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}
int min(int arr[],int n)
{
    int min = arr[0];
    for(int i = 0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min = arr[i];
        }
    }
    return min;
}
void countSort(int *arr,int n)
{
    int maxi = max(arr,n);
    int count[maxi+1]={0};
    for(int i =0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i =1;i<=maxi;i++)
    {
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i = n-1;i>=0;i--)
    {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for(int i = 0;i<n;i++)
    {
        arr[i] = output[i];
    }
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the elements of the array\n";
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    countSort(arr,n);
    cout<<"The sorted array is\n";
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}