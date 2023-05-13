//str1 to str2 conversion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int min(int x, int y, int z) {
    return ((x < y) && (x < z)) ? x : ((y < z) ? y : z);
}

int editDistDP(char *str1, char *str2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;

            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    char str1[100];
    char str2[100];
    scanf("%s", str1);
    scanf("%s", str2);
    int m = strlen(str1);
    int n = strlen(str2);

    printf("%d\n", editDistDP(str1, str2, m, n));

    return 0;
}
