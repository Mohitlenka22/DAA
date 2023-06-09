#include <stdio.h>

int n;

void printPath(int path[n][n], int src, int dest)
{
    if (path[src][dest] == -1)
    {
        printf("%d", src);
    }
    else
    {
        printPath(path, src, path[src][dest]);
        printf("->%d", dest);
    }
}

void printAllPaths(int dist[n][n], int path[n][n])
{
    for (int src = 0; src < n; src++)
    {
        for (int dest = 0; dest < n; dest++)
        {
            if (src != dest)
            {
                printf("Shortest path from %d to %d: ", src, dest);
                if (dist[src][dest] == 1e9)
                {
                    printf("No path exists\n");
                }
                else
                {
                    printPath(path, src, dest);
                    printf("\n");
                }
            }
        }
    }
}

void floyd_warshall(int graph[n][n])
{
    int dist[n][n], path[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != 1e9 && i != j)
            {
                path[i][j] = i;
            }
            else
            {
                path[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != 1e9 && dist[k][j] != 1e9 && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    printAllPaths(dist, path);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%d ", dist[i][j]);
    //     }
    //     printf("\n");
    // }
}

int main()
{
    scanf("%d", &n);
    int graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1)
                graph[i][j] = 1e9;
        }
    }
    floyd_warshall(graph);
    return 0;
}