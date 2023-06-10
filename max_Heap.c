#include <stdio.h>

int n;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapify(int arr[], int size, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2, largest = i;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        maxHeapify(arr, size, largest);
    }
}

void buildHeap(int arr[])
{
    for (int i = (n - 2) / 2; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void Heapsort(int arr[])
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int delmax(int arr[])
{
    if (n == 0)
        return -1;
    if (n == 1)
    {
        n--;
        return arr[0];
    }
    int ret = arr[0];
    swap(&arr[0], &arr[n - 1]);
    n--;
    maxHeapify(arr, n, 0);
    return ret;
}

int main()
{
    n = 7;
    int arr[] = {0, 1, 3, 1, 2, 56, 89};
    buildHeap(arr);
    Heapsort(arr);
    // printf("%d\n", delmax(arr));
    // printf("%d\n", delmax(arr));
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

// #include <stdio.h>

// void maxHeapify(int arr[], int n, int i);
// void swap(int *a, int *b);
// void buildHeap(int arr[], int n);
// void Heapsort(int arr[]);
// int size;

// int main()
// {
//     int arr[] = {80, 77, 34, 56, 23, 10};
//     size = sizeof(arr) / sizeof(arr[0]);
//     buildHeap(arr, size);
//     Heapsort(arr);
//     for (int i = 0; i < size; i++)
//         printf("%d ", arr[i]);
//     return 0;
// }

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void maxHeapify(int arr[], int n, int i)
// {
//     int largest = i, lft = 2 * i + 1, rgt = 2 * i + 2;
//     if (lft < n && arr[lft] > arr[largest])
//         largest = lft;
//     if (rgt < n && arr[rgt] > arr[largest])
//         largest = rgt;
//     if (largest != i)
//     {
//         swap(&arr[i], &arr[largest]);
//         maxHeapify(arr, n, largest);
//     }
// }

// void buildHeap(int arr[], int n)
// {
//     for (int i = (n / 2) - 1; i >= 0; i--)
//         maxHeapify(arr, n, i);
// }

// void Heapsort(int arr[])
// {
//     // heap sort`
//     for (int i = size - 1; i >= 0; i--)
//     {
//         swap(&arr[0], &arr[i]);
//         maxHeapify(arr, i, 0);
//     }
// }