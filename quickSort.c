#include <stdio.h>

int partition(int a[], int l, int h)
{
    int t = a[l];
    int lp = l + 1, rp = h - 1;
    while (lp <= rp)
    {
        while (a[lp] <= t)
            lp++;
        while (a[rp] > t)
            rp--;
        if (lp < rp)
        {
            int temp = a[lp];
            a[lp] = a[rp];
            a[rp] = temp;
        }
    }
    a[l] = a[rp];
    a[rp] = t;
    return rp;
}

void qsort(int a[], int l, int h)
{
    if (h > l)
    {
        int p = partition(a, l, h + 1);
        qsort(a, l, p - 1);
        qsort(a, p + 1, h);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}


// #include <stdio.h>

// int partition(int arr[], int l, int h)
// {
//     int pivot = arr[l];
//     int i = l - 1;
//     int j = h + 1;
//     while (i <= j)
//     {
//         do
//         {
//             i++;
//         } while (arr[i] < pivot);
//         do
//         {
//             j--;
//         } while (arr[j] > pivot);
//         if (i >= j)
//             return j;
//         int t = arr[i];
//         arr[i] = arr[j];
//         arr[j] = t;
//     }
// }

// void qsort(int arr[], int l, int h)
// {
//     if (h > l)
//     {
//         int pi = partition(arr, l, h);
//         qsort(arr, l, pi);
//         qsort(arr, pi + 1, h);
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
//     qsort(arr, 0, n - 1);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }
