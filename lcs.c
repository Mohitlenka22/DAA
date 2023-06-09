//lcs
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int lcs(char *s1, int m, char *s2, int n, int **dp) {
    int i, j;

    for (i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }

    for (i = 0; i <= n; i++) {
        dp[0][i] = 0;
    }

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

void PRINT_LCS(int **c, char *X, char *Y, int i, int j)
{
    if (c[i][j] == 0)
    {
        return;
    }
    if (X[i - 1] == Y[j - 1])
    {
        PRINT_LCS(c, X, Y, i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if (c[i - 1][j] > c[i][j - 1])
    {
        PRINT_LCS(c, X, Y, i - 1, j);
    }
    else
    {
        PRINT_LCS(c, X, Y, i, j - 1);
    }
}

int main() {
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);
    int m = strlen(s1);
    int n = strlen(s2);

    
    int **dp = (int **) malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *) malloc((n + 1) * sizeof(int));
        memset(dp[i], 0, (n + 1) * sizeof(int));
    }

    printf("%d\n", lcs(s1, m, s2, n, dp));
    PRINT_LCS(dp, s1, s2, m, n);
    
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return 0;
}
