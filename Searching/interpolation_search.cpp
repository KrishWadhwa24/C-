#include<bits/stdc++.h>
using namespace std;
int interpolation(int* arr,int size,int target)
{
    int low = 0;
    int high = size-1;
    while(target>=arr[low] && target<=arr[high] && low<=high)
    {
         int pos = low +(high-low)*(target-arr[low])/(arr[high]-arr[low]);
         if(arr[pos]==target)
         {
            return pos;
         }else
         {
            if(arr[pos]<target)
            {
                low = pos+1;
            }else
            {
                high = pos-1;
            }
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
    int target;
    cout<<"Enter the element to be searched\n";
    cin>>target;
    int index = interpolation(arr,n,target);
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