#include <stdio.h>

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int n1, n2;
    printf("Enter n1, n2: ");
    scanf("%d", &n1);
    scanf("%d", &n2);
    int a[n1];
    int b[n2];
    printf("Enter a elements: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter b elements: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }
    int res[n1 + n2];
    insertionSort(a, n1);
    insertionSort(b, n2);
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            res[k++] = a[i++];
        }
        else if (a[i] > b[j])
        {
        }
        else if (a[i] == b[j])
        {
            j++;
        }
    }
    while (i < n1)
    {
        res[k++] = a[i++];
    }
    while (j < n2)
    {
        res[k++] = b[j++];
    }
    for (int t = 0; t < k; t++)
    {
        printf("%d ", res[t]);
    }

    return 0;
}

// 1 2 3
// 1 3 4 5