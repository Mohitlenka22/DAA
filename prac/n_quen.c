#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void Nqueens(int k, int n, int x[]);
bool place(int k, int i, int x[]);
void printBoard(int x[], int n);

void printBoard(int x[], int n)
{
    int board[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            board[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        board[i][x[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

bool place(int k, int i, int x[])
{
    for (int j = 1; j < k; j++)
        if (x[j] == i || (abs(x[j] - i) == abs(j - k))) // two queens positions --> (k, i) && (j, x[j])
            return false;
    return true;
}

void Nqueens(int k, int n, int x[])
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i, x))
        {
            x[k] = i;
            if (k == n)
            {
                for (int i = 1; i <= n; i++)
                {
                    printf("%d ", x[i]);
                }
                printf("\n\n Board \n");
                printBoard(x, n);
                printf("\n");
            }
            else
                Nqueens(k + 1, n, x);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int x[n + 1];
    Nqueens(1, n, x);

    return 0;
}