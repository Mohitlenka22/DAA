#include <stdio.h>
#include <string.h>

void SubsetSum(int s, int k, int r, int x[], int w[], int m, int n)
{

    x[k] = 1;
    if (s + w[k] == m)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", x[i]);
        }
        printf("\n");
    }
    else if ((s + w[k] + w[k + 1]) <= m)
    {
        SubsetSum(s + w[k], k + 1, r - w[k], x, w, m, n);
    }
    if (((s + r - w[k]) >= m) && ((s + w[k + 1]) <= m))
    {
        x[k] = 0;
        SubsetSum(s, k + 1, r , x, w, m, n);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int w[n + 1];
    int x[n + 1];
    int totSum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        totSum += w[i];
        x[i] = 0;
    }
    int m;
    scanf("%d", &m);
    SubsetSum(0, 1, totSum, x, w, m, n);

    return 0;
}