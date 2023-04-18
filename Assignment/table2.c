#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int flg;
    int dept;
    char dest[100];
} table;

void qsort(table arr[], int low, int high);
int partition(table arr[], int low, int high);

void mergeSort(table arr[], int low, int high);
int merge(table arr[], int low, int mid, int high);

table b[100];

int main()
{
    int n = 5;
    table arr[5] = {{1, 11, "Delhi"},
                    {2, 10, "Mumbai"},
                    {3, 13, "Delhi"},
                    {4, 9, "Mumbai"},
                    {5, 12, "Mumbai"}};
    qsort(arr, 0, n - 1);
    printf("Result after first sorting: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %s\n", arr[i].flg, arr[i].dept, arr[i].dest);
    }
    mergeSort(arr, 0, n - 1);
    printf("Result after second sorting: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %s\n", arr[i].flg, arr[i].dept, arr[i].dest);
    }

    return 0;
}

// First sorting

void qsort(table arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        qsort(arr, low, p);
        qsort(arr, p + 1, high);
    }
}

int partition(table arr[], int low, int high)
{
    int pivot = arr[low].dept;
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i].dept < pivot);
        do
        {
            j--;
        } while (arr[j].dept > pivot);

        if (i >= j)
            return j;
        table t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

// Second Sorting

void mergeSort(table arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int merge(table arr[], int low, int mid, int high)
{
    int i = low;
    int h = low;
    int j = mid + 1;

    while ((h <= mid) && (j <= high))
    {
        if (strcmp(arr[h].dest, arr[j].dest) <= 0)
        {
            b[i] = arr[h];
            h++;
        }
        else
        {
            b[i] = arr[j];
            j++;
        }
        i++;
    }
    if (h > mid)
    {
        for (int k = j; k <= high; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }
    else
    {
        for (int k = h; k <= mid; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = b[i];
    }
}