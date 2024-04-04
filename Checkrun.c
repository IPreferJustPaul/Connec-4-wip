#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reset_board(int board[8][8]){
	int i, j, d;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(i==3 || i==4 || (i+j)%2==1){
				d=32;
			} else if(i<4){
				d=176;
			} else {
				d=178;
			}
			board[i][j]=d;
		}
	}
}
void (){
	printf("Enter your move, L for left or R for Right");
	scanf("%c", &move);
	if((move)){
		
	}
}
void printswitch(int board[8][8], int turn, int i, int j){
	if(turn==0){
		printf("|%c%c", board[i][j], board[i][j]);
	} else {
		printf("|%c%c", board[7-i][7-j], board[7-i][7-j]);
	}
}
void board_view(int board[8][8], int turn){
	int i, j, t;
	printf(" ");
	for(i=0;i<8;i++){
		if(turn==0){
			printf(" %c ", i+65);
		} else {
			printf(" %c ", 72-i);
		}
	}
	printf("\n");
	for(i=0;i<8;i++){ 
		printf(" -------------------------\n");
		if(turn==0){
			printf("%d", i+1);
		} else {
			printf("%d", 8-i);
		}
		for(j=0;j<8;j++){
			printswitch(board, turn, i, j);
		}
		printf("|\n");
	}
	printf(" -------------------------\n");
}
int main(int argc, char *argv[]){
	int board[8][8], turn=1, move_y, move_x, move;
//	char move_x;
	reset_board(board);
	while(1<2){
		turn++;
		turn=turn%2;
		begin:
		board_view(board, turn);
		printf("Select your piece:");
		scanf("%c %d", &move_x, &move_y);
		if(board[move_y-1][toupper(move_x)-65]==32 || toupper(move_x)-65>7 || toupper(move_x)-65<0 || move_y-1>7 || move_y-1<0){
			system("cls");
			printf("Try again.\n");
			goto begin;
		} else {
			if(board[move_y-1][toupper(move_x)-65]>200){
				
			}
		}
		system("cls");
	}
}
