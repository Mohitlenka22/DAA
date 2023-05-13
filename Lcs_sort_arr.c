// Longest increasing subsequence in array
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lcs(int *s1, int n, int *s2, int **dp)
{
    int i, j;

    for (i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[n][n];
}

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PRINT_LCS(int **dp, int *x, int *y, int i, int j)
{
    if (dp[i][j] == 0)
        return;
    if (x[i - 1] == y[j - 1])
    {
        PRINT_LCS(dp, x, y, i - 1, j - 1);
        printf("%d ", x[i - 1]);
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
        PRINT_LCS(dp, x, y, i - 1, j);
    else
        PRINT_LCS(dp, x, y, i, j - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    int s1[n], s2[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &s1[i]);
    for (int i = 0; i < n; i++)
    {
        s2[i] = s1[i];
    }
    insertionSort(s2, n);

    // memo-table
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
        memset(dp[i], 0, (n + 1) * sizeof(int));
    }

    printf("%d\n", lcs(s1, n, s2, dp));
    PRINT_LCS(dp, s1, s2, n, n);

    // free memory
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return 0;
}
