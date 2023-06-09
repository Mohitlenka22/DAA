#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int x, int y, int z)
{
    return (x < y && x < z) ? x : ((y < z) ? y : z);
}

int minEdit(char *s1, char *s2, int m, int n, int **dp)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            if (j == 0)
                dp[i][j] = i;
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    return dp[m][n];
}

int main()
{
    char s1[100], s2[100];
    scanf("%s%s", s1, s2);
    int m = strlen(s1);
    int n = strlen(s2);
    int **dp = (int **)malloc(sizeof(int *) * (m + 1));
    for (int i = 0; i <= m; i++)
    {
        dp[i] = (int *)malloc(sizeof(int) * (n + 1));
        memset(dp[i], 0, sizeof(int) * (n + 1));
    }
    printf("%d", minEdit(s1, s2, m, n, dp));
    for (int i = 0; i <= m; i++)
        free(dp[i]);
    free(dp);

    return 0;
}