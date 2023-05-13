//0/1 knapsack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int KnapSack(int n, int M, int *w, int *p)
{
    int T[n + 1][M + 1];
    int i, j;

    memset(T, 0, sizeof(T));

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= M; j++)
        {
            if (w[i] > j)
            {
                T[i][j] = T[i - 1][j];
            }
            else
            {
                T[i][j] = T[i - 1][j] > p[i] + T[i - 1][j - w[i]] ? T[i - 1][j] : p[i] + T[i - 1][j - w[i]];
            }
        }
    }

    int x[n + 1];
    memset(x, 0, sizeof(x));
    j = M;

    for (i = n; i >= 1; i--)
    {
        if (T[i][j] == T[i - 1][j])
        {
            x[i] = 0;
        }
        else
        {
            x[i] = 1;
            j -= w[i];
        }
    }

    printf("x: ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");

    return T[n][M];
}

int main()
{

    int n, M;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &M);

    int w[n + 1], p[n + 1];

    printf("Enter the weight and profit of each item:\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &w[i], &p[i]);
    }

    printf("%d\n", KnapSack(n, M, w, p));

    return 0;
}