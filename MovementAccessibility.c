
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
bool checkWhitePawn(int board[8][8],int x, int y, int enemyX, int enemyY);
bool checkBlackPawn(int board[8][8],int x, int y, int enemyX, int enemyY);
bool checkRook(int board[8][8], int x, int y, int enemyX, int enemyY);
bool checkBishop(int board[8][8], int x, int y, int enemyX, int enemyY);
//bool checkHorse(int board[8][8], int x, int y, int enemyX, int enemyY);
bool checkQueen(int board[8][8], int x, int y, int enemyX, int enemyY);
bool checkKing(int board[8][8], int x, int y, int enemyX, int enemyY);


bool checkWhitePawn(int board[8][8],int x, int y, int enemyX, int enemyY)
{
	if(enemyX==x-1 &&
	(enemyY==y-1||enemyY==y+1))
	{
		return true;
	}
	return false;

}

bool checkBlackPawn(int board[8][8],int x, int y, int enemyX, int enemyY)
{
	if(enemyX==x+1 &&
	(enemyY==y-1||enemyY==y+1))
	{
		return true;
	}
	return false;

}
		

bool checkRook(int board[8][8], int x, int y, int enemyX, int enemyY)
{
	printf("check rook %d,%d \n",enemyX,enemyY);
	if(enemyY==y)
	{
		int xChange = abs(enemyX-x);
		if(enemyX>x)
		{
			for(int i=1; i<xChange; i++)
			{
				if(board[enemyX-i][enemyY]<EMPTY) //Anything other than EMPTY
				{
					return false;
				}
			}
		}	
		else if(x>enemyX)
		{
			for(int i = 1; i<xChange; i++)
			{
				if(board[enemyX+1][enemyY]<EMPTY) //Anything other than EMPTY
				{
					return false;
				}
			}
		}
		return true;
	}
	else if(enemyX ==x)
	{
		int yChange = abs(enemyY-x);
		if(enemyY>y)
		{
			for(int i=1; i<yChange; i++)
			{
				if(board[enemyX][enemyY-i]<EMPTY) //Anything other than EMPTY
				{
					return false;
				}
			}
		}	
		else if(y>enemyY)
		{
			for(int i = 1; i<yChange; i++)
			{
				if(board[enemyX][enemyY+i]<EMPTY) //Anything other than EMPTY
				{
					return false;
				}
			}
		}
		return true;
				
	}
	return false;
}

bool checkBishop(int board[8][8], int x, int y, int enemyX, int enemyY)
{
	if(abs(enemyX-x)==abs(enemyY-y))
	{
		int change = abs(enemyX-x);
		if(enemyX>x && enemyY>y)
		{
			for(int i=1; i<change; i++)
			{
				if(board[enemyX-i][enemyY-i]<EMPTY) //true if Anything other than EMPTY
				{
					return false;
				}
			}
		}	
		else if(enemyX>x && y>enemyY)
		{
			for(int i = 1; i<change; i++)
			{
				if(board[enemyX-i][enemyY+i]<EMPTY) //true if Anything other than EMPTY
				{
					return false;
				}
			}
		}
		else if(x>enemyX && enemyY>y)
		{
			for(int i = 0; i<change; i++)
			{
				if(board[enemyX+i][enemyY-i]<EMPTY) //true if anyhthing other than EMPTY
				{
					return false;
				}
			}
		}
		else if(x>enemyX && y>enemyY)
		{
			for(int i = 1; i<change; i++)
			{
				if(board[enemyX+i][enemyY+i]<EMPTY) //true if Anything other than EMPTY
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

/*
bool checkHorse(int board[8][8], int x, int y, int enemyX, int enemyY)
{
	if((enemyX==x+1) && (enemyY==y+2 || enemyY==y-2)
	 ||(enemyX==x-1) && (enemyY==y+2 || enemyY==y-2)
	 ||(enemyX==x+2) && (enemyY==y+1 || enemyY==y-1)
	 ||(enemyX==x-2) && (enemyY==y+1 || enemyY==y-1))
	{
		board[x][y]=EMPTY;
		board[enemyX][enemyY]=HORSE;
		return true;
	}
	if(
	return false;
}
	*/

bool checkQueen(int board[8][8], int x, int y, int enemyX, int enemyY)
{
	printf("Check queen %d,%d\n",enemyX,enemyY);
	if(checkRook(board, x, y, enemyX, enemyY) || checkBishop(board,x,y, enemyX, enemyY))
	{
		return true;
	}
	return false;
}

bool checkKing(int board[8][8], int x, int y, int enemyX, int enemyY)
{
	if((enemyX==x) && (enemyY==y+1 || enemyY==y-1)
	||(enemyX==x+1 || enemyX==x-1) && (enemyY==y || enemyY==y+1 || enemyY==y-1))
	{
		return true;
	}
	return false;	
}
