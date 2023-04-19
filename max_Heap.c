#include <stdio.h>

void maxHeapify(int arr[], int n, int i);
void swap(int *a, int *b);
void buildHeap(int arr[], int n);
int size;

int main()
{
    int arr[] = {40, 80, 35, 90, 45, 50, 70};
    size = sizeof(arr) / sizeof(arr[0]);
    buildHeap(arr, size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i, lft = 2 * i + 1, rgt = 2 * i + 2;
    if (lft < n && arr[lft] > arr[largest])
        largest = lft;
    if (rgt < n && arr[rgt] > arr[largest])
        largest = rgt;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
    for (int i = size - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}