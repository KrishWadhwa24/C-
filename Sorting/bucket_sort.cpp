#include <iostream>
#include <algorithm>
using namespace std;
void insertionSort(float *bucket, int size)
{
    for (int i = 1; i < size; i++)
    {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}
void bucketSort(float *arr, int n)
{
    if (n <= 0)
        return;
    int bucketSize[n] = {0};
    float *buckets[n];
    for (int i = 0; i < n; i++)
    {
        buckets[i] = new float[n];
    }
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex][bucketSize[bucketIndex]++] = arr[i];
    }
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (bucketSize[i] > 0)
        {
            insertionSort(buckets[i], bucketSize[i]);
            for (int j = 0; j < bucketSize[i]; j++)
            {
                arr[index++] = buckets[i][j];
            }
        }
        delete[] buckets[i];
    }
}
int main()
{
    int n;
    cin >> n;
    float *arr = new float[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bucketSort(arr, n);
    cout << "The sorted array is\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}