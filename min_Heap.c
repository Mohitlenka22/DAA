#include <stdio.h>

void minHeapify(int arr[], int n, int i);
void swap(int *a, int *b);
void buildHeap(int arr[], int n);
int extract_min(int arr[]);

int size;

int main()
{
    int arr[] = {40, 80, 35, 90, 45, 50, 70};
    size = sizeof(arr) / sizeof(arr[0]);
    buildHeap(arr, size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("%d\n", extract_min(arr));
    printf("%d\n", extract_min(arr));
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

void minHeapify(int arr[], int n, int i)
{
    int smallest = i, lft = 2 * i + 1, rgt = 2 * i + 2;
    if (lft < n && arr[lft] < arr[smallest])
        smallest = lft;
    if (rgt < n && arr[rgt] < arr[smallest])
        smallest = rgt;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
        minHeapify(arr, n, i);
}

int extract_min(int arr[])
{
    if (size == 0)
        return -1;
    if (size == 1)
    {
        size--;
        return arr[0];
    }
    int ans = arr[0];
    swap(&arr[0], &arr[size - 1]);
    size--;
    minHeapify(arr, size, 0);

    return ans;
}