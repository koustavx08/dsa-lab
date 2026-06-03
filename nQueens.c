#include <stdio.h>
#include <stdlib.h>

int board[20];
int n, i;

// function to check whether queen can be placed
int place(int row, int column) {
    for(i = 1; i < row; i++) {
        if(board[i] == column ||
           (abs(board[i] - column) == abs(i - row)))
            return 0;
    }
    return 1;
}

// function to solve n-queens using backtracking
void nQueens(int row) {
int column;
    for(column = 1; column <= n; column++) {
        if(place(row, column)) {
            board[row] = column;

            if(row == n) {
                printf("Solution: ");

                for(i = 1; i <= n; i++)
                    printf("%d ", board[i]);
                printf("\n");
            }
            else
                nQueens(row + 1);
        }
    }
}

int main() {
    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("\nPossible Solutions:\n");

    nQueens(1);

    return 0;
}
