// str1 to str2 conversion
#include <stdio.h>
#include <string.h>

int m, n;

int min(int a, int b, int c)
{
    return a < b && a < c ? a : (b < c ? b : c);
}

int minEdit(char *s1, char *s2, int dp[m + 1][n + 1])
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

void print_lcs(char *s1, char *s2, int dp[m + 1][n + 1], int i, int j)
{
    if (dp[i][j] == 0)
        return;
    if (min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) == dp[i - 1][j - 1])
    {
        print_lcs(s1, s2, dp, i - 1, j - 1);
        if (s1[i - 1] != s2[j - 1])
            printf("%c in s1 was replaced with %c \n", s1[i - 1], s2[j - 1]);
    }
    else if (min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) == dp[i - 1][j])
    {
        print_lcs(s1, s2, dp, i - 1, j);
        printf("%c in s1 was deleted \n", s1[i - 1]);
    }
    else
    {
        print_lcs(s1, s2, dp, i, j - 1);
        printf("%c was inserted in s1\n", s2[j - 1]);
    }
}

int main()
{
    char s1[100], s2[100];
    scanf("%s%s", s1, s2);
    m = strlen(s1);
    n = strlen(s2);
    int dp[m + 1][n + 1];
    printf("%d\n", minEdit(s1, s2, dp));
    print_lcs(s1, s2, dp, m, n);

    return 0;
}

// m , n
/*
m -> n-1(insert)
m-1 -> n-1(replace)
m-1 -> n (delete)




*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int min(int x, int y, int z)
// {
//     return ((x < y) && (x < z)) ? x : ((y < z) ? y : z);
// }

// int editDistDP(char *str1, char *str2, int m, int n)
// {
//     int dp[m + 1][n + 1];

//     for (int i = 0; i <= m; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {

//             if (i == 0)
//                 dp[i][j] = j;
//             else if (j == 0)
//                 dp[i][j] = i;

//             else if (str1[i - 1] == str2[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1];

//             else
//                 dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
//         }
//     }

//     return dp[m][n];
// }

// int main()
// {
//     char str1[100];
//     char str2[100];
//     scanf("%s", str1);
//     scanf("%s", str2);
//     int m = strlen(str1);
//     int n = strlen(str2);

//     printf("%d\n", editDistDP(str1, str2, m, n));

//     return 0;
// }
