#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lcs(int *s1, int m, int *s2, int n, int **dp)
{
    int i, j;
    for (i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (i = 0; i <= n; i++)
        dp[0][i] = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    return dp[m][n];
}

void PRINT_LCS(int **dp, int *s1, int *s2, int m, int n)
{
    if (dp[m][n] == 0)
        return;
    if (s1[m - 1] == s2[n - 1])
    {
        PRINT_LCS(dp, s1, s2, m - 1, n - 1);
        printf("%c", s1[m - 1]);
    }
    else if (dp[m - 1][n] > dp[m][n - 1])
        PRINT_LCS(dp, s1, s2, m - 1, n);
    else
        PRINT_LCS(dp, s1, s2, m, n - 1);
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

int main()
{
    int n
    int  s1[100], s2[100];
    
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i < n; i++)
        dp[i] = (int *)malloc(sizeof(int) * (n + 1));

    printf("%d\n", lcs(s1, m, s2, n, dp));

    PRINT_LCS(dp, s1, s2, m, n);

    for (int i = 0; i < n; i++)
        free(dp[i]);
    free(dp);

    return 0;
}