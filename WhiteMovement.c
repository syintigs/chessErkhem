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
 *26 Pawn
 *69 Rook
 *94 Bishop
 *116 Horse
 *151 Queen
 *170 King
 */
int movePawn(int board[8][8], int x, int y)
{
	int newX;
       	int newY;	
	printf("Choose new X:");
	scanf("%d\n",newX);
	printf("Choose new Y:");
	scanf("%d\n",newY);
	switch(board[newX][newY])
	{
		case QUEENB: case PAWNB: case HORSEB: case BISHOPB: case ROOKB: case EMPTY:
			switch(board[newX][newY])
			{
			case board[x+1][y]: case board[x+1][y-1]: case board[x+1][y+1]:
				board[x][y]=EMPTY;
				board[newX][newY]=PAWN;
				return 1;
			}	
	}
	printf("Choose new coordinates.\n");
	return 0;

}
		

int moveRook(int board[8][8], int x, int y)
{
	int newX; 
	int newY; 
	printf("Choose new X:")
	scanf("\d\n", newX);
	printf("Choose new Y:");
	scanf("\d\n", newY);
	if(newX==x && newY ==y)
	{
		printf("Input other than where you are\n");
		return 0;
	}
	switch(board[newX][newY])
	{
		case QUEENB: case PAWNB: case HORSEB: case BISHOPB: case ROOKB: case EMPTY:
			switch(board[newX][newY])
			{
			 	case board[newX][y]: case board[x][newY]
					board[x][y]= EMPTY;
					board[newX][newY]=ROOK;
					return 1;
				default:
					printf("Not a rook movement\n");
					return 0;
			}
		
		default:
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
	switch(board[x+movement][y+movement])
	{
		case QUEENB: case PAWNB: case HORSEB: case BISHOPB: case ROOKB: case EMPTY:
			board[x][y] =EMPTY;
			board[x+movement][y+movement]=BISHOP;
			return 1;
		default:
			printf("Not inside board or friendly unit\n");
			return 0;
 	}
}

int moveHorse(int board[8][8], int x, int y)
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
		case QUEENB: case PAWNB: case HORSEB: case BISHOPB: case ROOKB: case EMPTY:
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

int moveQueen(int board[8][8], int x, int y)
{
	int rookOrBishop =0;
	printf("Lateral or diagonal(1 for lateral, 2 for diagonal):");
	scanf("%d\n",rookOrBishop);
	if(rookOrBishop==1)
	{
		moveRook(board, x, y);
	}
	else if(rookOrBishop==2)
	{
		moveBishop(board,x,y);
	}
	else
	{
		printf("Wrong input\n");
	}
}

int moveKing(int board[8][8], int x, int y)
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
			board[newX][newY] =KING;
			return 1;
	}
}
