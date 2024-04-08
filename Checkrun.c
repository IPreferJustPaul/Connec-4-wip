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
				d=48;
			} else {
				d=221;
			}
			board[i][j]=d;
		}
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
	int board[8][8], turn=1, move_y, move_x;
//	char move_x;
	reset_board(board);
	while(1<2){
		turn++;
		turn=turn%2;
		board_view(board, turn);
		printf("Enter your move:");
		scanf("%c %d", &move_x, &move_y);
		board[move_y-1][toupper(move_x)-65]=84;
		printf("\n");
	}
}
