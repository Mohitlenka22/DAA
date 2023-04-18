#include <stdio.h>

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l - 1;
    int j = h + 1;
    while (i <= j)
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

void qsort(int arr[], int l, int h)
{
    if (h > l)
    {
        int pi = partition(arr, l, h);
        qsort(arr, l, pi);
        qsort(arr, pi + 1, h);
    }
}

int main()
{
    int n;
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
