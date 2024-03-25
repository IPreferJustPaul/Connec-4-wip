#include <stdio.h>
#include <stdlib.h>
void reset_board(int board[8][8]){
	int i, j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			board[i][j]=0;
		}
	}
}
void printswitch(int board[8][8], int turn, int i, int j){
	if(turn==0){
		printf("|%c%c", board[i][j]+65, board[i][j]+65);
	} else {
		printf("|%c%c", board[7-i][7-j]+65, board[7-i][7-j])+65;
	}
}
void board_view(int board[8][8], int turn){
	int i, j;
	for(i=0;i<8;i++){ 
		printf("-------------------------\n");
		for(j=0;j<8;j++){
			printswitch(board, turn, i, j);
		}
		printf("|\n");
	}
	printf("-------------------------\n");
}
int main(int argc, char *argv[]){
	int board[8][8], turn=0;
	reset_board(board);
	board_view(board, turn);
}
