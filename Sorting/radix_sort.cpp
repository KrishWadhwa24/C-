#include<bits/stdc++.h>
using namespace std;
int getMax(int *arr,int n)
{
    int maxi = arr[0];
    for(int i = 0;i<n;i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
        }
    }
    return maxi;
}
void count_sort(int *arr,int n,int exp)
{
    int output[n];
    int i,count[10]={0};
    for(int i =0;i<n;i++)
    {
        count[(arr[i]/exp)%10]++;
    }
    for(int i =1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    for(int i = n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1]= arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i = 0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
void radixSort(int *arr,int n)
{
    int m = getMax(arr,n);
    for(int exp = 1;m/exp>0;exp*=10)
    {
        count_sort(arr,n,exp);
    }
}
void print(int *arr,int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    radixSort(arr,n);
    print(arr,n);
    return 0;
}