#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chessfunc.h"
int main(){
    char choice;
    printf("\n****************\n");
    printf("\nWELCOME TO CHESS\n");
    printf("\n****************\n");
    do{//loop to set board and to play
        char board[]={
            'r','k','b','q','+','b','k','r',
            'p','p','p','p','p','p','p','p',
            ' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',
            ' ',' ',' ',' ',' ',' ',' ',' ',
            'P','P','P','P','P','P','P','P',
            'R','K','B','Q','*','B','K','R'
        };//declared board inside as we need to reset board after every game
        do{//loop to get choice and check it
            printf("\nCHOOSE AN OPTION\n1.vs Computer\n2.vs Human(make sure that that human is with you, this is not online)\n3.How to play\n4.Exit\n");
            scanf(" %c",&choice);//taking choice as a character to make sure that it doesnot go for infinite loop as if choice was an int and we input character
            if(((choice-48)!=1)&&((choice-48)!=2)&&((choice-48)!=3&&((choice-48)!=4))){
                printf("Choose a valid option\n");   
            }//48 is the ascii for zero 
            if((choice-48)==3){
                  printf("\nEnter your move using algebraic notation (e.g., a1, e3, d7).\nTo resign, type 'rs'.\nThis is a standard chess game but castling and en passant are not available\n");
            }
        }while((choice-48)!=2&&(choice-48)!=4&&(choice-48)!=1);
        if((choice-48)==2){
            while(1){
                showboard1(board);
                if(checkgaming(1,board)==0){//checkgaming checks whether the game is over or not, return 1 if not, 0 if yes
                    break;
                }
                printf("Move-Player 1\n");
                if(player1(board)==0){
                    printf("Player 1 resigned. Player 2 wins\n");
                    break;
                }
                showboard2(board);
                if(checkgaming(2,board)==0){
                    break;
                }
                printf("Move-Player 2\n");
                if(player2(board)==0){
                    printf("Player 2 resigned. Player 1 wins\n");
                    break;
                }
            }//gameover when code reaches this point
        }
        if((choice-48)==1){
            while(1){
                showboard1(board);
                if(checkgaming(-1,board)==0){//checkgaming checks whether the game is over or not, return 1 if not, 0 if yes
                    break;
                }
                printf("Move-Player\n");
                if(player1(board)==0){
                    printf("Player 1 resigned. Computer wins\n");
                    break;
                }
                if(checkgaming(0,board)==0){
                    break;
                }
                computermove(board);
            }//gameover when code reaches this point
        }
    }while((choice-48)!=4);
    printf("\nThank you for playing!\nDeveloped by:Mahmood Sinan\n");
    return 0;
}