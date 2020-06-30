
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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

/*Table of Content
 *26 Pawn
 *69 Rook
 *94 Bishop
 *116 Horse
 *151 Queen
 *170 King
 */
int moveWhitePawn(int board[8][8],int x, int y, int newX, int newY)
{
	newX--;
	newY--;
	if(newX==x-1 &&
	(newY==y-1||newY==y+1))
	{
		return 1;
	}
	return 0;

}
		

int moveWhiteRook(int board[8][8], int x, int y, int newX, int newY)
{
	newX--;
	newY--;
	if(newY==y || newX==x)
	{
		return 1;
	}
	return 0;
}

int moveWhiteBishop(int board[8][8], int x, int y, int newX, int newY)
{
	newX--;
	newY--;
	if(abs(newX-x)==abs(newY-y))
	{
		return 1;
	}
	return 0;
}

int moveWhiteHorse(int board[8][8], int x, int y, int newX, int newY)
{
	newX--;
	newY--;
	if((newX==x+1) && (newY==y+2 || newY==y-2)
	 ||(newX==x-1) && (newY==y+2 || newY==y-2)
	 ||(newX==x+2) && (newY==y+1 || newY==y-1)
	 ||(newX==x-2) && (newY==y+1 || newY==y-1))
	{
		board[x][y]=EMPTY;
		board[newX][newY]=HORSE;
		return 1;
	}
	return 0;
}

int moveWhiteQueen(int board[8][8], int x, int y)
{
	moveWhiteRook(board, x, y);
	moveWhiteBishop(board,x,y);
}

int moveWhiteKing(int board[8][8], int x, int y)
{
	newX--;
	newY--;
	if((newX==x) && (newY==y+1 || newY==y-1)
	||(newX==x+1 || newX==x-1) && (newY==y || newY==y+1 || newY==y-1))
	{
	/* if(check(board,newX,newY)
	 {
		printf("You'll be checked\n");
		return 0;
	*/
	board[x][y]=EMPTY;
	board[newX][newY]=KING;
		return 1;
	}
	return 0;	
}
