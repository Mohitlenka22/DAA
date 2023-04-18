#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int parent[MAX];
int size[MAX];

int Find(int i)
{
    if (parent[i] == -1)
    {
        return i;
    }
    return parent[i] = Find(parent[i]);
}

void Union(int i, int j)
{
    if (size[i] < size[j])
    {
        parent[i] = j;
        size[j] += size[i];
    }
    else
    {
        parent[j] = i;
        size[i] += size[j];
    }
}

void AdjustMin(int cost[], int heap[], int i, int n)
{
    int j = 2 * i;
    int item = heap[i];
    while (j <= n)
    {
        if ((j < n) && (cost[heap[j]] > cost[heap[j + 1]]))
        {
            j = j + 1;
        }
        if (cost[item] <= cost[heap[j]])
        {
            break;
        }
        heap[j / 2] = heap[j];
        j = 2 * j;
    }
    heap[j / 2] = item;
}

void Heapify(int E[][3], int heap[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        AdjustMin(E[0], heap, i, n);
    }
}

float Kruskal(int E[][3], int n, int t[][2])
{
    int heap[MAX];
    int heapsize = n;
    float mincost = 0.0;

    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        size[i] = 1;
        heap[i + 1] = i;
    }

    Heapify(E, heap, n);

    int i = 0;
    while ((i < n - 1) && (heapsize > 0))
    {
        int u = heap[1];
        heap[1] = heap[heapsize];
        heapsize--;
        AdjustMin(E[0], heap, 1, heapsize);

        int j = Find(u);
        int k = Find(heap[1]);

        if (j != k)
        {
            i++;
            t[i][0] = u;
            t[i][1] = heap[1];
            mincost += E[heap[1]][2];
            Union(j, k);
        }
    }

    if (i != n - 1)
    {
        printf("No spanning tree\n");
        return 0.0;
    }
    else
    {
        return mincost;
    }
}

int main()
{
    int n = 5;
    int E[MAX][3] = {{0, 1, 10},
                     {0, 2, 6},
                     {0, 3, 5},
                     {1, 3, 15},
                     {2, 3, 4}};
    int t[MAX][2];

    float mincost = Kruskal(E, n, t); // Added semicolon here

    printf("Minimum cost of spanning tree: %f\n", mincost);
    printf("Edges in the minimum cost spanning tree:\n");
    for (int i = 1; i < n; i++)
    {
        printf("(%d, %d)\n", t[i][0], t[i][1]);
    }

    return 0;
}
