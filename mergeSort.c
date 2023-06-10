#include <stdio.h>

int b[100];

void Merge(int a[], int low, int mid, int high)
{
    int i = low, h = low, j = mid + 1;
    while ((h <= mid) && (j <= high))
    {
        if (a[h] <= a[j])
            b[i++] = a[h++];
        else
            b[i++] = a[j++];
    }
    if (h > mid)
    {
        for (int k = j; k <= high; k++)
            b[i++] = a[k];
    }
    else
    {
        for (int k = h; k <= mid; k++)
            b[i++] = a[k];
    }
    for (int k = low; k <= high; k++)
        a[k] = b[k];
}

void MergeSort(int a[], int low, int high)
{
    if (high > low)
    {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    MergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}


// #include <stdio.h>

// // Global array
// int b[100];

// void Merge(int arr[], int l, int m, int h)
// {
//     int i, j, k;
//     i = l;
//     j = l;
//     k = m + 1;
//     while (j <= m && k <= h)
//     {
//         if (arr[j] <= arr[k])
//         {
//             b[i] = arr[j];
//             j++;
//         }
//         else
//         {
//             b[i] = arr[k];
//             k++;
//         }
//         i++;
//     }
//     if (j > m)
//     {
//         for (int z = k; z <= h; z++)
//         {
//             b[i] = arr[z];
//             i++;
//         }
//     }
//     else
//     {
//         for (int z = j; z <= m; z++)
//         {
//             b[i] = arr[z];
//             i++;
//         }
//     }
//     for (int z = l; z <= h; z++)
//     {
//         arr[z] = b[z];
//     }
// }

// void MergeSort(int arr[], int l, int h)
// {
//     if (h > l)
//     {
//         int mid = (l + h) / 2;
//         MergeSort(arr, l, mid);
//         MergeSort(arr, mid + 1, h);
//         Merge(arr, l, mid, h);
//     }
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     MergeSort(arr, 0, n - 1);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }