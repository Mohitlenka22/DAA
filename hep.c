#include <stdio.h>


void Heapify(int A[], int n);
void Adjust(int A[], int i, int n);

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int A[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }
    Heapify(A, n);

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n"); // Add newline character
    return 0;
}

void Heapify(int A[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        Adjust(A, i, n);
    }
}

void Adjust(int A[], int i, int n)
{
    int j = 2 * i; // Left child of i
    int item;
    item = A[i];
    while (j <= n)
    {
        if ((j < n) && (A[j] < A[j + 1])) // compare left and right child
        {
            j = j + 1; // and let j be the right child.
        }
        if (item >= A[j])
            break;       // position for item is found which is j/2.
        A[j / 2] = A[j]; // move the A[j] up
        j = 2 * j;       // Left child of j
    }
    A[j / 2] = item;
}
