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
int moveWhitePawn(int board[8][8], int x, int y)
{
	int newX;
       	int newY;	
	printf("Choose new X:");
	scanf("%d",&newX);
	printf("Choose new Y:");
	scanf("%d",&newY);
	switch(board[newX][newY])
	{
		case QUEENB:
	       	case PAWNB:
	       	case HORSEB:
	       	case BISHOPB:
	       	case ROOKB:
	       	case EMPTY:
			if(newX==x+1||
			(newY==y||newY==y-1||newY==y+1))
			{
				board[x][y]= EMPTY;
				board[newX][newY] = PAWN;
				return 1;
			}
	}
	printf("Choose new coordinates.\n");
	return 0;

}
		

int moveWhiteRook(int board[8][8], int x, int y)
{
	int newX; 
	int newY; 
	printf("Choose new X:");
	scanf("%d", &newX);
	printf("Choose new Y:");
	scanf("%d", &newY);
	if(newX==x && newY ==y)
	{
		printf("Input other than where you are\n");
		return 0;
	}
	switch(board[newX][newY])
	{
		case QUEENB: 
		case PAWNB:
	       	case HORSEB:
	       	case BISHOPB:
	       	case ROOKB:
	       	case EMPTY:
			if(newY==y || newX==x)
			{
				board[x][y]= EMPTY;
				board[newX][newY]=ROOK;
				return 1;
			}
			else
			{
				printf("not a rook movement");
				return 0;
			}	
		default:
			printf("Not inside board or friendly unit \n");
			return 0;
	}
}

int moveWhiteBishop(int board[8][8], int x, int y)
{
	int newX;
	int newY;
	printf("Choose new X:");
	scanf("%d", &newX);
	printf("Choose new Y:");
	scanf("%d", &newY);
	if(newX==x && newY==y)
	{
		printf("Input other than current value\n");
		return 0;
	}
	switch(board[newX][newY])
	{
		case QUEENB:
	       	case PAWNB:
	       	case HORSEB:
	       	case BISHOPB:
	       	case ROOKB:
	       	case EMPTY:
			if(abs(newX-x)==abs(newY-y))
			{
				board[x][y]= EMPTY;
				board[newX][newY] = BISHOP;
				return 1;
			}
			else
			{
				printf("Not a bishop movement\n");
				return 0;
			}
		default:
			printf("Not inside board or friendly unit\n");
			return 0;
 	}
}

int moveWhiteHorse(int board[8][8], int x, int y)
{
	int newX;
	int newY;
	printf("Choose a new X location:");
	scanf("%d", &newX);
	printf("Choose a new Y location:");
	scanf("%d", &newY);
	if(newX==x && newY==y)
	{
		printf("Input other than 0\n");
		return 0;
	}
	switch(board[newX][newY])
	{
		case QUEENB:
	       	case PAWNB:
	       	case HORSEB:
	       	case BISHOPB:
	       	case ROOKB:
	       	case EMPTY:
			if((newX==x+1) && (newY==y+2 || newY==y-2)
			 ||(newX==x-1) && (newY==y+2 || newY==y-2)
			 ||(newX==x+2) && (newY==y+1 || newY==y-1)
			 ||(newX==x-2) && (newY==y+1 || newY==y-1))
			{
				board[x][y]=EMPTY;
				board[newX][newY]=HORSE;
				return 1;
			}
			printf("Not a valid horse movement\n");
			return 0;
		default: 
			printf("Outside board or friendly unit\n");
			return 0;
	}
}

int moveWhiteQueen(int board[8][8], int x, int y)
{
	int rookOrBishop =0;
	printf("Lateral or diagonal(1 for lateral, 2 for diagonal):");
	scanf("%d",rookOrBishop);
	if(rookOrBishop==1)
	{
		moveWhiteRook(board, x, y);
	}
	else if(rookOrBishop==2)
	{
		moveWhiteBishop(board,x,y);
	}
	else
	{
		printf("Wrong input\n");
	}
}

int moveWhiteKing(int board[8][8], int x, int y)
{
	int newX;
	int newY;
	printf("Choose new x:");
	scanf("%d", &newX);
	printf("Choose new y:");
	scanf("%d",newY);
	switch(board[newX][newY])
	{
		case QUEENB:
	       	case PAWNB:
	       	case HORSEB:
	       	case BISHOPB: 
		case ROOKB:
	       	case EMPTY:
			if((newX==x) && (newY==y+1 || newY==y-1)
			||(newX==x+1 || newX==x-1) && (newY==y || newY==y+1 || newY==y-1))
			{
				/* if(check(board,newX,newY)
				 {
					printf("You'll be checked\n");
					return 0;
				*/
				board[x][y]=EMPTY;
				board[newX][newY]=KING;
				return 1;
			}
			printf("Not a king movement\n");
			return 0;
		default:
			printf("Not a enemy or empty space\n");
			return 0;	
	}
}
