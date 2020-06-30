// Y and X are swapped. I got them confused. In this program X is vertical while Y is horizontal.
#include <stdio.h>
#include <stdbool.h>
#include "WhiteMovement.h"
#include "BlackMovement.h"
#include "CheckAndMate.h"
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

int chooseWhiteUnit(int board[8][8])
{
	int x;
	int y;
	printf("Input x:");
	scanf("%d",&y);
	printf("Input y:");
	scanf("%d",&x);
	x--;
	y--;
	if(board[x][y]==PAWN)
	{
		return moveWhitePawn(board,x,y);
	}
	else if(board[x][y]==BISHOP)
	{
		return moveWhiteBishop(board,x,y);
	}
	else if(board[x][y]==ROOK)
	{
		return moveWhiteRook(board,x,y);
	}
	else if(board[x][y]==QUEEN)
	{
		return moveWhiteQueen(board,x,y);
	}
	else if(board[x][y]==HORSE)
	{
		return moveWhiteHorse(board,x,y);
	}
	else if(board[x][y]==KING)
	{
		return moveWhiteKing(board,x,y);
	}
	else
	{
		printf("Choose your own unit\n");
		return 0;
	}
}
int chooseBlackUnit(int board[8][8])
{
	int x;
	int y;
	printf("Input x:");
	scanf("%d",&y);
	printf("Input y:");
	scanf("%d",&x);
	x--;
	y--;
	if(board[x][y]==PAWNB)
	{
		return moveBlackPawn(board,x,y);
	}
	else if(board[x][y]==BISHOPB)
	{
		return moveBlackBishop(board,x,y);
	}
	else if(board[x][y]==ROOKB)
	{
		return moveBlackRook(board,x,y);
	}
	else if(board[x][y]==QUEENB)
	{
		return moveBlackQueen(board,x,y);
	}
	else if(board[x][y]==HORSEB)
	{
		return moveBlackHorse(board,x,y);
	}
	else if(board[x][y]==KINGB)
	{
		return moveBlackKing(board,x,y);
	}
	else
	{
		printf("Choose your own unit\n");
		return 0;
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
			if(j==0 && i ==0)
			{
				printf("         ");
			}
			else if(j==0)
			{
				printf(GREEN "%d        " COLORRESET, i);
			}
			else if(i==0)
			{
				printf(GREEN "%d      " COLORRESET, j);
			}
			else
			{
				switch(board[i-1][j-1])
				{
					
					case EMPTY:  printf(RED "-      " COLORRESET); break;
					case PAWN:  printf(GREEN "P      " COLORRESET);break;
					case HORSE:  printf(GREEN "H      " COLORRESET);break;
					case BISHOP:  printf(GREEN "B      " COLORRESET);break;
					case ROOK:  printf(GREEN "R      " COLORRESET);break;
					case QUEEN:  printf(GREEN "Q      " COLORRESET);break;
					case KING:  printf(GREEN "K      " COLORRESET);break;
					case PAWNB:  printf(RED "P      " COLORRESET);break;
					case HORSEB: printf(RED "H      " COLORRESET);break;
					case BISHOPB:  printf(RED "B      " COLORRESET);break;
					case ROOKB:  printf(RED "R      " COLORRESET);break;
					case QUEENB:  printf(RED "Q      " COLORRESET);break;
					case KINGB:  printf(RED "K      " COLORRESET);break;
				}	
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


int checkBoardForCheckmate(int board[8][8]


int main(void)
{
	int cycle = 1;
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
		if(cycle==1)
			if(chooseWhiteUnit(chessBoard))
			{
				cycle=0;
			}	
		if(cycle==0)
		{
			if(chooseBlackUnit(chessBoard))
			{
				cycle =1;
			}
		}	
	}

	
		
	return 0;
}	
