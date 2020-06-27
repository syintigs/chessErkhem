// Y and X are swapped. I got them confused. In this program X is vertical while Y is horizontal.
#include <stdio.h>
#include <stdbool.h>
#include "WhiteMovement.h"
#include "BlackMovement.h"
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

#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define BLUE  "\x1b[34m"
#define COLORRESET "\x1b[0m"

void chooseWhiteUnit(int board[8][8])
{
	int x;
	int y;
	printf("Input x:");
	scanf("%d",&x);
	printf("Input y:");
	scanf("%d",&y);
	if(board[x][y]==PAWN)
	{
		moveWhitePawn(board,x,y);
	}
	else if(board[x][y]==BISHOP)
	{
		moveWhiteBishop(board,x,y);
	}
	else if(board[x][y]==ROOK)
	{
		moveWhiteRook(board,x,y);
	}
	else if(board[x][y]==QUEEN)
	{
		moveWhiteQueen(board,x,y);
	}
	else if(board[x][y]==HORSE)
	{
		moveWhiteHorse(board,x,y);
	}
	else if(board[x][y]==KING)
	{
		moveWhiteKing(board,x,y);
	}
	else
	{
		printf("Choose your own unit\n");
	}
}
void printBoard(int board[8][8])
{
	int i;
	int j;
	for(i = 0; i<9; i++)
	{
		for(j=0;j<9;j++)
		{
			if(j==0)
			{
				printf(GREEN "%d        " COLORRESET, i);
			}
			else if(i==0)
			{
				printf(GREEN "%d      " COLORRESET, j);
			}

			else if(board[i-1][j-1]==EMPTY)
			{
				printf(GREEN "-      " COLORRESET);
			}
			else if(board[i-1][j-1]==PAWN)
			{
				printf(GREEN "P      " COLORRESET);
			}
			else if(board[i-1][j-1]==ROOK)
			{
				printf(GREEN "R      " COLORRESET);
			}
			else if(board[i-1][j-1]==BISHOP)
			{
				printf(GREEN "B      " COLORRESET);
			}
			else if(board[i-1][j-1]==QUEEN)
			{
				printf(GREEN "Q      " COLORRESET);
			}
			else if(board[i-1][j-1]==KING)
			{
				printf(GREEN "K      " COLORRESET);
			}
			else if(board[i-1][j-1]==HORSE)
			{
				printf(GREEN "H      " COLORRESET);
			}
			else if(board[i-1][j-1]==PAWNB)
			{
				printf(RED "P      " COLORRESET);
			}
			else if(board[i-1][j-1]==ROOKB)
			{
				printf(RED "R      " COLORRESET);
			}
			else if(board[i-1][j-1]==BISHOPB)
			{
				printf(RED "B      " COLORRESET);
			}
			else if(board[i-1][j-1]==QUEENB)
			{
				printf(RED "Q      " COLORRESET);
			}
			else if(board[i-1][j-1]==KINGB)
			{
				printf(RED "K      " COLORRESET);
			}
			else if(board[i-1][j-1]==HORSEB)
			{
				printf(RED "H      " COLORRESET);
			}
		}
		if(i==0)
		{	
			printf("\n\n\n\n\n");
		}
		else
		{
			printf("\n\n\n");
		}
	}
}	
int main(void)
{
	int chessBoard[8][8] = {
		{ ROOKB, HORSEB, BISHOPB, QUEENB, KINGB, BISHOPB, HORSEB, ROOKB},
		{ PAWNB,PAWNB,PAWNB,PAWNB,PAWNB,PAWNB,PAWNB,PAWNB},
		{EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
		{EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
		{EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
		{EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
		{ PAWN,PAWN,PAWN,PAWN,PAWN,PAWN,PAWN,PAWN},
		{ ROOK, HORSE, BISHOP, QUEEN, KING, BISHOP, HORSE, ROOK}
	};
	while(1)
	{
		printBoard(chessBoard);
		chooseWhiteUnit(chessBoard);
	}
		
	return 0;
}	
