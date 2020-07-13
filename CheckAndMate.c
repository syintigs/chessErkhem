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

int checkBlackLateral(int board[8][8], int x, int y)
{
       for(int enemyX = 0; enemyX<8 ; enemyX++)
       {
		if(enemyX==x) continue;
		if(board[enemyX][y] == ROOK)
		{
			if(checkRook(board,x, y, enemyX, y) return 1;
		}	
		else if(board[enemyX][y] == QUEEN)
		{
			if(checkQueen(board, x, y, enemyX, y) return 1;
		}	
       }
       for(int enemyY = 0; enemyY<8; enemyY++)
       {
		if(enemyY=y) continue;
		if(board[x][enemyY]==ROOK)
		{
			if(checkRook(board ,x ,y ,x, enemyY) return 1;
		}
		else if(board[x][enemyY] ==QUEEN)
		{
			if(checkQueen(board, x, y, x, enemyY) return 1;
		}
       }
       return 0;
}

int checkBlackDiagonal(int board[8][8] , int x, int y)
{
	int change;
	for(change = 1; (x-change)>=0 && (y+change)<8 ; change++)//Negative X, Positive Y. Top Right
	{
		if(board[x-change][y+change]==BISHOP)
		{
			if(checkBishop(board, x, y, x-change, y+change) return 1;
		}
		else if(board[x-change][y+change]==QUEEN)
		{
			if(checkQueen(board,x,y,x-change, y+change) return 1;
		}
	}
	for(change = 1; (x-change)>=0 && (y-change)>=0; change--)//Negative X, Negative Y. Top Left
	{
		if(board[x-change][y-change]==BISHOP)
		{
			if(checkBishop(board, x, y, x-change, y-change) return 1;
		}
		else if(board[x-change][y-change]==QUEEN)
		{
			if(checkQueen(board, x, y, x-change, y-change)return 1;
		}
	}
	for(change = 1 ; (x+change)>8 && (y+change)>8; change++)//Positive X, Positive Y. Bottom Right
	{
		if(board[x+change][y+change]==BISHOP)
		{
			if(checkBishop(board, x, y, x+change, y+change)) return 1;
		}
		else if(board[x+change][y+change] == QUEEN)
		{
			if(checkQueen(board, x, y, x+change, y+change)) return 1;
		}
	}
	for(change = 1; (x+change)>8 && (y-change) <=0 ; change++) //Positive X, Negative Y. Bottom Left
	{
		if(board[x+change][y-change] == BISHOP)
		{
			if(checkBishop(board, x, y, x+change, y-change)) return 1;
		}
		else if(board[x+change][y-change] == QUEEN)
		{
			if(checkBishop(board, x, y, x+change, y-change)) return 1;
		}
	}
}
int checkEnemyWhiteHorse(int board[8][8], int x, int y)
{
	if(board[x+1][y+2] ==HORSE) return 1;
	else if(board[x+1][y-2] ==HORSE) return 1;
	else if(board[x-1][y+2] ==HORSE) return 1;
	else if(board[x-1][y-2] ==HORSE) return 1;
	else if(board[x+2][y+1] ==HORSE) return 1;
	else if(board[x+2][y-1] ==HORSE) return 1;
	else if(board[x-2][y+1] ==HORSE) return 1;
	else if(board[x-2][y-1] ==HORSE) return 1;
	else return 0;
}

int checkBlackSurrounding(int board[8][8] , int x, y) // Checks the 8 spaces around the king
{
	if(board[x+1][y+1]==KING) return 1;
	else if(board[x+1][y]==KING) return 1;
	else if(board[x+1][y-1]==KING) return 1;
	else if(board[x][y+1]==KING) return 1;
	else if(board[x][y-1]==KING) return 1;
	else if(board[x-1][y+1]==KING) return 1;
	else if(board[x-1][y]==KING) return 1;
	else if(board[x-1][y-1]==KING) return 1;


}
int checkBlack(int board[8][8], int x, int y)
{
	checkBlackLateral(board, x, y);		// Enemy White Rook and Queen
	checkBlackDiagonal(board, x, y);	// Enemy White Bishop and Queen
	checkEnemyWhiteHorse(board, x, y);	
}

int checkMateBlack(int board[8][8], int x, int y)
{
	if((checkBlack(board,x,y))
	||((checkBlack(board,x+1,y) || (board[x+1][y]!=EMPTY && board[x+1][y]<0))
	||(checkBlack(board,x-1,y) || (board[x-1][y]!=EMPTY && board[x-1][y]<0))
	||(checkBlack(board,x+1,y+1) || (board[x+1][y+1]!=EMPTY && board[x+1][y+1]<0))
	||(checkBlack(board,x-1,y+1) || (board[x-1][y+1]!=EMPTY && board[x-1][y+1]<0))
	||(checkBlack(board,x,y+1) || (board[x][y+1]!=EMPTY && board[x][y+1]<0))
	||(checkBlack(board,x+1,y-1) || (board[x+1][y-1]!=EMPTY && board[x+1][y-1]<0))
	||(checkBlack(board,x-1,y-1) || (board[x-1][y]!=EMPTY && board[x-1][y]<0))
	||(checkBlack(board,x,y-1) || (board[x][y-1]!=EMPTY && board[x][y-1]<0)))	 
	{
		return 1;
	}
	return 0;	
}
int checkMateWhite(int board[8][8], int x, int y)
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
		return 1;
	}
	return 0;
}


