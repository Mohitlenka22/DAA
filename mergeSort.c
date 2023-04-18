#include <stdio.h>

// Global array
int b[100];

void Merge(int arr[], int l, int m, int h)
{
    int i, j, k;
    i = l;
    j = l;
    k = m + 1;
    while (j <= m && k <= h)
    {
        if (arr[j] <= arr[k])
        {
            b[i] = arr[j];
            j++;
        }
        else
        {
            b[i] = arr[k];
            k++;
        }
        i++;
    }
    if (j > m)
    {
        for (int z = k; z <= h; z++)
        {
            b[i] = arr[z];
            i++;
        }
    }
    else
    {
        for (int z = j; z <= m; z++)
        {
            b[i] = arr[z];
            i++;
        }
    }
    for (int z = l; z <= h; z++)
    {
        arr[z] = b[z];
    }
}

void MergeSort(int arr[], int l, int h)
{
    if (h > l)
    {
        int mid = (l + h) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, h);
        Merge(arr, l, mid, h);
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
    MergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}