#include <stdio.h>

int n;

void ShortestPath(int v, int cost[n][n], int dist[], int predecessor[])
{
    int s[n];
    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
        dist[i] = cost[v][i];
        if (cost[v][i] < 1e9)
            predecessor[i] = v;
        else
            predecessor[i] = -1;
    }
    s[v] = 1;
    dist[v] = 0;
    predecessor[v] = -1;

    // Discover n-1 vertices
    for (int j = 2; j <= n; j++)
    {
        int u = -1;
        int min_dist = 1e9;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 0 && dist[i] < min_dist)
            {
                u = i;
                min_dist = dist[i];
            }
        }
        s[u] = 1;
        for (int w = 0; w < n; w++)
        {
            if (s[w] == 0 && cost[u][w] < 1e9)
            {
                if (dist[w] > (dist[u] + cost[u][w]))
                {
                    dist[w] = dist[u] + cost[u][w];
                    predecessor[w] = u;
                }
            }
        }
    }
}

void printPath(int s, int v, int predecessor[])
{
    if (s == v)
    {
        printf("(%d", s);
    }
    else if (predecessor[v] == -1)
    {
        printf("No path");
    }
    else
    {
        printPath(s, predecessor[v], predecessor);
        printf("-> %d", v);
    }
}

int main()
{
    scanf("%d", &n);
    int v;
    int cost[n][n];
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == -1)
                cost[i][j] = 1e9;
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &v);
    int dist[n];
    int predecessor[n];
    ShortestPath(0, cost, dist, predecessor);

    for (int i = 0; i < n; i++)
    {
        printf("Shortest Path from %d to %d ", 0, i);
        if (dist[i] == 1e9)
            printf("No path");
        else
            printf("%d: ", dist[i]);
        printPath(0, i, predecessor);
        printf(")\n");
    }

    return 0;
}

// #include <stdio.h>
// #include <limits.h>

// void ShortestPaths(int v, int cost[100][100], int dist[], int predecessor[], int n)
// {
//     int S[n];
//     for (int i = 0; i < n; i++)
//     {
//         S[i] = 0;
//         dist[i] = cost[v][i];
//         if (cost[v][i] < INT_MAX)
//             predecessor[i] = v;
//         else
//             predecessor[i] = -1;
//     }
//     S[v] = 1;
//     predecessor[v] = -1;
//     dist[v] = 0;
//     for (int j = 2; j <= n; j++)
//     {
//         int u = -1;
//         int min_dist = INT_MAX;
//         for (int i = 0; i < n; i++)
//         {
//             if (S[i] == 0 && dist[i] < min_dist)
//             {
//                 u = i;
//                 min_dist = dist[i];
//             }
//         }
//         S[u] = 1;
//         for (int w = 0; w < n; w++)
//         {
//             if (S[w] == 0 && cost[u][w] < INT_MAX)
//             {
//                 if (dist[w] > (dist[u] + cost[u][w]))
//                 {
//                     dist[w] = dist[u] + cost[u][w];
//                     predecessor[w] = u;
//                 }
//             }
//         }
//     }
// }

// void PrintPath(int s, int v, int predecessor[])
// {
//     if (v == s)
//     {
//         printf("%d", s);
//     }
//     else if (predecessor[v] == -1)
//     {
//         printf("No path");
//     }
//     else
//     {
//         PrintPath(s, predecessor[v], predecessor);
//         printf(" -> %d", v);
//     }
// }

// int main()
// {
//     int n, v;
//     printf("Enter the number of vertices: ");
//     scanf("%d", &n);
//     int cost[100][100];
//     printf("Enter the cost adjacency matrix:\n");
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &cost[i][j]);
//             if (cost[i][j] == -1)
//                 cost[i][j] = INT_MAX;
//         }
//     }
//     printf("Enter the source vertex: ");
//     scanf("%d", &v);
//     int dist[n];
//     int predecessor[n];
//     ShortestPaths(0, cost, dist, predecessor, n);
//     for (int i = 0; i < n; i++)
//     {
//         printf("Shortest path from %d to %d: ", 0, i);
//         if (dist[i] == INT_MAX)
//             printf("No path\n");
//         else
//             printf("%d\n", dist[i]);
//         PrintPath(v, i, predecessor);
//         printf(")\n");
//     }
//     return 0;
// }