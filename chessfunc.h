#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void showboard1(char board[]);
void showboard2(char board[]);
int player1(char board[]);
int player2(char board[]);
int checkfrommove(char board[],int fromind,int move);
int checktomove(char board[],int toind,int move);
int piecemoves(char board[],int fromind,int toind,int frnum,int fcnum,int trnum,int tcnum);
int rook(char board[],int frnum,int fcnum,int trnum,int tcnum);
int bishop(char board[],int fromind,int toind,int frnum,int fcnum,int trnum,int tcnum);
int knight(char board[],int frnum,int fcnum,int trnum,int tcnum);
int king(char board[],int frnum,int fcnum,int trnum,int tcnum);
int pawn(char board[],int frnum,int fcnum,int trnum,int tcnum,int fromind,int toind);
int check(char board[],int move);
int calcmoves(char board[],int move);
int piecemovesforgaming(char board[],int fromind,int toind,int frnum,int fcnum,int trnum,int tcnum);
int checkfrommoveforgaming(char board[],int fromind,int move);
int checktomoveforgaming(char board[],int toind,int move);
int checkgaming(int move,char board[]);
void computermove(char board[]);
void promotion(char board[],int move,int toind);

void showboard1(char board[]){
    printf("   _____ _____ _____ _____ _____ _____ _____ _____ \n");
    for(int i=0;i<8;i++){
        if(i%2==1){   
            printf("  |     |\u2588\u2588\u2588\u2588\u2588|     |\u2588\u2588\u2588\u2588\u2588|     |\u2588\u2588\u2588\u2588\u2588|     |\u2588\u2588\u2588\u2588\u2588|\n");
            printf("%d |  %c  |\u2588 %c \u2588|  %c  |\u2588 %c \u2588|  %c  |\u2588 %c \u2588|  %c  |\u2588 %c \u2588|\n",8-i,board[(8*i)],board[(8*i)+1],board[(8*i)+2],board[(8*i)+3],board[(8*i)+4],board[(8*i)+5],board[(8*i)+6],board[(8*i)+7]);
            printf("  |_____|\u2588\u2588\u2588\u2588\u2588|_____|\u2588\u2588\u2588\u2588\u2588|_____|\u2588\u2588\u2588\u2588\u2588|_____|\u2588\u2588\u2588\u2588\u2588|\n");
        }
        else{
            printf("  |\u2588\u2588\u2588\u2588\u2588|     |\u2588\u2588\u2588\u2588\u2588|     |\u2588\u2588\u2588\u2588\u2588|     |\u2588\u2588\u2588\u2588\u2588|     |\n");
            printf("%d |\u2588 %c \u2588|  %c  |\u2588 %c \u2588|  %c  |\u2588 %c \u2588|  %c  |\u2588 %c \u2588|  %c  |\n",8-i,board[(8*i)],board[(8*i)+1],board[(8*i)+2],board[(8*i)+3],board[(8*i)+4],board[(8*i)+5],board[(8*i)+6],board[(8*i)+7]);
            printf("  |\u2588\u2588\u2588\u2588\u2588|_____|\u2588\u2588\u2588\u2588\u2588|_____|\u2588\u2588\u2588\u2588\u2588|_____|\u2588\u2588\u2588\u2588\u2588|_____|\n");
        }
    }
    printf("     a     b     c     d     e     f     g     h   \n");
}
void showboard2(char board[]){
    printf("   _____ _____ _____ _____ _____ _____ _____ _____ \n");
    for(int i=7;i>-1;i--){
        if(i%2==0){   
            printf("  |     |\u2588\u2588\u2588\u2588\u2588|     |\u2588\u2588\u2588\u2588\u2588|     |\u2588\u2588\u2588\u2588\u2588|     |\u2588\u2588\u2588\u2588\u2588|\n");
            printf("%d |  %c  |\u2588 %c \u2588|  %c  |\u2588 %c \u2588|  %c  |\u2588 %c \u2588|  %c  |\u2588 %c \u2588|\n",8-i,board[(8*i)+7],board[(8*i)+6],board[(8*i)+5],board[(8*i)+4],board[(8*i)+3],board[(8*i)+2],board[(8*i)+1],board[(8*i)]);
            printf("  |_____|\u2588\u2588\u2588\u2588\u2588|_____|\u2588\u2588\u2588\u2588\u2588|_____|\u2588\u2588\u2588\u2588\u2588|_____|\u2588\u2588\u2588\u2588\u2588|\n");
        }
        else{
            printf("  |\u2588\u2588\u2588\u2588\u2588|     |\u2588\u2588\u2588\u2588\u2588|     |\u2588\u2588\u2588\u2588\u2588|     |\u2588\u2588\u2588\u2588\u2588|     |\n");
            printf("%d |\u2588 %c \u2588|  %c  |\u2588 %c \u2588|  %c  |\u2588 %c \u2588|  %c  |\u2588 %c \u2588|  %c  |\n",8-i,board[(8*i)+7],board[(8*i)+6],board[(8*i)+5],board[(8*i)+4],board[(8*i)+3],board[(8*i)+2],board[(8*i)+1],board[(8*i)]);
            printf("  |\u2588\u2588\u2588\u2588\u2588|_____|\u2588\u2588\u2588\u2588\u2588|_____|\u2588\u2588\u2588\u2588\u2588|_____|\u2588\u2588\u2588\u2588\u2588|_____|\n");
        }
    }
    printf("     h     g     f     e     d     c     b     a   \n");
}

