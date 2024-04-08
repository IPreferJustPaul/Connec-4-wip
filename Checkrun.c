#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reset_board(int board[10][10]){
	int i, j, d;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(i==5 || i==4 || (i+j)%2==0){
				d=32;
			} else if(i<5){
				d=176;
			} else {
				d=178;
			}
			board[i][j]=d;
		}
	}
}
/*void (){
	printf("Enter your move, L for left or R for Right");
	scanf("%c", &move);
	if((move)){
		
	}
}*/
void printswitch(int board[10][10], int turn, int i, int j){
	if(turn==0){
		printf("|%c%c", board[i][j], board[i][j]);
	} else {
		printf("|%c%c", board[9-i][9-j], board[9-i][9-j]);
	}
}
void board_view(int board[10][10], int turn){
	int i, j, t;
	printf("\t  ");
	for(i=0;i<10;i++){
		if(turn==0){
			printf(" %c ", i+65);
		} else {
			printf(" %c ", 74-i);
		}
	}
	printf("\n");
	for(i=0;i<10;i++){ 
		printf("\t  -------------------------------\n");
		if(turn==1){
			if(i+1==10){
				printf("\t%d", i+1);
			} else {
				printf("\t %d", i+1);
			}
		} else {
			if(10-i==10){
				printf("\t%d", 10-i);
			} else {
				printf("\t %d", 10-i);
			}
		}
		for(j=0;j<10;j++){
			printswitch(board, turn, i, j);
		}
		printf("|\n");
	}
	printf("\t  -------------------------------\n");
}
int main(int argc, char *argv[]){
	int board[10][10], turn=1, move1, x, y, move2, a, b;
	reset_board(board);
	while(1<2){
		turn++;
		turn=turn%2;
		begin:
		board_view(board, turn);
		printf("Select your piece:");
		scanf("%d", &move1);
		x=(move1-1)/5;
		y=((move1-1)%5)*2+x%2;
		if(board[9-x][y]==32 || board[9-x][y]==176+turn*2 || move1>50 || move1<1){
			system("cls");
			printf("Try again.\n");
			goto begin;
		} else {
			if(1<2){
				printf("Enter your move:");
				scanf("%d", &move2);
				a=(move2-1)/5;
				b=((move2-1)%5)*2+a%2;
				if((move2!=move1+5+x%2 && move2!=move1+4+x%2 && move2!=move1-5+x%2 && move2!=move1-6+x%2)|| move2>50 || move2<1 || a==x|| a>x+1 || a<x-1){
					system("cls");
					printf("Try again.\n");
					goto begin;
				}
				board[9-a][b]=board[9-x][y];
				board[9-x][y]=32;
			}
		}
		system("cls");
	}
	board_view(board, turn);
}
