#include <stdio.h>
#include <stdlib.h>

#define N 4

void printBoard(int board[N][N])
{
    printf("\nSolution:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solveNQueens(int board[N][N], int col)
{
    if (col == N)
    {
        printBoard(board);
        return 1;
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            res = solveNQueens(board, col + 1) || res;

            board[i][col] = 0;
        }
    }

    return res;
}

int main()
{
    int board[N][N] = {0};

    if (solveNQueens(board, 0) == 0)
        printf("\nSolution does not exist for N = %d", N);

    return 0;
}