//Tic Tac Toe game between 2 players or player vs player
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//declare functions
void printGame();
void setGame();
char whoWins();
int numberOfPlaces();
void firstPlayer();
void secondPlayer();
void aiComputer();
void printWhoWins(char);

//create global variables
char gameArray[3][3];
char player1 = 'X';
char player2 = 'O';
char ai = 'O';


int main(){

    char winner = ' ';
    char playagain;
    int choice;

    do {
        printf("======================\n");
        printf("WELCOME TO TIC TAC TOE!\n");
        printf("1 -- person vs person\n");
        printf("2 -- person vs computer\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
         if(choice == 1){
            winner = ' ';
            playagain = ' ';
            setGame();
            while(winner == ' ' && numberOfPlaces() != 0){
                printGame();

                firstPlayer();
                winner = whoWins();

                if(winner != ' ' || numberOfPlaces() == 0){
                    break;
                }

                printGame();
                secondPlayer();
                winner = whoWins();

                if(winner != ' ' || numberOfPlaces() == 0){
                    break;
                }
            }

            printGame();
            printWhoWins(winner);
        }
        if(choice == 2){

            winner = ' ';
            playagain = ' ';
            setGame();
            while(winner == ' ' && numberOfPlaces() != 0){
                printGame();

                firstPlayer();
                winner = whoWins();

                if(winner != ' ' || numberOfPlaces() == 0){
                    break;
                }

                aiComputer();
                winner = whoWins();

                if(winner != ' ' || numberOfPlaces() == 0){
                    break;
                }
            }

        printGame();
        printWhoWins(winner); 
        }

        printf("\n Play Again? (Y/N): ");
        scanf("%c");
        scanf("%c", &playagain);
        playagain = toupper(playagain);
    } while (playagain == 'Y');
    

    printf("Gamer Over.");

    return 0;
}


void printGame(){
    printf("The current status is:\n");
    printf("+-----------+\n");
    printf("| %c | %c | %c |", gameArray[0][0], gameArray[0][1], gameArray[0][2]);
    printf("\n+-----------+\n");
    printf("| %c | %c | %c |", gameArray[1][0], gameArray[1][1], gameArray[1][2]);
    printf("\n+-----------+\n");
    printf("| %c | %c | %c |", gameArray[2][0], gameArray[2][1], gameArray[2][2]);
    printf("\n+-----------+\n");
}

void setGame(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) {
            gameArray[i][j] = ' ';
        }
    }
}

char whoWins(){

    //check for rows
    for(int i=0; i<3; i++){
        if(gameArray[i][0] == gameArray[i][1] && gameArray[i][0] == gameArray[i][2]){
            return gameArray[i][0];
        }
    }

    //check for columns
    for(int i=0; i<3; i++){
        if(gameArray[0][i] == gameArray[1][i] && gameArray[0][i] == gameArray[2][i]){
            return gameArray[0][i];
        }
    }

    //check diagonals
    if(gameArray[0][0] == gameArray[1][1] && gameArray[0][0] == gameArray[2][2]){
        return gameArray[0][0];
    }
    if(gameArray[0][2] == gameArray[1][1] && gameArray[0][2] == gameArray[2][0]){
        return gameArray[0][2];
    }
    return ' ';
}

int numberOfPlaces(){
    int numberOfSpaces = 9;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(gameArray[i][j] != ' '){
                numberOfSpaces--;
            }
        }
    }
    return numberOfSpaces;
}

void firstPlayer(){
    int x,y;

    do {
        printf("Player 1 make your move: ");
        scanf("%d %d", &x, &y);
        x--;
        y--;

        if(gameArray[x][y] != ' '){
            printf("Invalid spot\n");
        } else{
            gameArray[x][y] = player1;
            break;
        }
    } while(gameArray[x][y] != ' ');
}

void secondPlayer(){
    int x,y;

    do {
        printf("Player 2 make your move: ");
        scanf("%d %d", &x, &y);
        x--;
        y--;

        if(gameArray[x][y] != ' '){
            printf("Invalid spot\n");
        } else{
            gameArray[x][y] = player2;
            break;
        }
    } while(gameArray[x][y] != ' ');
}

void aiComputer(){
    srand(time(0));
    int x,y;

    if(numberOfPlaces() > 0){
        do {
            x = rand()%3;
            y = rand()%3;
        } while(gameArray[x][y] != ' ');

        gameArray[x][y] = ai;
    } else{
        printWhoWins(' ');
    }
}

void printWhoWins(char winner){
    if(winner == player1){
        printf("Player 1 wins.");
    } else if(winner == ai){
        printf("Computer wins.");
    } else if (winner == player2){
        printf("Player 2 wins.");
    } else{
        printf("Draw.");
    }
    
}