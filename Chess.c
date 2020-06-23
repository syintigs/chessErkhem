// Y and X are swapped. I got them confused. In this program X is vertical while Y is horizontal.
#include <stdio.h>
#include <stdbool.h>
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
		chooseWhiteUnit;
	}
		
	return 0;
}	
void chooseWhiteUnit(int board[8][8], int x, int y)
{
	if(board[x][y]==PAWN)
	{
		movePawn(board,x,y);
	}
	if(board[x][y]==BISHOP)
	{
		moveBishop(board,x,y);
	}
	if(board[x][y]==ROOK)
	{
		moveRook(board,x,y);
	}
	if(board[x][y]==QUEEN)
	{
		moveQueen(board,x,y);
	}
	if(board[x][y]==HORSE)
	{
		moveHorse(board,x,y);
	}
	if(board[x][y]==KING)
	{
		moveKing(board,x,y);
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
	for(i = 0; i<8; i++)
	{
		for(j=0;j<8;j++)
		{
			if(board[i][j]==EMPTY)
			{
				prinf("--");
			}
			else
			{
				printf(board[i][j]);
			}
		}
		printf("\n");
	}
}	
