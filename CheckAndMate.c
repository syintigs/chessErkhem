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
bool checkWhite(int board[8][8], int x, int y);
bool checkBlack(int board[8][8], int x, int y);
bool checkMateWhite(int board[8][8], int x, int y);
bool checkMateBlack(int board[8][8], int x, int y);
bool checkBlackLateral(int board[8][8], int x, int y);
bool checkBlackDiagonal(int board[8][8] , int x, int y);
bool checkEnemyWhiteHorse(int board[8][8], int x, int y);
bool checkBlackSurrounding(int board[8][8] , int x, int y);

bool checkBlackLateral(int board[8][8], int x, int y)
{
       printf("Check Black Lateral\n");
       for(int enemyX = 0; enemyX<8 ; enemyX++)
       {
	       printf("enemyX\n");
	       	printf("%d,%d\n",enemyX,y);
		if(enemyX==x) continue;
		if(board[enemyX][y] == ROOK)
		{
			if(checkRook(board,x, y, enemyX, y)) return true;
		}	
		else if(board[enemyX][y] == QUEEN)
		{
			if(checkQueen(board, x, y, enemyX, y)) return true;
		}	
       }
       for(int enemyY = 0; enemyY<8; enemyY++)
       {
	       if(enemyY!=5) printf("%d,%d\n",x,enemyY);
		if(enemyY==y) continue;
		if(board[x][enemyY]==ROOK)
		{
			if(checkRook(board ,x ,y ,x, enemyY)) return true;
		}
		else if(board[x][enemyY] ==QUEEN)
		{
			if(checkQueen(board, x, y, x, enemyY)) return true;
		}
       }
       return false;
}

bool checkBlackDiagonal(int board[8][8] , int x, int y)
{
	printf("Check Black Diagonal\n");
	int change;
	for(change = 1; (x-change)>=0 && (y+change)<8 ; change++)//Negative X, Positive Y. Top Right
	{
		printf("Neg X , Pos Y %d,%d \n", x-change, y+change);
		if(board[x-change][y+change]==BISHOP)
		{
			if(checkBishop(board, x, y, x-change, y+change)) return true;
		}
		else if(board[x-change][y+change]==QUEEN)
		{
			if(checkQueen(board,x,y,x-change, y+change)) return true;
		}
	}
	for(change = 1; (x-change)>=0 && (y-change)>=0; change--)//Negative X, Negative Y. Top Left
	{
		printf("Neg X, Neg Y %d,%d\n", x-change, y-change);
		if(board[x-change][y-change]==BISHOP)
		{
			if(checkBishop(board, x, y, x-change, y-change)) return true;
		}
		else if(board[x-change][y-change]==QUEEN)
		{
			if(checkQueen(board, x, y, x-change, y-change))return true;
		}
	}
	for(change = 1 ; (x+change)>8 && (y+change)>8; change++)//Positive X, Positive Y. Bottom Right
	{
		printf("Pos X, Pos Y %d,%d\n", x+change, y+change);
		if(board[x+change][y+change]==BISHOP)
		{
			if(checkBishop(board, x, y, x+change, y+change)) return true;
		}
		else if(board[x+change][y+change] == QUEEN)
		{
			if(checkQueen(board, x, y, x+change, y+change)) return true;
		}
	}
	for(change = 1; (x+change)>8 && (y-change) <=0 ; change++) //Positive X, Negative Y. Bottom Left
	{
		printf("Pos X, Neg Y %d,%d\n", x+change, y-change);
		if(board[x+change][y-change] == BISHOP)
		{
			if(checkBishop(board, x, y, x+change, y-change)) return true;
		}
		else if(board[x+change][y-change] == QUEEN)
		{
			if(checkBishop(board, x, y, x+change, y-change)) return true;
		}
	}
	return false;
}
bool checkEnemyWhiteHorse(int board[8][8], int x, int y)
{
	printf("Check enemy white horse\n");
	if(board[x+1][y+2] ==HORSE) return true;
	else if(board[x+1][y-2] ==HORSE) return true;
	else if(board[x-1][y+2] ==HORSE) return true;
	else if(board[x-1][y-2] ==HORSE) return true;
	else if(board[x+2][y+1] ==HORSE) return true;
	else if(board[x+2][y-1] ==HORSE) return true;
	else if(board[x-2][y+1] ==HORSE) return true;
	else if(board[x-2][y-1] ==HORSE) return true;
	else return false;
}

