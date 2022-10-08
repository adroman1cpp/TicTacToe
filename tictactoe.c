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
constant char PLAYER1 = 'X';
constant char PLAYER2 = 'O';


int main(){

    char winner = ' ';

    setGame();
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

}
void setGame(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
}
char winner(){

}
int numberOfPlaces(){

}
void player1(){

}
void aiComputer(){

}
void whoWins(char winner){

}