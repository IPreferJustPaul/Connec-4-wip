#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
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
void printswitch(int board[10][10], int turn, int i, int j){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if(turn==0){
		if(board[i][j]==93){
			printf("|");
			SetConsoleTextAttribute(hConsole, 240);
			printf("%c%c", board[i][j]-2, board[i][j]);
			SetConsoleTextAttribute(hConsole, 15);
		} else if(board[i][j]==91){
			printf("|%c%c", board[i][j], board[i][j]+2);
		} else {
			printf("|%c%c", board[i][j], board[i][j]);
		}
	} else {
		if(board[9-i][9-j]==93){
			printf("|");
			SetConsoleTextAttribute(hConsole, 240);
			printf("%c%c", board[9-i][9-j]-2, board[9-i][9-j]);
			SetConsoleTextAttribute(hConsole, 15);
		} else if(board[9-i][9-j]==91){
			printf("|%c%c", board[9-i][9-j], board[9-i][9-j]+2);
		} else {
			printf("|%c%c", board[9-i][9-j], board[9-i][9-j]);
		}
	}
}
void board_view(int board[10][10], int turn){
	int i, j, t;
	printf("\t  ");
	for(i=0;i<5;i++){
		if(turn==0){
			printf(" %d  %d ", i+1, i+1);
		} else {
			printf(" %d  %d ", 5-i, 5-i);
		}
	}
	printf("\n");
	for(i=0;i<10;i++){ 
		printf("\t  -------------------------------\n");
		if(turn==1){
			if(i<2){
				printf("\t %d", i*5);

			} else {
				printf("\t%d", i*5);
			}
		} else {
			if(i>7){
				printf("\t %d", (9-i)*5);		
			} else {
				printf("\t%d", (9-i)*5);
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
			if(board[9-x][y]<128){
				printf("Enter your move:");
				scanf("%d", &move2);
				a=(move2-1)/5;
				b=((move2-1)%5)*2+a%2;
				if((move2!=move1+5+x%2 && move2!=move1+4+x%2 && move2!=move1-5+x%2 && move2!=move1-6+x%2)|| move2>50 || move2<1 || a==x|| a>x+1 || a<x-1 || board[9-a][b]==board[9-x][y] || board[9-a][b]==board[9-x][y]+85){
					system("cls");
					printf("Try again.\n");
					goto begin;
				}
				board[9-a][b]=board[9-x][y];
				board[9-x][y]=32;
			} else if(turn==0){
				printf("Enter your move:");
				scanf("%d", &move2);
				a=(move2-1)/5;
				b=((move2-1)%5)*2+a%2;
				if((move2!=move1+5+x%2 && move2!=move1+4+x%2)|| move2>50 || move2<1 || a==x|| a>x+1 || a<x-1 || board[9-a][b]==board[9-x][y] || board[9-a][b]==board[9-x][y]-85){
					system("cls");
					printf("Try again.\n");
					goto begin;
				}
				board[9-a][b]=board[9-x][y];
				board[9-x][y]=32;
			} else {
				printf("Enter your move:");
				scanf("%d", &move2);
				a=(move2-1)/5;
				b=((move2-1)%5)*2+a%2;
				if((move2!=move1-5+x%2 && move2!=move1-6+x%2)|| move2>50 || move2<1 || a==x|| a>x+1 || a<x-1 || board[9-a][b]==board[9-x][y] || board[9-a][b]==board[9-x][y]-85){
					system("cls");
					printf("Try again.\n");
					goto begin;
				}
				if(board[9-a][b]==176+turn*2 || board[9-a][b]==91+turn*2){
				}
				board[9-a][b]=board[9-x][y];
				board[9-x][y]=32;				
			}
		}
		system("cls");
	}
	board_view(board, turn);
}

