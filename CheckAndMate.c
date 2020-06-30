#include <stdio.h>
#include <stdbool.h>
#include "MovementAccessibility.h"

#define EMPTY 9
#define PAWN 1
#define HORSE 2
#define BISHOP 3
#define ROOK 4
#define	QUEEN 5
#define KING 6
#define PAWNB -1
#define HORSEB -2
#define BISHOPB -3
#define ROOKB -4
#define QUEENB -5
#define KINGB -6

//CHANGE THIS FUNCTION UP. MOVE FUNCTIONS EXECUTE COMMANDS OTHER THAN JUST RETURNING
int check(int board[8][8], int x, int y, int enemyX, int enemyY)
{	
	if(checkPawn(board,x,y, enemyX, enemyY))
	{
		printf("You'll be checked\n");
		return 1;
	}
	else if(checkRook(board,x,y, enemyX, enemyY))
	{
		printf("You'll be checked\n");
		return 1;
	}
	else if(checkBishop(board,x,y, enemyX, enemyY))
	{
		printf("You'll be checked\n");
		return 1;
	}
	else if(checkHorse(board,x,y, enemyX, enemyY))
	{
		printf("You'll be checked\n");
		return 1;
	}
	else if(checkQueen(board,x,y, enemyX, enemyY))
	{
		printf("You'll be checked\n");
		return 1;
	}
}
int checkMate(int board[8][8], int x, int y)
{
	if((check(board,x,y,x+1,y) || (board[x+1][y]<EMPTY && board[x+1][y]>0))
	||(check(board,x,y,x-1,y) || (board[x-1][y]<EMPTY && board[x-1][y]>0))
	||(check(board,x,y,x+1,y+1) || (board[x+1][y+1]<EMPTY && board[x+1][y+1]>0))
	||(check(board,x,y,x-1,y+1) || (board[x-1][y+1]<EMPTY && board[x-1][y+1]>0))
	||(check(board,x,y,x,y+1) || (board[x][y+1]<EMPTY && board[x][y+1]>0))
	||(check(board,x,y,x+1,y-1) || (board[x+1][y-1]<EMPTY && board[x+1][y-1]>0))
	||(check(board,x,y,x-1,y-1) || (board[x-1][y]<EMPTY && board[x-1][y]>0))
	||(check(board,x,y,x,y-1) || (board[x][y-1]<EMPTY && board[x][y-1]>0)))	 
	{
		return 1;
	}
	return 0;
	
}


		




