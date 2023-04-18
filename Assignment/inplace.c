// A sort algorithm in which the sorted items occupy the same storage as the original ones. These algorithms may use o(n) additional memory for bookkeeping, but at most a constant number of items are kept in auxiliary memory at any time.

#include <stdio.h>
#include <stdbool.h>

int qsort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

int qsort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        qsort(arr, low, p);
        qsort(arr, p + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}