// Aim: To implement N-Queen's problem using backtracking.

#include <stdio.h>
#include <stdbool.h>

#define N 8

int board[N][N] = {0};

/* Check whether a queen can be placed safely */
bool isSafe(int row, int col)
{
    // Check the same column in previous rows
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper-right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

/* Solve the N-Queens problem using backtracking */
bool solveNQueen(int row)
{
    // All queens have been placed successfully
    if (row == N) {
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            if (solveNQueen(row + 1)) {
                return true;
            }
            // Backtrack: remove the queen
            board[row][col] = 0;
        }
    }

    return false;
}

/* Display the chessboard */
void printBoard(void)
{
    printf("\nSolution:\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    printf("----- N-Queens Problem -----\n");

    if (solveNQueen(0)) {
        printBoard();
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
