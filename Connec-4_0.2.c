#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
void set_zero(int a[6][7]){
	int i, j;
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			a[i][j]=0;
		}
	}
}
void board_view(int a[6][7]){
	int i, j;
	printf("\t");
	for(i=0;i<7;i++){
		printf(" %d", i+1);
	}
	printf("\n");
	for(i=0;i<6;i++){
		printf("\t");
		for(j=0;j<7;j++){
			printf("|");
			if(a[i][j]==1){
				printf("X");
			} else if(a[i][j]==2) {
				printf("O");
			} else {
				printf(" ");
			}
		}
		printf("|\n");
	}
	printf("\t");
	for(i=0;i<7;i++){
		printf("__");
	}
	printf("_\n");
}
int win_check(int a[6][7]){
	int i, j, w, r; 
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			if(a[i][j]>0){
				if(a[i][j]==1){
					w=1;
				} else if (a[i][j]==2){
					w=2;
				}
				if(i<3){
					if(j<4){
						for(r=0;r<4;r++){
							if(a[i+r][j+r]!=w){
								break;
							}
							if(r==3){
								return w;
							}
						}
					}
					if(j>2){
						for(r=0;r<4;r++){
							if(a[i+r][j-r]!=w){
								break;
							}
							if(r==3){
								return w;
							}
						}
					}
					for(r=0;r<4;r++){
						if(a[i+r][j]!=w){
							break;
						}
						if(r==3){
							return w;
						}
					}
				}
				if(j<4){
					for(r=0;r<4;r++){
						if(a[i][j+r]!=w){
							break;
						}
						if(r==3){
							return w;
						}
					}
				}
			}
		}
	}
	return 0;
}
void tutorial(int a[6][7]){
	int q;
	char f[9];
	set_zero(a);
	board_view(a);
	printf("This is the game board, it is vertical.\nBy entering a number from 1 to 7 you can drop a piece down the column of the same number. Try it!\n");
	scanf("%d", &q);
	q--;
	a[5][q]=1;
	board_view(a);
	sleep(3);
	printf("The game is played in turns with each player dropping a piece each turn. Pieces fall on top of others, for example:\n");
	a[4][q]=1;
	board_view(a);
	sleep(6);
	printf("The first player's pieces are represented by Xs, and the second player's by Os.\n\n");
	printf("The goal of the game is to line up 4 of your pieces horizontally, vertically or diagonally:\n");
	set_zero(a);
	a[5][1]=2;
	a[5][2]=2;
	a[5][3]=2;
	a[5][4]=2;
	board_view(a);
	sleep(5);
	set_zero(a);
	a[5][1]=1;
	a[4][1]=1;
	a[3][1]=1;
	a[2][1]=1;
	board_view(a);
	sleep(1);
	set_zero(a);
	a[2][0]=1;
	a[3][1]=1;
	a[4][2]=1;
	a[5][3]=1;
	a[3][0]=2;
	a[4][0]=2;
	a[5][0]=2;
	a[4][1]=2;
	a[5][1]=2;
	a[5][2]=1;
	board_view(a);
	sleep(1);
	printf("If you think you're ready to play, type \"ok\". Otherwise feel free to reread.\n");
	scanf("%s", f);
}
int main(int argc, char *argv[]) {
	int board[6][7], move, turn, h[7], i, j, w;
	char p1[15], p2[15], name[15], a;
	printf("\t OOO   OOO   O   O  O   O  OOOO   OOO  OOOOO	O  O\n\tO     O   O  OO  O  OO  O  O     O       O   	O  O\n\tO     O   O  O O O  O O O  OOO   O       O  	OOOOO\n\tO     O   O  O  OO  O  OO  O     O       O  	   O\n\t OOO   OOO   O   O  O   O  OOOO   OOO    O  	   O\n\n");
	printf("*if you don't know how to play type \"info\" for some extra help,\n otherwise type \"ok\" and enjoy ;)\n");
	scanf("%s", name);
	if(tolower(name[0])=='i' && tolower(name[1])=='n' && tolower(name[2])=='f' && tolower(name[3])=='o'){
		tutorial(board);
	}
	system("cls");
	jk:
	for(j=0;j<7;j++){
		h[j]=0;
	}
	printf("Player 1, please enter your name.\n");
	scanf("%s", p1);
	printf("Player 2, please enter your name.\n");
	scanf("%s", p2);
	set_zero(board);
	for(i=0;1<2;i++){
		system("cls");
		w:
		board_view(board);
		if(i%2==0){
			turn=1;
			strcpy(name, p1);
		} else {
			turn=2;
			strcpy(name, p2);
		}
		printf("\n");
		printf("%s's turn:\n", name);
		scanf("%d", &move);
		move--;
		h[move]++;
		if(move>6 || move<0 || h[move]>6){
			system("cls");
			printf("Nope, try again.\n");
			goto w;
		}
		board[6-h[move]][move]=turn;
		w=win_check(board);
		if(w!=0){
			system("cls");
			board_view(board);
			printf("The winner is %s!\n\n", name);
			break;
		}
	}
	printf("Do you want to play again? y/n\n");
	scanf(" %c", &a);
	if(tolower(a)=='y' || tolower(a)=='z'){
		system("cls");
		goto jk;
	}
	return 0;
}
