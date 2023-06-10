#include <stdio.h>

int n;

void prim(int cost[n][n])
{
    int t[n - 1][2];
    int near[n], k, l, i, j, mincost;
    //(k, l) is a edge with min weight
    k = l = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (cost[i][j] < cost[k][l])
            {
                k = i;
                l = j;
            }
        }
    }

    // Add edge to the MST
    t[0][0] = k;
    t[0][1] = l;
    mincost = cost[k][l];

    // Initilaize the near array
    for (i = 0; i < n; i++)
    {
        if (cost[i][l] < cost[i][k])
            near[i] = l;
        else
            near[i] = k;
    }
    near[k] = near[l] = -1;

    // Find remaining n-2 edges
    for (i = 1; i < n - 1; i++)
    {
        j = 0;
        while (near[j] == -1)
            j++;
        for (int k = j; k < n; k++)
        {
            if (near[k] != -1 && cost[k][near[k]] < cost[j][near[j]])
                j = k;
        }

        t[i][0] = j;
        t[i][1] = near[j];
        mincost += cost[j][near[j]];
        near[j] = -1;

        // update near array
        for (int k = 0; k < n; k++)
        {
            if (near[k] != -1 && cost[k][near[k]] > cost[k][j])
                near[k] = j;
        }
    }

    printf("%d\n", mincost);
    for (i = 0; i < n - 1; i++)
    {
        printf("(%d, %d) with cost: %d\n", t[i][0], t[i][1], cost[t[i][0]][t[i][1]]);
    }
}

int main()
{
    scanf("%d", &n);
    int cost[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == -1)
                cost[i][j] = 1e9;
        }
    }
    prim(cost);
    return 0;
}

// #include <stdio.h>
// #include <limits.h>

// #define MAX_N 100
// #define INF INT_MAX

// void prim(int n, int cost[MAX_N][MAX_N], int t[MAX_N - 1][2])
// {
//     int near[MAX_N], mincost = 0, k, l, i, j;

//     // Find an edge of minimum cost
//     k = l = 0;
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < n; j++)
//         {
//             if (cost[i][j] < cost[k][l])
//             {
//                 k = i;
//                 l = j;
//             }
//         }
//     }

//     // Add the edge to the minimum spanning tree
//     t[0][0] = k;
//     t[0][1] = l;
//     mincost = cost[k][l];

//     // Initialize the near[] array
//     for (i = 0; i < n; i++)
//     {
//         if (cost[i][l] < cost[i][k])
//         {
//             near[i] = l;
//         }
//         else
//         {
//             near[i] = k;
//         }
//     }
//     near[k] = near[l] = -1;

//     // Find the n-2 remaining edges
//     for (i = 1; i < n - 1; i++)
//     {
//         j = 0;
//         while (near[j] == -1)
//         {
//             j++;
//         }
//         for (k = j; k < n; k++)
//         {
//             if (near[k] != -1 && cost[k][near[k]] < cost[j][near[j]])
//             {
//                 j = k;
//             }
//         }

//         // Add the edge to the minimum spanning tree
//         t[i][0] = j;
//         t[i][1] = near[j];
//         mincost += cost[j][near[j]];
//         near[j] = -1;

//         // Update the near[] array
//         for (k = 0; k < n; k++)
//         {
//             if (near[k] != -1 && cost[k][near[k]] > cost[k][j])
//             {
//                 near[k] = j;
//             }
//         }
//     }

//     printf("Minimum cost: %d\n", mincost);
//     printf("Minimum spanning tree:\n");
//     for (i = 0; i < n - 1; i++)
//     {
//         printf("(%d, %d) with cost: %d\n", t[i][0], t[i][1], cost[t[i][0]][t[i][1]]);
//     }
// }

// int main()
// {
//     int n = 5;
//     int cost[MAX_N][MAX_N];
//     int t[MAX_N - 1][2];
//     printf("Enter n: ");
//     scanf("%d", &n);
//     printf("Enter cost adjacency matrix:\n");
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &cost[i][j]);
//             if (cost[i][j] == -1)
//                 cost[i][j] = INF;
//         }
//     }

//     prim(n, cost, t);
//     return 0;
// }
