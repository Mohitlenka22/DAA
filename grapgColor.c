#include <stdio.h>
#include <stdbool.h>

#define V 4

void printSolution(int color[])
{
    printf("Vertex colors:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", color[i]);
    printf("\n");
}

bool isSafe(int graph[V][V], int color[])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] && color[j] == color[i])
                return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int v)
{
    if (v == V) 
        return true;

    for (int c = 1; c <= m; c++)
    {
        color[v] = c;

        if (isSafe(graph, color))
        {
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
        }

        color[v] = 0;
    }

    return false;
}

bool graphColoring(int graph[V][V], int m)
{
    int color[V] = {0}; // initialize all colors to 0

    if (graphColoringUtil(graph, m, color, 0) == false)
    {
        printf("Solution does not exist.\n");
        return false;
    }

    printSolution(color);
    return true;
}

int main()
{
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};

    int m = 3; 

    graphColoring(graph, m);

    return 0;
}