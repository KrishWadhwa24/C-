#include<iostream>
using namespace std;
int linear(int *arr,int l,int r,int x)
{
    if(l>r)
    {
        return -1;
    }
    if(arr[l]==x)
    {
        return l;
    }else
    {
        return linear(arr,l+1,r,x);
    }
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
    int x;
    cout<<"Enter the element to be searched:"<<endl;
    cin>>x;
    int index = linear(arr,0,n-1,x);
    if(index==-1)
    {
        cout<<"Element not found"<<endl;
    }else
    {
        cout<<"Element found at index "<<index<<endl;
    }
}