#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int flg;
    int dept;
    char dest[100];
} table;

void qsortInt(table arr[], int low, int high);
int partitionInt(table arr[], int low, int high);
void qsortString(table arr[], int low, int high);
int partitionString(table arr[], int low, int high);

table b[100];

int main()
{
    int n = 5;
    table arr[5] = {{1, 11, "Delhi"},
                    {2, 10, "Mumbai"},
                    {3, 13, "Delhi"},
                    {4, 9, "Mumbai"},
                    {5, 12, "Mumbai"}};
    qsortInt(arr, 0, n - 1);
    printf("Result after first sorting: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %s\n", arr[i].flg, arr[i].dept, arr[i].dest);
    }
    qsortString(arr, 0, n - 1);
    printf("Result after second sorting: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %s\n", arr[i].flg, arr[i].dept, arr[i].dest);
    }

    return 0;
}

// First sorting
void qsortInt(table arr[], int low, int high)
{
    if (low < high)
    {
        int p = partitionInt(arr, low, high);
        qsortInt(arr, low, p);
        qsortInt(arr, p + 1, high);
    }
}

int partitionInt(table arr[], int low, int high)
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
void qsortString(table arr[], int low, int high)
{
    if (low < high)
    {
        int p = partitionString(arr, low, high);
        qsortString(arr, low, p);
        qsortString(arr, p + 1, high);
    }
}

int partitionString(table arr[], int low, int high)
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