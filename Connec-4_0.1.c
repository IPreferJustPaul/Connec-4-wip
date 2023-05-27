#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
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
int main(int argc, char *argv[]) {
	int board[6][7], move, turn, h[7], i, j, w;
	char a;
	jk:
	for(j=0;j<7;j++){
		h[j]=0;
	}
	set_zero(board);
	for(i=0;1<2;i++){
		system("cls");
		w:
		board_view(board);
		if(i%2==0){
			turn=1;
		} else {
			turn=2;
		}
		scanf("%d", &move);
		move--;
		if(move>6 || move<0){
			system("cls");
			printf("Nope, try again.\n");
			goto w;
		}
		h[move]++;
		board[6-h[move]][move]=turn;
		w=win_check(board);
		if(w!=0){
			system("cls");
			board_view(board);
			printf("The %d. player is the winner!\n\n", w);
			break;
		}
	}
	printf("Do you want to play again? y/n\n");
	scanf(" %c", &a);
	if(a=='y'){
		goto jk;
	}
	return 0;
}
