#include<bits/stdc++.h>
using namespace std;
int linear_search(int* arr,int n,int key)
{
    for(int i = 0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
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
    int key;
    cout<<"Enter the element to be searched\n";
    cin>>key;
    int index = linear_search(arr,n,key);
    if(index==-1)
    {
        cout<<"Element not found\n";
    }
    else
    {
        cout<<"Element found at index "<<index<<endl;
    }
    return 0;
}