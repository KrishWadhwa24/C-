#include<bits/stdc++.h>
using namespace std;
void sort(int* arr,int size)
{
    for(int i = 0;i<size-1;i++)
    {
        int min = i;
        for(int j = i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            int temp = arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}
void print(int* arr,int size)
{
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    print(arr,n);
    return 0;
}