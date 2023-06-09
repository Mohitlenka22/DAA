#include <stdio.h>

int max, min;

int Maxmin(int arr[], int low, int high)
{
    if (low == high)
        max = min = arr[low];
    else if (low == high - 1)
    {
        if (arr[low] > arr[high])
        {
            max = arr[low];
            min = arr[high];
        }
        else
        {
            max = arr[high];
            min = arr[low];
        }
    }
    else
    {
        int mid = (low + high) / 2;
        Maxmin(arr, low, mid);
        int max1, min1;
        max1 = max;
        min1 = min;
        Maxmin(arr, mid + 1, high);

        if (max1 > max)
            max = max1;
        if (min1 < min)
            min = min1;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    Maxmin(arr, 0, n - 1);
    printf("max: %d && min: %d", max, min);
    return 0;
}