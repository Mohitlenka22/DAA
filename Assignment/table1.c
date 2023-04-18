#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int flg;
    int dept;
    char dest[100];
} table;

void mergeSort(table arr[], int low, int high);
int merge(table arr[], int low, int mid, int high);

void qsort(table arr[], int low, int high);
int partition(table arr[], int low, int high);

table b[100];

int main()
{
    int n = 5;
    table arr[5] = {{1, 11, "Delhi"},
                    {2, 10, "Mumbai"},
                    {3, 13, "Delhi"},
                    {4, 9, "Mumbai"},
                    {5, 12, "Mumbai"}};
    mergeSort(arr, 0, n - 1);
    printf("Result after first sorting: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %s\n", arr[i].flg, arr[i].dept, arr[i].dest);
    }
    qsort(arr, 0, n - 1);
    printf("Result after second sorting: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %s\n", arr[i].flg, arr[i].dept, arr[i].dest);
    }

    return 0;
}

// First sorting
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
        if (arr[h].dept <= arr[j].dept)
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

// Second Sorting
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
    char pivot[100];
    strcpy(pivot, arr[low].dest);
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (strcmp(arr[i].dest, pivot) < 0);
        do
        {
            j--;
        } while (strcmp(arr[j].dest, pivot) > 0);

        if (i >= j)
            return j;
        table t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}