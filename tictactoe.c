//Tic Tac Toe game between 2 players or player vs player
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//declare functions
void printGame();
void setGame();
char winner();
int numberOfPlaces();
void player1();
void aiComputer();
void whoWins(char);

//create global variables
char gameArray[3][3];
char PLAYER1 = 'X';
char PLAYER2 = 'O';


int main(){

    char winner = ' ';

    setGame();
    while(winner == ' ' && numberOfPlaces() != 0){
        printGame();
    }






    //prompt user for game they wish to play
    //write code here

    //read information from console
    //write code here

    //pvp code
    //write code here

    //computer code
    //write code here

    //



    return 0;
}


void printGame(){
    printf("+------------+\n");
    printf("| %c | %c | %c |", gameArray[0][0], gameArray[0][1], gameArray[0][2]);
    printf("\n+------------+\n");
    printf("| %c | %c | %c |", gameArray[1][0], gameArray[1][1], gameArray[1][2]);
    printf("\n+------------+\n");
    printf("| %c | %c | %c |", gameArray[2][0], gameArray[2][1], gameArray[2][2]);
    printf("\n+------------+\n");
}
void setGame(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) {
            gameArray[i][j] = ' ';
        }
    }
}
char winner(){

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
void player1(){

}
void aiComputer(){

}
void whoWins(char winner){

}