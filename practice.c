#include <stdio.h>
#include <limits.h>

void ShortestPaths(int v, int cost[100][100], int dist[], int predecessor[], int n)
{
    int S[n];
    for (int i = 0; i < n; i++)
    {
        S[i] = 0;
        dist[i] = cost[v][i];
        if (cost[v][i] < INT_MAX)
            predecessor[i] = v;
        else
            predecessor[i] = -1;
    }
    S[v] = 1;
    dist[v] = 0;
    predecessor[v] = -1;
    for (int j = 2; j <= n; j++)
    {
        int u = -1;
        int min_dist = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (S[i] == 0 && dist[i] < min_dist)
            {
                u = i;
                min_dist = dist[i];
            }
        }
        S[u] = 1;
        for (int w = 0; w < n; w++)
        {
            if (S[w] == 0 && cost[u][w] < INT_MAX)
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