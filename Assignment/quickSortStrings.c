#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void qsort(char arr[6][100], int low, int high);
int partition(char arr[6][100], int low, int high);

int main()
{
    char arr[6][100] = {"Srinivas", "Lakshmi", "Gopi", "Krishna", "Rama", "Partha"};
    qsort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        printf("%s ", arr[i]);
    }
    return 0;
}

void qsort(char arr[6][100], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        qsort(arr, low, p);
        qsort(arr, p + 1, high);
    }
}

int partition(char arr[6][100], int low, int high)
{
    char pivot[100];
    strcpy(pivot, arr[low]);
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (strcmp(arr[i], pivot) < 0);
        do
        {
            j--;
        } while (strcmp(arr[j], pivot) > 0);

        if (i >= j)
            return j;
        char t[100];
        strcpy(t, arr[i]);
        strcpy(arr[i], arr[j]);
        strcpy(arr[j], t);
    }
}