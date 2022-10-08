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
int choice;


int main(){

    //local variables
    char winner = ' ';
    char playagain;

    //game runs in a do wile loop
    do {
        //start the game and ask player what mode they want to play
        printf("======================\n");
        printf("WELCOME TO TIC TAC TOE!\n");
        printf("1 -- person vs person\n");
        printf("2 -- person vs computer\n");
        printf("Enter your choice (1 or 2): ");
        //scanf is where the player(s) decide their choice
        scanf("%d", &choice);
        //choice == 1 means they chose to do person vs person
         if(choice == 1){
            winner = ' ';
            playagain = ' ';
            //setGame() makes the initial array
            setGame();

            //checks to see if the game can be player
            while(winner == ' ' && numberOfPlaces() != 0){
                //prints the game board
                printGame();
                
                //gets input from first player
                firstPlayer();
                //checks to see if there is a winner
                winner = whoWins();

                //checks to see if all spaces is filled or if someone has won
                if(winner != ' ' || numberOfPlaces() == 0){
                    break;
                }

                //does everything that just happened above but with player2
                printGame();
                secondPlayer(); //gets input from player2
                winner = whoWins();

                if(winner != ' ' || numberOfPlaces() == 0){
                    break;
                }
            }

            printGame();
            printWhoWins(winner);
        } else if(choice == 2){ // choice == 2 means player1 chose to go against a computer


            winner = ' ';
            playagain = ' ';
            //set up the inital array
            setGame();
            
            while(winner == ' ' && numberOfPlaces() != 0){
                printGame();
                //gets input from first player
                firstPlayer();
                winner = whoWins();
                //if checks to see if game has been completed
                if(winner != ' ' || numberOfPlaces() == 0){
                    break;
                }

                //gets the input from the computer
                aiComputer();
                winner = whoWins();

                if(winner != ' ' || numberOfPlaces() == 0){
                    break;
                }
            }

        //print the final board
        printGame();
        //show who the winner of the game was
        printWhoWins(winner); 
        } else{
            printf("Invalid Option\n"); //happens when 1 or 2 for choice wasn't selected
        }

        //asks if the player wants to player
        //Y will reset the game to the choose a mode area
        //N will end the game
        printf("\nPlay Again? (Y/N): ");
        scanf("%c");
        scanf("%c", &playagain);
        playagain = toupper(playagain);
    } while (playagain == 'Y');
    
    //at this point the program will stop running
    printf("Gamer Over.");

    return 0;
}

//this function will print the game board
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

//creates the array that the game will be using
void setGame(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) {
            gameArray[i][j] = ' ';
        }
    }
}

//this function checks to see who has won the game
char whoWins(){

    //checks to see if the game has been won through the rows
    for(int i=0; i<3; i++){
        if(gameArray[i][0] == gameArray[i][1] && gameArray[i][0] == gameArray[i][2]){
            return gameArray[i][0];
        }
    }

    //checks to see if the game has been won through the columns
    for(int i=0; i<3; i++){
        if(gameArray[0][i] == gameArray[1][i] && gameArray[0][i] == gameArray[2][i]){
            return gameArray[0][i];
        }
    }

    //checks to see if the game has been won diagonally
    if(gameArray[0][0] == gameArray[1][1] && gameArray[0][0] == gameArray[2][2]){
        return gameArray[0][0];
    }
    if(gameArray[0][2] == gameArray[1][1] && gameArray[0][2] == gameArray[2][0]){
        return gameArray[0][2];
    }
    //returns ' ' if game has not been won
    return ' ';
}

//checks to see how many open spots are on the game
int numberOfPlaces(){
    //initial amount should be 9
    int numberOfSpaces = 9;

    //checks the amount of space and decreases numberOfSpaces as needed
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(gameArray[i][j] != ' '){
                numberOfSpaces--;
            }
        }
    }
    return numberOfSpaces;
}

//function for player1's input
void firstPlayer(){
    int x,y;

    do {
        //gets the input from the player
        printf("Player 1 make your move: ");
        scanf("%d %d", &x, &y);
        x--;
        y--;

        //gets the input from the player
        if(gameArray[x][y] != ' '){
            printf("Invalid spot\n");
        } else{
            gameArray[x][y] = player1;
            break;
        }
    } while(gameArray[x][y] != ' ');
}

//function for the player2's input
void secondPlayer(){
    int x,y;

    do {
        //gets the input from the player
        printf("Player 2 make your move: ");
        scanf("%d %d", &x, &y);
        x--;
        y--;

        //gets the input from the player
        if(gameArray[x][y] != ' '){
            printf("Invalid spot\n");
        } else{
            gameArray[x][y] = player2;
            break;
        }
    } while(gameArray[x][y] != ' ');
}

//function for the computer's input
void aiComputer(){
    srand(time(0));
    int x,y;

    if(numberOfPlaces() > 0){
        do {
            //chooses a random spot in the game
            x = rand()%3;
            y = rand()%3;
        } while(gameArray[x][y] != ' ');

        gameArray[x][y] = ai;
    } else{
        printWhoWins(' ');
    }
}

//prints the final message saying who was the winner or draw
void printWhoWins(char winner){
    if(winner == player1){
        printf("Player 1 wins.");
    } else if(winner == ai && choice == 2){
        printf("Computer wins.");
    } else if (winner == player2 && choice == 1){
        printf("Player 2 wins.");
    } else{
        printf("Draw.");
    }
    
}