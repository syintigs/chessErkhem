// Y and X are swapped. I got them confused. In this program X is vertical while Y is horizontal.
#include <stdio.h>

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
	return 0;
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
int movePawn(int board[8][8], int x, int y)
{
	int checker = 0; 
	if(board[x+1][y] == EMPTY)
	{
		printf("Go forward:");
		scanf("\d\n", checker);
		if(checker==1)
		{
			board[x][y]==EMPTY;
			board[x+1][y] == PAWN;
			return 1;
		}
	}
	else if(board[x+1][y-1]==PAWNB)
	{
		printf("Eat Left:");
		scanf("\d\n", checker);
		if(checker==1)
		{
			board[x][y]==EMPTY;
			board[x+1][y-1]==PAWN;
			return 1;
		}
	}
	else if(board[x+1][y+1]==PAWNB)
	{
		printf("Eat right:");
		scanf("\d\n", checker);
		if(checker==1)
		{
			board[x][y]==EMPTY;
			board[x+1][y+1] ==PAWN;
			return 1;
		}
	}
	else
	{
		printf("Choose new coordinate\n");
		return 0;
	}	
}	
int moveRook(int board[8][8], int x, int y)
{
	int xChange; 
	int yChange; 
	printf("Choose vertical movement:")
	scanf("\d\n", xChange);
	printf("Choose horizontal movement:");
	scanf("\d\n", yChange);
	ifxChange==0 && yChange ==0)
	{
		printf("Input other than 0, 0)\n");
		return 0;
	}
	else if(board[x+xChange][y+yChange]==EMPTY||board[x+xChange][y+yChange]==PAWNB||board[x+xChange][y+yChange]==HORSEB||board[x+xChange][y+yChange]==BISHOPB||board[x+xChange][y+yChange]==ROOKB||board[x+xChange][y+yChange]==QUEENB)
	{
		board[x][y]==EMPTY;
		board[x+xChange][y+yChange]==ROOK;
		return 1;
	}
	else
	{
		printf("Not inside board or friendly unit \n");
		return 0;
	}
}
	
int moveBishop(int board[8][8], int x, int y)
{
	int movement;
	printf("Move left or right(Negative for left, positive for right):");
	scanf("\d\n", movement);
	if(movement==0)
	{
		printf("Input other than 0\n");
		return 0;
	}
	else if(board[x+movement][y+movement]==EMPTY||board[x+movement][y+movement]==PAWNB||board[x+movement][y+movement]==HORSEB||board[x+movement][y+movement]==BISHOPB||board[x+movement][y+movement]==ROOKB||board[x+movement][y+movement]==QUEENB)
	{
		board[x][y] == EMPTY;
		board[x+movement][y+movement]==BISHOP;
		return 1; 
	}
	else
	{
		printf("Not inside board or friendly unit\n");
		return 0;
	}
	
}

int moveHorse(int board[8][8], int x, int y)
{
	int newPositionX;
	int newPositionY;
	printf("Choose a new X location:");
	scanf("%d\n", newPositionX);
	printf("Choose a new Y location:");
	scanf("%d\n", newPositionY);
	if(movement==0)
	{
		printf("Input other than 0\n");
		return 0;
	}
	else if(board[newPositionX][newPositionY]==EMPTY||board[newPositionX][newPositionY]==PAWNB||board[newPositionX][newPositionY]==HORSEB||board[newPositionX][newPositionY]==BISHOPB||board[newPositionX][newPositionY]==ROOKB||board[newPositionX][newPositionY]==QUEENB)
	{
		if(board[newPositionX][newPositionY]==board[x+1][y+2]||board[newPositionX][newPositionY]==board[x+1][y-2]||board[newPositionX][newPositionY]==board[x-1][y+2]||board[newPositionX][newPositionY]==board[x-1][y-2]||board[newPositionX][newPositionY]==board[x+2][y+1]||board[newPositionX][newPositionY]==board[x+2][y-1]||board[newPositionX][newPositionY]==board[x-2][y+1]||board[newPositionX][newPositionY]==board[x-2][y-1])
		{
			board[x][y]=EMPTY;
			board[newPositionX][newPositionY]=HORSE;
			return 1;
		}
		else
		{
			printf("Not a valid horse movement\n");
			return 0;
		}
	}
	else
	{
		printf("Outside board or friendly unit\n");
		return 0;
	}
}




