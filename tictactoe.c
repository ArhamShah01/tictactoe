#include <stdio.h>

char board[3][3];

void initBoard() {
    int i, j;
    char cell = '1';
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = cell++;
        }
    }
}

void printBoard() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("\n---+---+---\n");
    }
    printf("\n\n");
}

int checkWin() {
    int i;
    /* rows and columns */
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    /* diagonals */
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

int isDraw() {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return 0;
    return 1;
}

int makeMove(char player, int choice) {
    int i, j;
    char target = '0' + choice;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == target) {
                board[i][j] = player;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char player = 'X';
    int choice;
    int gameOver = 0;

    initBoard();
    printf("Tic Tac Toe (Player X vs Player O)\n");
    printBoard();

    while (!gameOver) {
        printf("Player %c, enter a cell number (1-9): ", player);
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 9) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (!makeMove(player, choice)) {
            printf("Cell already taken. Try again.\n");
            continue;
        }

        printBoard();

        if (checkWin()) {
            printf("Player %c wins!\n", player);
            gameOver = 1;
        } else if (isDraw()) {
            printf("It's a draw.\n");
            gameOver = 1;
        } else {
            player = (player == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
