#include <stdio.h>

int Maxmin(int arr[], int low, int high);
int max, min;

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    Maxmin(arr, 0, n - 1);
    printf("max: %d, min: %d", max, min);

    return 0;
}

int Maxmin(int arr[], int low, int high)
{
    if (low == high)
    {
        max = min = arr[low];
    }
    else if (low == high - 1)
    {
        if (arr[low] > arr[high])
        {
            min = arr[high];
            max = arr[low];
        }
        else
        {
            min = arr[low];
            max = arr[high];
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
        {
            max = max1;
        }
        if (min1 < min)
        {
            min = min1;
        }
    }
}