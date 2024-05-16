#include <stdio.h>

void displayChoice () {
    printf("\t\t\t#Tic-Tac-Toe#\n");
    printf("Choose a cell numbered from 1 to 9 as below and play.\n");
    printf("\t\t\t  1 | 2 | 3\n");
    printf("\t\t\t ---|---|---\n");
    printf("\t\t\t  4 | 5 | 6\n");
    printf("\t\t\t ---|---|---\n");
    printf("\t\t\t  7 | 8 | 9");
}

void displayWinner (int winner) {
    printf("\t\t\t  GAME OVER!\n");
    printf("\t\t\tPlayer %d wins!", winner);
}

int determinePosition (int player) {
    int position;
    
    printf("\n\nPlayer %d | Enter your move (1-9): ", player);
    scanf("%d", &position);

    return position;
}

void printBoard (int board[3][3]) {
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            int value = board[y][x];

            if (!value) printf(" ");
            else printf("%c", (value == 1) ? 'X' : 'O');

            if (x != 2) printf(" | ");
        }

        printf("\n");
        if (y != 2) printf("--|---|--\n");
    }
}

void checkPlacement (int board[3][3], int position, int player) {
    int status = 1;

    for (int y = 0 ; y < 3 && status; y++) {
        for (int x = 0; x < 3; x++) {
            if (x == position - 1) {
                int value = board[y][x];

                if (value) {
                    printf("Invalid Move: This cell is already occupied by Player %d.\n", value);
                    status = 0;
                }

                board[y][x] = player;
                status = 0;
            }
            else if (x == 2) position -= 3;
        }
    }
}

int checkWinner(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return 0;
}

int main(void) {
    int position;

    int gameOver = 0;
    int player1Win = 0;
    int player2Win = 0;
    int playerTurn = -1;

    int board[][3] = {
        { 0, 0, 0 },
        { 0, 0, 0 },
        { 0, 0, 0 }
    };

    displayChoice();

    int player;
    int winner;
    int turnCount = 0;

    while (1) {
        playerTurn *= (-1);

        if (playerTurn > 0) player = 1;
        else player = 2;

        position = determinePosition(player);

        checkPlacement(board, position, player);
        printBoard(board);
        winner = checkWinner(board);

        if (winner > 0) break;
        else if (winner < 0) break;
        else if (turnCount == 8) {
            printf("\t\t\t      GAME OVER!\n");
            printf("\t\t\tGame ends in stalemate");
            return 0;
        }

        turnCount++;
    }

    displayWinner(winner);

    return 0;
}