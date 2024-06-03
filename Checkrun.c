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
			} else if(i>5){
				d=93;
			} else {
				d=91;
			}
			board[i][j]=d;
		}
	}
}
int board_check(int board[10][10], int turn){
	int i, j, d=0;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(i==0 && board[i][j]==178){
				board[i][j]=93;
			}
			if(i==9 && board[i][j]==176){
				board[i][j]=91;
			}
			if(board[i][j]==176+turn*2 || board[i][j]==91+turn*2){
				d=1;
			}
		}
	}
	return d;
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
int queen_move(int board[10][10], int move1, int x, int y, int turn){
	int move2, a, b, move3, c, d;
	if(board[9-x][y]==91+turn*2){
		printf("Try again.\n");
		return 1;
	}
	printf("Enter your move:");
	scanf("%d", &move2);
	a=(move2-1)/5;
	b=((move2-1)%5)*2+a%2;
	if((move2!=move1+5+x%2 && move2!=move1+4+x%2 && move2!=move1-5+x%2 && move2!=move1-6+x%2)|| move2>50 || move2<1 || a==x|| a>x+1 || a<x-1 || board[9-a][b]==board[9-x][y] || board[9-a][b]==board[9-x][y]+85){
		system("cls");
		printf("Try again.\n");
		return 1;
	}
	if(board[9-a][b]==176+turn*2 || board[9-a][b]==91+turn*2){
		c=a*2-x;
		d=b*2-y;
		move3=1+c*5+(d-c%2)/2;
		if(move3>50 || move3<1 || c==a|| c>x+2 || c<x-2 || board[9-c][d]!=32){
			system("cls");
			printf("Try again.\n");
			return 1;
		}
		board[9-c][d]=board[9-x][y];
		board[9-a][b]=32;
		board[9-x][y]=32;
		return 1;
	} else {
		board[9-a][b]=board[9-x][y];
		board[9-x][y]=32;
	}
	return 0;
}
int white_move(int board[10][10], int move1, int x, int y, int turn){
	int move2, a, b, move3, c, d;
	printf("Enter your move:");
	scanf("%d", &move2);
	a=(move2-1)/5;
	b=((move2-1)%5)*2+a%2;
	if((move2!=move1+5+x%2 && move2!=move1+4+x%2)|| move2>50 || move2<1 || a==x|| a>x+1 || a<x-1 || board[9-a][b]==board[9-x][y] || board[9-a][b]==board[9-x][y]-85){
		system("cls");
		printf("Try again.\n");
		return 1;
	}
	if(board[9-a][b]==176+turn*2 || board[9-a][b]==91+turn*2){
		c=a*2-x;
		d=b*2-y;
		move3=1+c*5+(d-c%2)/2;
		if(move3>50 || move3<1 || c==a|| c>x+2 || c<x-2 || board[9-c][d]!=32){
			system("cls");
			printf("Try again.\n");
			return 1;
		}
		board[9-c][d]=board[9-x][y];
		board[9-a][b]=32;
		board[9-x][y]=32;
		return 1;
	} else {
		board[9-a][b]=board[9-x][y];
		board[9-x][y]=32;
	}
	return 0;
}
int black_move(int board[10][10], int move1, int x, int y, int turn){
	int move2, a, b, move3, c, d;
	printf("Enter your move:");
	scanf("%d", &move2);
	a=(move2-1)/5;
	b=((move2-1)%5)*2+a%2;
	if((move2!=move1-5+x%2 && move2!=move1-6+x%2)|| move2>50 || move2<1 || a==x|| a>x+1 || a<x-1 || board[9-a][b]==board[9-x][y] || board[9-a][b]==board[9-x][y]-85){
		system("cls");
		printf("Try again.\n");
		return 1;
	}
	if(board[9-a][b]==176+turn*2 || board[9-a][b]==91+turn*2){
		c=a*2-x;
		d=b*2-y;
		move3=1+c*5+(d-c%2)/2;
		if(move3>50 || move3<1 || c==a|| c>x+2 || c<x-2 || board[9-c][d]!=32){
			system("cls");
			printf("Try again.\n");
			return 1;
		}
		board[9-c][d]=board[9-x][y];
		board[9-a][b]=32;
		board[9-x][y]=32;
		return 1;
	} else {
		board[9-a][b]=board[9-x][y];
		board[9-x][y]=32;
	}
	return 0;
}
int move(int board[10][10], int turn){
	int move1, x, y, move2, a, b, move3, c, d, fail;
	turn++;
	turn=turn%2;
	begin:
	board_view(board, turn);
	printf("Select your piece:");
	scanf("%d", &move1);
	if(move1==420){
		return 69;
	}
	x=(move1-1)/5;
	y=((move1-1)%5)*2+x%2;
	if(board[9-x][y]==32 || board[9-x][y]==176+turn*2 || move1>50 || move1<1){
		system("cls");
		printf("Try again.\n");
		turn=(turn+1)%2;
		return turn;
	} else {
		if(board[9-x][y]<128){
			fail=queen_move(board, move1, x, y, turn);
			if(fail==1){
				turn=(turn+1)%2;
				return turn;
			}
		} else if(turn==0){
			fail=white_move(board, move1, x, y, turn);
			if(fail==1){
				turn=(turn+1)%2;
				return turn;
			}
		} else {
							
		}
	}
	return turn;
}
int main(int argc, char *argv[]){
	int board[10][10], turn=1, move1, x, y, move2, a, b, move3, c, d;
	char response;
	while(1<2){
		reset_board(board);
		while(1<2){
			turn=move(board, turn);
			system("cls");
			if(board_check(board, turn)==0 || turn==420){
				printf("%d", turn);
				printf("Congrats player %d.\n", turn+1);
				turn=1;
				break;
				system("cls");
			}
		}
		printf("Would you like to play again? Y/N");
		while(1<2){
			if (_kbhit()) {
	    		response=_getch();
	    	}
	    	if (response=='Y' || response=='y' || response=='Z' || response=='z'){
	    		turn=1;
	    		system("cls");
	    		break;
			} else if (response=='N' || response=='n'){
				return 0;
			}
		}
	}
}
