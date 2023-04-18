#include <stdio.h>
#include <string.h>

char b[100][100];
void mergeSort(char arr[6][100], int low, int high);
void merge(char arr[6][100], int low, int mid, int high);

int main()
{
    char arr[6][100] = {"Srinivas", "Lakshmi", "Gopi", "Krishna", "Rama", "Partha"};
    mergeSort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        printf("%s ", arr[i]);
    }

    return 0;
}

void mergeSort(char arr[6][100], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(char arr[6][100], int low, int mid, int high)
{
    int i = low;
    int h = low;
    int j = mid + 1;

    while ((h <= mid) && (j <= high))
    {
        if (strcmp(arr[h], arr[j]) <= 0)
        {
            strcpy(b[i], arr[h]);
            h++;
        }
        else
        {
            strcpy(b[i], arr[j]);
            j++;
        }
        i++;
    }
    if (h > mid)
    {
        for (int k = j; k <= high; k++)
        {
            strcpy(b[i], arr[k]);
            i++;
        }
    }
    else
    {
        for (int k = h; k <= mid; k++)
        {
            strcpy(b[i], arr[k]);
            i++;
        }
    }
    for (int i = low; i <= high; i++)
    {
        strcpy(arr[i], b[i]);
    }
}