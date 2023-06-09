#include <stdio.h>

void NextValue(int k, int x[], int n, int m, int G[100][100])
{
    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return; // If all colors are used
        int j;
        for (j = 1; j <= n; j++)
        {
            if (G[k][j] != 0 && x[j] == x[k])
                break;
        }
        if (j == n + 1)
            return;
    }
}

void mColoring(int k, int x[], int n, int m, int G[100][100])
{
    while (1)
    {
        NextValue(k, x, n, m, G);
        if (x[k] == 0)
            return;
        if (k == n)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", x[i]);
            }
            printf("\n");
        }
        else
            mColoring(k + 1, x, n, m, G);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int G[100][100];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            scanf("%d", &G[i][j]);
    }
    int x[n + 1];
    for (int i = 1; i <= n; i++)
        x[i] = 0;
    mColoring(1, x, n, 3, G);

    return 0;
}

// 1---2
// |   |
// 3---4