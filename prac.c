#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lcs(char *s1, char *s2, int m, int n, int **dp)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i][j - 1] > dp[i - 1][j]) ? dp[i][j - 1] : dp[i - 1][j];
        }
    }
    return dp[m][n];
}

void print_lcs(int **dp, char *s1, char *s2, int i, int j)
{
    if (dp[i][j] == 0)
        return;
    if (s1[i - 1] == s2[j - 1])
    {
        print_lcs(dp, s1, s2, i - 1, j - 1);
        printf("%c", s1[i - 1]);
    }
    else if (dp[i][j - 1] > dp[i - 1][j])
        print_lcs(dp, s1, s2, i, j - 1);
    else
        print_lcs(dp, s1, s2, i - 1, j);
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
    printf("%d\n", lcs(s1, s2, m, n, dp));
    print_lcs(dp, s1, s2, m, n);

    for (int i = 0; i <= m; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return 0;
}
