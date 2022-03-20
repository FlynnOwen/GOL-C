#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int nRows = 50;
int nCols = 50;
char board[50][50];
char blankBoard[50][50];
_Bool isBlank;
int i, j;
int counter;
int evolutions = 100;

void initBoard(isBlank){
    
    if (isBlank) {
        for (i = 0; i < nRows; i++){
            for (j = 0; j < nCols; j++){
            blankBoard[i][j] = ' ';
            }
        }
    }

    else {
        int x;
        for (i = 0; i < nRows; i++){
            for (j = 0; j < nCols; j++){
                x = rand() % 2;
                if (x == 1) {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = ' ';
                }
            }
        }
    }

}

int _countCellNeighbours(i, j){
    int counter = 0;

    if (i - 1 > 0) {
        if (board[i-1][j] == 'O') {
            counter += 1;
        }
        if (j - 1 > 0) {
            if (board[i-1][j-1] == 'O') {
                counter += 1;
            }
        }
        if (j + 1 < nCols) {
            if (board[i-1][j+1] == 'O') {
                counter += 1;
            }
        }
    }

    if (i + 1 < nRows) {
        if (board[i+1][j] == 'O') {
                counter += 1;
        }

        if (j - 1 > 0) {
            if (board[i+1][j-1] == 'O') {
                counter += 1;
            }
        }
        if (j + 1 < nCols) {
            if (board[i+1][j+1] == 'O') {
                counter += 1;
            }
        }
    }


    if (j + 1 < nCols) {
        if (board[i][j+1] == 'O') {
            counter += 1;
        }
    }

    if (j - 1  > 0) {
        if (board[i][j-1] == 'O') {
            counter += 1;
        }
    }

    return counter;

}

void _evolveCell(i, j, counter) {
    
    if (board[i][j] == 'O') {
        if (counter < 2) {
            blankBoard[i][j] = ' ';
        }
        else if (counter == 2 || counter == 3) {
            blankBoard[i][j] = 'O';
        }
        else {
            blankBoard[i][j] = ' ';
        }
    }

    else {
        if (counter == 3) {
            blankBoard[i][j] = 'O';
        }
    }

}

void evolveBoard() {
    for (i = 0; i < nRows; i++){
        for (j = 0; j < nCols; j++){
            counter = _countCellNeighbours(i, j);
            _evolveCell(i, j, counter);
        }
    }
}

void updateOldBoard() {
    for (i = 0; i < nRows; i++){
        for (j = 0; j < nCols; j++){
            board[i][j] = blankBoard[i][j];
        }
    }
}

void printBoardState(evolution) {
    system("clear");

    for (i = 0; i < nRows; i++){
        for (j = 0; j < nCols; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("Generation = %i\n", evolution);
}

int main() {
    int timeBetweenEvolutions = 1;
    int e;

    initBoard(0);

    for (e=0; e < evolutions; e++) {
        //sleep(timeBetweenEvolutions);
        initBoard(1);
        evolveBoard();
        updateOldBoard();
        printBoardState(e);
    }

    return 0;
}