bool checkBlackSurrounding(int board[8][8] , int x, int y) // Checks the 8 spaces around the king
{
	printf("Check black surrounding\n");
	if ((board[x+1][y+1]==KING) 
	|| (board[x+1][y]==KING) 
  	|| (board[x+1][y-1]==KING) 
	|| (board[x][y+1]==KING) 
	|| (board[x][y-1]==KING)
	|| (board[x-1][y+1]==KING)
	|| (board[x-1][y]==KING) 
	|| (board[x-1][y-1]==KING)) return true;
	return false;
}
bool checkBlack(int board[8][8], int x, int y)
{
	printf("Check black\n");
	if(checkBlackLateral(board, x, y) // Enemy White Rook and Queen
	|| checkBlackDiagonal(board, x , y) // Enemy White Bishop and Queen
	|| checkEnemyWhiteHorse(board, x, y) //Enemy White Horse
       	|| checkBlackSurrounding(board, x, y)) //Enemy White King and Pawn	
	{
		printf("Black will be checked if he makes that move\n");
 		return true;
	}
	return false;
}

bool checkMateBlack(int board[8][8], int x, int y)
{
	if((checkBlack(board,x,y))
	||(checkBlack(board,x+1,y) || (board[x+1][y]!=EMPTY && board[x+1][y]<0))
	||(checkBlack(board,x-1,y) || (board[x-1][y]!=EMPTY && board[x-1][y]<0))
	||(checkBlack(board,x+1,y+1) || (board[x+1][y+1]!=EMPTY && board[x+1][y+1]<0))
	||(checkBlack(board,x-1,y+1) || (board[x-1][y+1]!=EMPTY && board[x-1][y+1]<0))
	||(checkBlack(board,x,y+1) || (board[x][y+1]!=EMPTY && board[x][y+1]<0))
	||(checkBlack(board,x+1,y-1) || (board[x+1][y-1]!=EMPTY && board[x+1][y-1]<0))
	||(checkBlack(board,x-1,y-1) || (board[x-1][y]!=EMPTY && board[x-1][y]<0))
	||(checkBlack(board,x,y-1) || (board[x][y-1]!=EMPTY && board[x][y-1]<0)))	 
	{
		printf("Black is checkmated\n");
		return true;
	}
	return false;	
}
/*
bool checkMateWhite(int board[8][8], int x, int y)
{
	if((checkWhite(board,x,y,x+1,y) || (board[x+1][y]<EMPTY && board[x+1][y]>))
	||(checkWhite(board,x,y,x-1,y) || (board[x-1][y]<EMPTY && board[x-1][y]>0))
	||(checkWhite(board,x,y,x+1,y+1) || (board[x+1][y+1]<EMPTY && board[x+1][y+1]>0))
	||(checkWhite(board,x,y,x-1,y+1) || (board[x-1][y+1]<EMPTY && board[x-1][y+1]>0))
	||(checkWhite(board,x,y,x,y+1) || (board[x][y+1]<EMPTY && board[x][y+1]>0))
	||(checkWhite(board,x,y,x+1,y-1) || (board[x+1][y-1]<EMPTY && board[x+1][y-1]>0))
	||(checkWhite(board,x,y,x-1,y-1) || (board[x-1][y-1]<EMPTY && board[x-1][y-1]>0))
	||(checkWhite(board,x,y,x,y-1) || (board[x][y-1]<EMPTY && board[x][y-1]>0)))	 
	{
		return true;
	}
	return false;
}
*/


