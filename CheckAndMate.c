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
int selectionWhiteCheck(int board[8][8], int x, int y, int enemyX, int enemyY)
{	
	if(board[enemyX][enemyY] == PAWNB)
	{
		if(checkWhitePawn(board,x,y, enemyX, enemyY))
		{
			printf("You'll be checked\n");
			return 1;
		}
	}
	else if(board[enemyX][enemyY] == ROOKB)
	{
		if(checkRook(board,x,y, enemyX, enemyY))
		{
			printf("You'll be checked\n");
			return 1;
		}
	}
	else if(board[enemyX][enemyY] == BISHOPB)
	{
		if(checkBishop(board,x,y, enemyX, enemyY))
		{
			printf("You'll be checked\n");
			return 1;
		}
	}
	else if(board[enemyX][enemyY] == HORSEB)
	{
		if(checkHorse(board,x,y, enemyX, enemyY))
		{
			printf("You'll be checked\n");
			return 1;
		}
	}
	else if(board[enemyX][enemyY] == QUEENB)
	{
		if(checkQueen(board,x,y, enemyX, enemyY))
		{
			printf("You'll be checked\n");
			return 1;
		}
	}
	else if(board[enemyX][enemyY] == KINGB)
	{
		if(checkKing(board,x,y, enemyX, enemyY))
		{
			printf("You'll be checked\n");
			return 1;
		}
	}
	else
	{
		return 0;
	}
}
int selectionBlackCheck(int board[8][8], int x, int y, int enemyX, int enemyY)
{	
	if(board[enemyX][enemyY] == PAWN)
	{
		if(checkBlackPawn(board,x,y, enemyX, enemyY))
		{
			printf("You'll be checked\n");
			return 1;
		}
	}
	else if(board[enemyX][enemyY] == ROOK)
	{
		if(checkRook(board,x,y, enemyX, enemyY))
		{
			printf("You'll be checked\n");
			return 1;
		}
	}
	else if(board[enemyX][enemyY] == BISHOP)
	{
		if(checkBishop(board,x,y, enemyX, enemyY))
		{
			printf("You'll be checked\n");
			return 1;
		}
	}
	else if(board[enemyX][enemyY] == HORSE)
	{
		if(checkHorse(board,x,y, enemyX, enemyY))
		{
			printf("You'll be checked\n");
			return 1;
		}
	}
	else if(board[enemyX][enemyY] == QUEEN)
	{
		if(checkQueen(board,x,y, enemyX, enemyY))
		{
			printf("You'll be checked\n");
			return 1;
		}
	}
	else if(board[enemyX][enemyY] == KING)
	{
		if(checkKing(board,x,y, enemyX, enemyY))
		{
			printf("You'll be checked\n");
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

int checkBlackRookAndQueen(int board[8][8], int x, int y, int enemyX, int enemyY)
{
       for(int rowX = 0; rowX<8 ; rowX++)
       {
		if(rowX==x) continue;
		if(board[rowX][y] == ROOK)
		{
			if(checkRook(board,x, y, enemyX, enemyY) return 1;
		}	
		else if(board[rowX][y] == QUEEN)
		{
			if(checkQueen(board, x, y, enemyX, enemyY) return 1;
		}	
       }
       for(int colY = 0; colY<8; colY++)
       {
		if(colY=y) continue;
		if(board[x][colY]==ROOK)
		{
			if(checkRook(board ,x ,y ,enemyX, enemyY) return 1;
		}
		else if(board[x][colY] ==QUEEN)
		{
			if(checkQueen(board, x, y, enemyX, enemyY) return 1;
		}
       }
       return 0;
}


int checkBlack(int board[8][8], int x, int y, int enemyX, int enemyY)
{
	checkBlackRookAndQueen(board, x, y, enemyX, enemyY);
	checkBlackBishopAndQueen(board, x, y, enemyX, enemyY);	
}

int checkMateBlack(int board[8][8], int x, int y)
{
	if((checkBlack(board,x,y,x+1,y) || (board[x+1][y]<EMPTY && board[x+1][y]>0))
	||(checkBlack(board,x,y,x-1,y) || (board[x-1][y]<EMPTY && board[x-1][y]>0))
	||(checkBlack(board,x,y,x+1,y+1) || (board[x+1][y+1]<EMPTY && board[x+1][y+1]>0))
	||(checkBlack(board,x,y,x-1,y+1) || (board[x-1][y+1]<EMPTY && board[x-1][y+1]>0))
	||(checkBlack(board,x,y,x,y+1) || (board[x][y+1]<EMPTY && board[x][y+1]>0))
	||(checkBlack(board,x,y,x+1,y-1) || (board[x+1][y-1]<EMPTY && board[x+1][y-1]>0))
	||(checkBlack(board,x,y,x-1,y-1) || (board[x-1][y]<EMPTY && board[x-1][y]>0))
	||(checkBlack(board,x,y,x,y-1) || (board[x][y-1]<EMPTY && board[x][y-1]>0)))	 
	{
		return 1;
	}
	return 0;	
}
int checkMateWhite(int board[8][8], int x, int y)
{
	if((checkWhite(board,x,y,x+1,y) || (board[x+1][y]<EMPTY && board[x+1][y]>0))
	||(checkWhite(board,x,y,x-1,y) || (board[x-1][y]<EMPTY && board[x-1][y]>0))
	||(checkWhite(board,x,y,x+1,y+1) || (board[x+1][y+1]<EMPTY && board[x+1][y+1]>0))
	||(checkWhite(board,x,y,x-1,y+1) || (board[x-1][y+1]<EMPTY && board[x-1][y+1]>0))
	||(checkWhite(board,x,y,x,y+1) || (board[x][y+1]<EMPTY && board[x][y+1]>0))
	||(checkWhite(board,x,y,x+1,y-1) || (board[x+1][y-1]<EMPTY && board[x+1][y-1]>0))
	||(checkWhite(board,x,y,x-1,y-1) || (board[x-1][y-1]<EMPTY && board[x-1][y-1]>0))
	||(checkWhite(board,x,y,x,y-1) || (board[x][y-1]<EMPTY && board[x][y-1]>0)))	 
	{
		return 1;
	}
	return 0;
}

int checkM