int player1(char board[]){//takes player 1 input and apply that move if valid
    char from[3],to[3],temp; //collect from and to position
    int fromind=0,toind=0,fromvalid=0,tovalid=0,piecemove=0;//index of the board is 0 on top left and 63 on bottom right. fromind is fromindex. toind is toindex. fromvalid and tovalid checks whether that move about that index is valid or not. piecemove to enforce the correct movement of pieces.
    do{
        do{
            do{//check whether one chose a valid from move
                if(check(board,1)!=0){//check to check whether the player in argument is in check or not
                    printf("Check\n");
                }
                printf("Type a valid position of the piece that you want to move:\n");
                scanf("%2s",from);
                if(from[0]=='r'&&from[1]=='s'){
                    return 0;
                }
                if(from[0]>104||from[0]<97||from[1]>56||from[1]<49){
                    continue; //104-h,97-a,56-8,49-1
                }//checks whether one input a slot in the board or not(like z100)
                fromind=((8-(from[1]-48))*8)+(from[0]-97);
                if(board[fromind]!=' '){
                    fromvalid=checkfrommove(board,fromind,1);//to check one selected one's own pieces
                }
            }while(board[fromind]==' '||fromvalid==0||from[0]>104||from[0]<97||from[1]>56||from[1]<49);
            printf("Type a valid position to where you want to move:\n");
            scanf("%2s",to);
            if(to[0]>104||to[0]<97||to[1]>56||to[1]<49){
                continue;
            }
            toind=((8-(to[1]-48))*8)+(to[0]-97);
            piecemove=piecemoves(board,fromind,toind,(fromind/8)+1,(fromind%8)+1,(toind/8)+1,(toind%8)+1);//to enforce the correct movement of pieces
            if(piecemove==1){
                tovalid=checktomove(board,toind,1);//to make sure to index is not index to one's own pieces
            }
        }while(tovalid==0||to[0]>104||to[0]<97||to[1]>56||to[1]<49);
        temp=board[toind];//did this temp and if method below, to make sure one playes correctly if he is in check
        board[toind]=board[fromind];
        board[fromind]=' ';
        if(check(board,1)!=0){
            board[fromind]=board[toind];
            board[toind]=temp;
        }
        else{
            // look at this code later
            if((fromind/8)+1==2&&board[toind]=='P'){
                promotion(board,1,toind);
            }
            break;
        }
    }while(1);
    return 1;
}
int player2(char board[]){
    char from[3],to[3],temp; //collect from and to position
    int fromind=0,toind=0,fromvalid=0,tovalid=0,piecemove=0;//index of the board is 0 on top left and 63 on bottom right. fromind from fromindex. toind is toindex. fromvalid and tovalid checks whether that move about that index is valid or not. piecemove to enforce the correct movement of pieces.
    do{
        do{
            do{
                if(check(board,2)!=0){
                    printf("Check\n");
                }
                printf("Type a valid position of the piece that you want to move:\n");
                scanf("%2s",from);
                if(from[0]=='r'&&from[1]=='s'){
                    return 0;
                }
                if(from[0]>104||from[0]<97||from[1]>56||from[1]<49){
                    continue; //104-h,97-a,56-8,49-1
                }
                fromind=((8-(from[1]-48))*8)+(from[0]-97);
                if(board[fromind]!=' '){
                    fromvalid=checkfrommove(board,fromind,2);
                }
            }while(board[fromind]==' '||fromvalid==0||from[0]>104||from[0]<97||from[1]>56||from[1]<49);
            printf("Type a valid position to where you want to move:\n");
            scanf("%2s",to);
            if(to[0]>104||to[0]<97||to[1]>56||to[1]<49){
                continue;
            }
            toind=((8-(to[1]-48))*8)+(to[0]-97);
            piecemove=piecemoves(board,fromind,toind,(fromind/8)+1,(fromind%8)+1,(toind/8)+1,(toind%8)+1);//last four arguments are row and column numbers of from index and to index respectively
            if(piecemove==1){
                tovalid=checktomove(board,toind,2);
            }
        }while(tovalid==0||to[0]>104||to[0]<97||to[1]>56||to[1]<49);
        temp=board[toind];
        board[toind]=board[fromind];
        board[fromind]=' ';
        if(check(board,2)!=0){
            board[fromind]=board[toind];
            board[toind]=temp;
        }
        else{//check this code later
            if((fromind/8)+1==7&&board[toind]=='p'){
                promotion(board,2,toind);
            }
            break;
        }
    }while(1);
    return 1;
}
int checkfrommove(char board[],int fromind,int move){
    switch(move){
        case 1:
        if(board[fromind]=='R'||board[fromind]=='P'||board[fromind]=='K'||board[fromind]=='B'||board[fromind]=='Q'||board[fromind]=='*'){
            return 1;
        }
        else{
            printf("Choose your own piece\n");
            return 0;
        }
        case 2:
        if(board[fromind]=='r'||board[fromind]=='p'||board[fromind]=='k'||board[fromind]=='b'||board[fromind]=='q'||board[fromind]=='+'){
            return 1;
        }
        else{
            printf("Choose your own piece\n");
            return 0;
        }
        default : return 0;
    }
}
int checktomove(char board[],int toind,int move){
    switch(move){
        case 1:
        if(board[toind]=='R'||board[toind]=='P'||board[toind]=='K'||board[toind]=='B'||board[toind]=='Q'||board[toind]=='*'){
            printf("You cannot capture your own pieces\n");
            return 0;
        }
        else{
            return 1;
        }
        case 2:
        if(board[toind]=='r'||board[toind]=='p'||board[toind]=='k'||board[toind]=='b'||board[toind]=='q'||board[toind]=='+'){
            printf("You cannot capture your own pieces\n");
            return 0;
        }
        else{
            return 1;
        }
        default:return 0;
    }
}
int piecemoves(char board[],int fromind,int toind,int frnum,int fcnum,int trnum,int tcnum){
    int returnvalue=0;//zero for the piece cannot be moved there because some other piece is blocking the way. one is for a valid move. two for the piece cannot be moved there as per the rules
    if(board[fromind]=='R'||board[fromind]=='r'){
        returnvalue=rook(board,frnum,fcnum,trnum,tcnum);
        if(returnvalue==0){
            printf("Choose a valid move for rook\n");
        }
        return returnvalue;
    }
    else if(board[fromind]=='B'||board[fromind]=='b'){
        returnvalue=bishop(board,fromind,toind,frnum,fcnum,trnum,tcnum);
        if(returnvalue==0){
            printf("Choose a valid move for bishop\n");
        }
        return returnvalue;
    }
    else if(board[fromind]=='K'||board[fromind]=='k'){
        returnvalue=knight(board,frnum,fcnum,trnum,tcnum);
        if(returnvalue==0){
            printf("Choose a valid move for knight\n");
        }
        return returnvalue;
    }
    else if(board[fromind]=='Q'||board[fromind]=='q'){
        returnvalue=rook(board,frnum,fcnum,trnum,tcnum)+bishop(board,fromind,toind,frnum,fcnum,trnum,tcnum);
        if(returnvalue==0){
            printf("Choose a valid move for queen\n");
        }
        return returnvalue;
    }
    else if(board[fromind]=='*'||board[fromind]=='+'){
        returnvalue=king(board,frnum,fcnum,trnum,tcnum);
        if(returnvalue==0){
            printf("Choose a valid move for king\n");
        }
        return returnvalue;
    }
    else if(board[fromind]=='P'||board[fromind]=='p'){
        returnvalue=pawn(board,frnum,fcnum,trnum,tcnum,fromind,toind);
        if(returnvalue==0){
            printf("Choose a valid move for pawn\n");
        }
        return returnvalue;
    }
    return 1;
}
int rook(char board[],int frnum,int fcnum,int trnum,int tcnum){
    int cd=0,rd=0,fromind=(frnum-1)*8+(fcnum-1),toind=(trnum-1)*8+(tcnum-1);
    rd=abs(frnum-trnum);
    cd=abs(fcnum-tcnum);
    if((frnum==trnum)||(fcnum==tcnum)){
        if(fcnum==tcnum&&trnum>frnum){
            for(int i=1;i<rd;i++){
                if(board[fromind+(i*8)]!=' '){
                    return 0;
                }
            }
        }
        else if(fcnum==tcnum&&trnum<frnum){
            for(int i=1;i<rd;i++){
                if(board[toind+(i*8)]!=' '){
                    return 0;
                }
            }
        }
        else if(frnum==trnum&&tcnum>fcnum){
            for(int i=1;i<cd;i++){
                if(board[fromind+i]!=' '){
                    return 0;
                }
            }
        }
        else if(frnum==trnum&&tcnum<fcnum){
            for(int i=1;i<cd;i++){
                if(board[toind+i]!=' '){
                    return 0;
                }
            }
        }
        return 1;
    }
    else{
        return 0;
    }
}
int bishop(char board[],int fromind,int toind,int frnum,int fcnum,int trnum,int tcnum){
    int d=0,rd=0,cd=0;
    rd=abs(frnum-trnum);
    cd=abs(fcnum-tcnum);
    d=abs(fromind-toind);
    if(rd==cd){
        if(((fromind-toind)%9==0)&&((fromind-toind)>0)){
            for(int i=9;i<d;i+=9){
                if(board[toind+i]!=' '){
                    return 0;
                }
            }
        }
        else if(((fromind-toind)%9==0)&&((fromind-toind)<0)){
            for(int i=9;i<d;i+=9){
                if(board[fromind+i]!=' '){
                    return 0;
                }
            }
        }
        else if(((fromind-toind)%7==0)&&((fromind-toind)>0)){
            for(int i=7;i<d;i+=7){
                if(board[toind+i]!=' '){
                    return 0;
                }
            }
        }
        else if(((fromind-toind)%7==0)&&((fromind-toind)<0)){
            for(int i=7;i<d;i+=7){
                if(board[fromind+i]!=' '){
                    return 0;
                }
            }
        }
        return 1;
    }
    else{
        return 0;
    }
}
int knight(char board[],int frnum,int fcnum,int trnum,int tcnum){
    int cd=0,rd=0;
    rd=abs(frnum-trnum);
    cd=abs(fcnum-tcnum);
    if(((cd+rd)==3)&&(cd!=0)&&(rd!=0)){
        return 1;
    }
    else{
        return 0;
    }
}
int king(char board[],int frnum,int fcnum,int trnum,int tcnum){
    int cd=0,rd=0;
    rd=abs(frnum-trnum);
    cd=abs(fcnum-tcnum);
    if((cd==1||rd==1)&&(cd+rd<3)){
        return 1;
    }
    else{
        return 0;
    }
}
int pawn(char board[],int frnum,int fcnum,int trnum,int tcnum,int fromind,int toind){
    char promote,temp;
    if(board[fromind]=='p'){
        if(frnum==2){
            if((toind-fromind==8)&&board[toind]==' '){
                return 1;
            }
            else if((toind-fromind==16)&&board[toind]==' '&&board[toind-8]==' '){
                return 1;
            }
            else if((toind-fromind==16)&&board[toind]==' '&&board[toind-8]!=' '){
                return 0;
            }
            else if((abs(tcnum-fcnum)==1)&&(trnum-frnum==1)&&(board[toind]!=' ')){
                return 1;
            }
            else{
                return 0;
            }
        }
        else if((abs(tcnum-fcnum)==1)&&(trnum-frnum==1)&&(board[toind]!=' ')){ //pawn kill
            return 1;
        }
        else if((trnum-frnum==1)&&(tcnum==fcnum)&&(board[toind]==' ')){ //pawn advance
            return 1;
        }
        else if((trnum-frnum==1)&&(tcnum==fcnum)&&(board[toind]!=' ')){
            return 0;
        }
        else{
            return 0;
        }
        
    }
    else if(board[fromind]=='P'){
        if(frnum==7){
            if((toind-fromind==-8)&&board[toind]==' '){
                return 1;
            }
            else if((toind-fromind==-16)&&board[toind]==' '&&board[toind+8]==' '){
                return 1;
            }
            else if((toind-fromind==-16)&&board[toind]==' '&&board[toind+8]!=' '){
                return 0;
            }
            else if((abs(tcnum-fcnum)==1)&&((trnum-frnum)==-1)&&(board[toind]!=' ')){
                return 1;
            }
            else{
                return 0;
            }
        }
        else if((abs(tcnum-fcnum)==1)&&((trnum-frnum)==-1)&&(board[toind]!=' ')){ //pawn kill
            return 1;
        }
        else if(((trnum-frnum)==-1)&&tcnum==fcnum&&(board[toind]==' ')){ //pawn advance
            return 1;
        }
        else if(((trnum-frnum)==-1)&&(tcnum==fcnum)&&(board[toind!=' '])){
            return 0;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}
int check(char board[],int move){
    int kingind=0,count=0,returnvalue=0;
    if(move==1){
        for(int i=0;i<64;i++){
            if(board[i]=='*'){
                kingind=i;
                break;
            }
        }
    }
    else{
        for(int i=0;i<64;i++){
            if(board[i]=='+'){
                kingind=i;
                break;
            }
        }
    }
    int krnum=(kingind/8)+1;
    int kcnum=(kingind%8)+1;
    if(move==1){
        for(int i=0;i<64;i++){
            int irnum=(i/8)+1;
            int icnum=(i%8)+1;
            switch(board[i]){
                case 114:
                    returnvalue=rook(board,irnum,icnum,krnum,kcnum);//fromind=i,toind=kingind,f=i,t=k
                    count+=returnvalue;
                    break;
                case 98:
                    returnvalue=bishop(board,i,kingind,irnum,icnum,krnum,kcnum);
                    count+=returnvalue;
                    break;
                case 107:
                    returnvalue=knight(board,irnum,icnum,krnum,kcnum);
                    count+=returnvalue;
                    break;
                case 43:
                    returnvalue=king(board,irnum,icnum,krnum,kcnum);
                    count+=returnvalue;
                    break;
                case 113:
                    returnvalue=rook(board,irnum,icnum,krnum,kcnum)+bishop(board,i,kingind,irnum,icnum,krnum,kcnum);
                    count+=returnvalue;
                    break;
                case 112:
                    returnvalue=pawn(board,irnum,icnum,krnum,kcnum,i,kingind);
                    count+=returnvalue;
                    break;
            }
        }
    }
    if(move==2){
        for(int i=0;i<64;i++){
            int irnum=(i/8)+1;
            int icnum=(i%8)+1;
            switch(board[i]){
                case 82:
                    returnvalue=rook(board,irnum,icnum,krnum,kcnum);//fromind=i,toind=kingind,f=i,t=k
                    count+=returnvalue;
                    break;
                case 66:
                    returnvalue=bishop(board,i,kingind,irnum,icnum,krnum,kcnum);
                    count+=returnvalue;
                    break;
                case 75:
                    returnvalue=knight(board,irnum,icnum,krnum,kcnum);
                    count+=returnvalue;
                    break;
                case 42:
                    returnvalue=king(board,irnum,icnum,krnum,kcnum);
                    count+=returnvalue;
                    break;
                case 81:
                    returnvalue=rook(board,irnum,icnum,krnum,kcnum)+bishop(board,i,kingind,irnum,icnum,krnum,kcnum);
                    count+=returnvalue;
                    break;
                case 80:
                    returnvalue=pawn(board,irnum,icnum,krnum,kcnum,i,kingind);
                    count+=returnvalue;
                    break;
            }
        }
    }
    return count;
}
int calcmoves(char board[],int move){
    int nmoves=0;
    if(move==1){
        nmoves=0;
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                char temp;
                int fromind=i,toind=0,fromvalid=0,tovalid=0,piecemove=0;
                if(board[fromind]!=' '){
                    toind=j;
                    if(checkfrommoveforgaming(board,fromind,1)==1&&piecemovesforgaming(board,fromind,toind,(fromind/8)+1,(fromind%8)+1,(toind/8)+1,(toind%8)+1)==1&&checktomoveforgaming(board,toind,1)==1){
                        temp=board[toind];
                        board[toind]=board[fromind];
                        board[fromind]=' ';
                        nmoves++;
                        if(check(board,1)!=0){
                            nmoves--;
                        }
                        board[fromind]=board[toind];
                        board[toind]=temp;
                    }
                }
            }
        }
    }
    else if(move==2){
        nmoves=0;
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                char temp;
                int fromind=i,toind=0,fromvalid=0,tovalid=0,piecemove=0;
                if(board[fromind]!=' '){
                    toind=j;
                    if(checkfrommoveforgaming(board,fromind,2)==1&&piecemovesforgaming(board,fromind,toind,(fromind/8)+1,(fromind%8)+1,(toind/8)+1,(toind%8)+1)==1&&checktomoveforgaming(board,toind,2)==1){
                        temp=board[toind];
                        board[toind]=board[fromind];
                        board[fromind]=' ';
                        nmoves++;
                        if(check(board,2)!=0){
                            nmoves--;
                        }
                        board[fromind]=board[toind];
                        board[toind]=temp;
                    }
                }
            }
        }
    }
    return nmoves;
}
int checkfrommoveforgaming(char board[],int fromind,int move){
    switch(move){
        case 1:
        if(board[fromind]=='R'||board[fromind]=='P'||board[fromind]=='K'||board[fromind]=='B'||board[fromind]=='Q'||board[fromind]=='*'){
            return 1;
        }
        else{
            return 0;
        }
        case 2:
        if(board[fromind]=='r'||board[fromind]=='p'||board[fromind]=='k'||board[fromind]=='b'||board[fromind]=='q'||board[fromind]=='+'){
            return 1;
        }
        else{
            return 0;
        }
        default : return 0;
    }
}
int checktomoveforgaming(char board[],int toind,int move){
    switch(move){
        case 1:
        if(board[toind]=='R'||board[toind]=='P'||board[toind]=='K'||board[toind]=='B'||board[toind]=='Q'||board[toind]=='*'){
            return 0;
        }
        else{
            return 1;
        }
        case 2:
        if(board[toind]=='r'||board[toind]=='p'||board[toind]=='k'||board[toind]=='b'||board[toind]=='q'||board[toind]=='+'){
            return 0;
        }
        else{
            return 1;
        }
        default:return 0;
    }
}
int piecemovesforgaming(char board[],int fromind,int toind,int frnum,int fcnum,int trnum,int tcnum){
    int returnvalue=0;
    if(board[fromind]=='R'||board[fromind]=='r'){
        returnvalue=rook(board,frnum,fcnum,trnum,tcnum);
        return returnvalue;
    }
    else if(board[fromind]=='B'||board[fromind]=='b'){
        returnvalue=bishop(board,fromind,toind,frnum,fcnum,trnum,tcnum);
        return returnvalue;
    }
    else if(board[fromind]=='K'||board[fromind]=='k'){
        returnvalue=knight(board,frnum,fcnum,trnum,tcnum);
        return returnvalue;
    }
    else if(board[fromind]=='Q'||board[fromind]=='q'){
        returnvalue=rook(board,frnum,fcnum,trnum,tcnum)+bishop(board,fromind,toind,frnum,fcnum,trnum,tcnum);
        return returnvalue;
    }
    else if(board[fromind]=='*'||board[fromind]=='+'){
        returnvalue=king(board,frnum,fcnum,trnum,tcnum);
        return returnvalue;
    }
    else if(board[fromind]=='P'||board[fromind]=='p'){
        returnvalue=pawn(board,frnum,fcnum,trnum,tcnum,fromind,toind);
        return returnvalue;
    }
    return 0;
}
int checkgaming(int move,char board[]){
    if(move==1||move==2){
        if(calcmoves(board,move)==0&&check(board,move)!=0){
            if(move==1){
                printf("Player 2 Wins by Checkmate\n");
            }
            else if(move==2){
                printf("Player 1 Wins by Checkmate\n");
            }
            return 0;
        }
        else if(calcmoves(board,move)==0&&check(board,move)==0){
            printf("Stalemate\n");
            return 0;
        }
        else if(calcmoves(board,move)!=0){
            return 1;
        }  
    }
    else{
        if(move==0){//0 for computer
            move=2;
        }
        else if(move==-1){//1 for player when playing against computer
            move=1;
        }
        if(calcmoves(board,move)==0&&check(board,move)!=0){
            if(move==1){
                printf("Computer Wins by Checkmate\n");
            }
            else if(move==2){
                showboard1(board);
                printf("Player Wins by Checkmate\n");
            }
            return 0;
        }
        else if(calcmoves(board,move)==0&&check(board,move)==0){
            printf("Stalemate\n");
            return 0;
        }
        else if(calcmoves(board,move)!=0){
            return 1;
        }
    }
    return 1;
}
void computermove(char board[]){
    srand(time(0));
    int ctoind=0,cfromind=0;
    char temp;
    do{
        do{
            cfromind=(rand()%64);
            ctoind=(rand()%64);
        }while(!(checkfrommoveforgaming(board,cfromind,2)==1&&piecemovesforgaming(board,cfromind,ctoind,(cfromind/8)+1,(cfromind%8)+1,(ctoind/8)+1,(ctoind%8)+1)==1&&checktomoveforgaming(board,ctoind,2)==1));
        temp=board[ctoind];
        board[ctoind]=board[cfromind];
        board[cfromind]=' ';
        if(check(board,2)!=0){
            board[cfromind]=board[ctoind];
            board[ctoind]=temp;
        }
        else{
            printf("Computer plays - %c%1d to %c%1d\n",cfromind%8+97,8-cfromind/8,ctoind%8+97,8-ctoind/8);
        }
    }while(check(board,2)!=0);
}
void promotion(char board[],int move,int toind){
    char promote;
    if(move==1){
        do{
            printf("Promote to R B K Q\n");
            scanf(" %c",&promote);
            if(!(promote=='R'||promote=='B'||promote=='K'||promote=='Q')){
                printf("Enter a valid choice\n");
            }
        }while(!(promote=='R'||promote=='B'||promote=='K'||promote=='Q'));
        board[toind]=promote;
    }
    else{
        do{
            printf("Promote to r b k q\n");
            scanf(" %c",&promote);
            if(!(promote=='r'||promote=='b'||promote=='k'||promote=='q')){
                printf("Enter a valid choice\n");
            }
        }while(!(promote=='r'||promote=='b'||promote=='k'||promote=='q'));
        board[toind]=promote;
    }
}
