#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

void floyd_warshall(int **graph, int n)
{
    int i, j, k;

    int **dist = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        dist[i] = (int *)malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("All pairs shortest path:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        free(dist[i]);
    }
    free(dist);
}

int main()
{
    int n, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int **graph = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(sizeof(int) * n);
    }

    printf("Enter the graph values:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1)
            {
                graph[i][j] = INF;
            }
        }
    }

    floyd_warshall(graph, n);

    for (i = 0; i < n; i++)
    {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
