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

/*Table of Content
 *26 Black Pawn
 *69 Black Rook
 *94 Black Bishop
 *116 Black Horse
 *151 Black Queen
 *170 Black King
 */
int moveBlackPawn(int board[8][8], int x, int y)
{
	int checker = 0; 
	if(board[x+1][y] == EMPTY)
	{
		printf("Go forward:");
		scanf("\d\n", checker);
		if(checker==1)
		{
			board[x][y]==EMPTY;
			board[x+1][y] == PAWNB;
			return 1;
		}
	}
	else if(board[x+1][y-1]==PAWN)
	{
		printf("Eat Left:");
		scanf("\d\n", checker);
		if(checker==1)
		{
			board[x][y]==EMPTY;
			board[x+1][y-1]==PAWNB;
			return 1;
		}
	}
	else if(board[x+1][y+1]==PAWN)
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

int moveBlackRook(int board[8][8], int x, int y)
{
	int xChange; 
	int yChange; 
	printf("Choose vertical movement:")
	scanf("\d\n", xChange);
	printf("Choose horizontal movement:");
	scanf("\d\n", yChange);
	if(Change==0 && yChange ==0)
	{
		printf("Input other than 0)\n");
		return 0;
	}
	switch(board[x+xChange][y+yChange])
	{
		case QUEEN: case PAWN: case HORSE: case BISHOP: case ROOK: case EMPTY:
			board[x][y] = EMPTY;
			board[x+xChange][y+yChange=ROOK;
			return 1;
		default:
			printf("Not inside board or friendly unit \n");
			return 0;
	}
}

int moveBlackBishop(int board[8][8], int x, int y)
{
	int movement;
	printf("Move left or right(Negative for left, positive for right):");
	scanf("\d\n", movement);
	if(movement==0)
	{
		printf("Input other than 0\n");
		return 0;
	}
	switch(board[x+movement][y+movement])
	{
		case QUEEN: case PAWN: case HORSE: case BISHOP: case ROOK: case EMPTY:
			board[x][y] =EMPTY;
			board[x+movement][y+movement]=BISHOP;
			return 1;
		default:
			printf("Not inside board or friendly unit\n");
			return 0;
 	}
}

int moveBlackHorse(int board[8][8], int x, int y)
{
	int newX;
	int newY;
	printf("Choose a new X location:");
	scanf("%d\n", newX);
	printf("Choose a new Y location:");
	scanf("%d\n", newY);
	if(movement==0)
	{
		printf("Input other than 0\n");
		return 0;
	}
	switch(board[newX][newY])
	{
		case QUEEN: case PAWN: case HORSE: case BISHOP: case ROOK: case EMPTY:
			switch(board[newX]newY)
			{
				case board(x+1][y+2]: case board[x+1][y-2]:
				case board[x-1][y+2]: case board[x-1][y-2]:
				case board[x+2][y+1]: case board[x+2][y-1]:
				case board[x-2][y+1]: case board[x-2][y-1]:
					board[x][y]=EMPTY;
					board[newX][newY]=HORSE;	
					return 1;
				default:
					printf("Not a valid horse movement\n");
					return 0;
			}
		default: 
			printf("Outside board or friendly unit\n");
			return 0;
	}
}

int moveBlackQueen(int board[8][8], int x, int y)
{
	int rookOrBishop =0;
	printf("Lateral or diagonal(1 for lateral, 2 for diagonal):");
	scanf("%d\n",rookOrBishop);
	if(rookOrBishop==1)
	{
		moveBlackRook(board, x, y);
	}
	else if(rookOrBishop==2)
	{
		moveBlackBishop(board,x,y);
	}
	else
	{
		printf("Wrong input\n");
	}
}

int moveBlackKing(int board[8][8], int x, int y)
{
	int newX;
	int newY;
	printf("Choose new x:");
	scanf("%d\n", newX);
	printf("Choose new y:");
	scanf("%d\n",newY);
	switch(board[newX][newY])
	{
		case board[x][y+1]: case board[x][y-1]:
		case board[x+1][y+1]: case board[x+1][y]: case board[x+1][y-1]:
		case board[x-1][y+1]: case board[x-1][y]: case board[x-1][y-1]:
			if(check(board,x,y))
			{
				printf("You'll be checked\n");
				return 0;
			}
			board[x][y]= EMPTY;
			board[newX][newY] =KINGB;
			return 1;
	}
}
