#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char boardInitState = 'r';
int i, j;
int counter;
int nRows = 40;
int nCols = 40;
char board[40][40];
char blankBoard[40][40];
int evolutions = 100;
int timeBetweenEvolutions = 0;
int randomSeed = 50;

void initBoard(boardInitState){
    // blank board
    if (boardInitState == 'b') {
        for (i = 0; i < nRows; i++){
            for (j = 0; j < nCols; j++){
            blankBoard[i][j] = ' ';
            }
        }
    }
    // board with random cells initiated
    else if (boardInitState == 'r') {
        srand(randomSeed);
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
    // board with just glider gun initiated
    else if (boardInitState == 'g') {
        for (i = 0; i < nRows; i++){
            for (j = 0; j < nCols; j++){
            board[i][j] = ' ';
            }
        }
        
        board[1][25] = 'O';
        board[2][23] = 'O';
        board[2][25] = 'O';
        board[3][13] = 'O';
        board[3][14] = 'O';
        board[3][21] = 'O';
        board[3][22] = 'O';
        board[3][35] = 'O';
        board[3][36] = 'O';
        board[4][12] = 'O';
        board[4][16] = 'O';
        board[4][21] = 'O';
        board[4][22] = 'O';
        board[4][35] = 'O';
        board[4][36] = 'O';
        board[5][1] = 'O';
        board[5][2] = 'O';
        board[5][11] = 'O';
        board[5][17] = 'O';
        board[5][21] = 'O';
        board[5][22] = 'O';
        board[6][1] = 'O';
        board[6][2] = 'O';
        board[6][11] = 'O';
        board[6][15] = 'O';
        board[6][17] = 'O';
        board[6][18] = 'O';
        board[6][23] = 'O';
        board[6][25] = 'O';
        board[7][11] = 'O';
        board[7][17] = 'O';
        board[7][25] = 'O';
        board[8][12] = 'O';
        board[8][16] = 'O';
        board[9][13] = 'O';
        board[9][14] = 'O';
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

int main(int argc, char *argv[]) {
    int e;
    int opt;

    while((opt = getopt(argc, argv, ":ge:t:s:x")) != -1) 
    { 
        switch(opt) 
        {   case 'g': 
                boardInitState = 'g';
                break; 
            case 't': 
                timeBetweenEvolutions = atoi(optarg);
                break; 
            case 'e': 
                evolutions = atoi(optarg);
                break; 
            case 's': 
                randomSeed = atoi(optarg);
                break; 
            case ':': 
                printf("option needs a value\n"); 
                break; 
            case '?': 
                printf("unknown option: %c\n", optopt);
                break; 
        } 
    } 

    initBoard(boardInitState);
    
    for (e=0; e < evolutions; e++) {
        sleep(timeBetweenEvolutions);
        initBoard('b');
        evolveBoard();
        updateOldBoard();
        printBoardState(e);
    }

    return 0;
}