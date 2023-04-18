#include <stdio.h>

int binsearch(int arr[], int low, int high, int x);

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
    int x;
    printf("Enter key: ");
    scanf("%d", &x);
    printf("%d", binsearch(arr, 0, n - 1, x));

    return 0;
}

int binsearch(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    else
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return binsearch(arr, low, mid - 1, x);
        else
            return binsearch(arr, mid + 1, high, x);
    }
}