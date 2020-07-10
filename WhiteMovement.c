#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
	scanf("%d",&newY);
	printf("Choose new Y:");
	scanf("%d",&newX);
	newX--;
	newY--;
	switch(board[newX][newY])
	{
		case QUEENB:
	       	case PAWNB:
	       	case HORSEB:
	       	case BISHOPB:
	       	case ROOKB:
			if(newX==x-1 &&
			(newY==y-1||newY==y+1))
			{
				board[x][y]= EMPTY;
				board[newX][newY] = PAWN;
				return 1;
			}
	       	case EMPTY:
			if(newX==x-1 && newY==y)
			{
				board[x][y]=EMPTY;
				board[newX][newY]= PAWN;
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
	scanf("%d", &newY);
	printf("Choose new Y:");
	scanf("%d", &newX);
	newX--;
	newY--;
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
			if(newY==y)
			{
				int xChange = abs(newX-x);
				if(newX>x)
				{
					for(int i = 1; i<xChange; i++)
					{
						if(board[newX-i][newY] < EMPTY)  //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return 0;
						}
					}
					board[x][y] =EMPTY;
					board[newX][newY] = ROOK;
					return 1;
				}
				else if(x>newX)
				{
					for(int i = 1; i<xChange; i++)
					{
						if(board[newX+i][newY] <EMPTY) //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return 0;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY] = ROOK;
					return 1;
				}	
				else
				{
					return 0;
				}
			}
			else if(newX==x)
			{
				int yChange = abs(newY-y);
				if(newY>y)
				{
					for(int i = 1; i<yChange; i++)
					{
						if(board[newX][newY-i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return 0;
						}
					}
					board[x][y] =EMPTY;
					board[newX][newY]=ROOK;
					return 1;
				}	
				else if(y>newY)
				{
					for(int i = 1 ; i<yChange; i++)
					{
						if(board[newX][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return 0;
						}
					}
					board[x][y] =EMPTY;
					board[newX][newY]=ROOK;
					return 1;
				}
				else 
				{
					printf("error #4");
				}
			}
			else
			{
				printf("not a rook movement");
				return 0;
			}	
			break;
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
	scanf("%d", &newY);
	printf("Choose new Y:");
	scanf("%d", &newX);
	newX--;
	newY--;
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
				int change = abs(newX-x);
				if(newX>x && newY>y)
				{
					for(int i = 1; i<change; i++)
					{
   						if(board[newX-i][newY-i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return 0;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= BISHOP;
					return 1;
				}
				else if(newX>x && y>newY)
				{
					for(int i = 1; i<change; i++)
					{
						if(board[newX-i][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return 0;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= BISHOP;
					return 1;
				}
				else if(x>newX && newY>y)
				{
					for(int i = 1; i<change; i++)
					{
						if(board[newX+i][newY-i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return 0;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= BISHOP;
					return 1;
				}
				else if(x>newX && y>newY)
				{
					for(int i = 1; i<change; i++)
					{
						if(board[newX+i][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return 0;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= BISHOP;
					return 1;
				}
				else
				{	
					printf("error #3");
				}
			}
			else
			{
				printf("Not a bishop movement\n");
				return 0;
			}
			break;
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
	scanf("%d", &newY);
	printf("Choose a new Y location:");
	scanf("%d", &newX);
	newX--;
	newY--;
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

int moveWhiteQueenRook(int board[8][8], int x, int y, int newX, int newY)
{
	switch(board[newX][newY])
	{
		case QUEENB: 
		case PAWNB:
	       	case HORSEB:
	       	case BISHOPB:
	       	case ROOKB:
	       	case EMPTY:
			if(newY==y)
			{
				int xChange = abs(newX-x);
				if(newX>x)
				{
					for(int i = 1; i<xChange; i++)
					{
						if(board[newX-i][newY] < EMPTY)  //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return 0;
						}
					}
					board[x][y] =EMPTY;
					board[newX][newY] = QUEEN;
					return 1;
				}
				else if(x>newX)
				{
					for(int i = 1; i<xChange; i++)
					{
						if(board[newX+i][newY] <EMPTY) //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return 0;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY] = QUEEN;
					return 1;
				}	
				else
				{
					return 0;
				}
			}
			else if(newX==x)
			{
				int yChange = abs(newY-y);
				if(newY>y)
				{
					for(int i = 1; i<yChange; i++)
					{
						if(board[newX][newY-i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return 0;
						}
					}
					board[x][y] =EMPTY;
					board[newX][newY]=QUEEN;
					return 1;
				}	
				else if(y>newY)
				{
					for(int i = 1 ; i<yChange; i++)
					{
						if(board[newX][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return 0;
						}
					}
					board[x][y] =EMPTY;
					board[newX][newY]=QUEEN;
					return 1;
				}
				else 
				{
					printf("error #4");
				}
			}
			else
			{
				printf("not a valid queen movement\n");
				return 0;
			}	
			break;
		default:
			printf("Not inside board or friendly unit \n");
			return 0;
	}
}

int moveWhiteQueenBishop(int board[8][8], int x, int y, int newX, int newY)
{
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
				int change = abs(newX-x);
				if(newX>x && newY>y)
				{
					for(int i = 1; i<change; i++)
					{
   						if(board[newX-i][newY-i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return 0;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= QUEEN;
					return 1;
				}
				else if(newX>x && y>newY)
				{
					for(int i = 1; i<change; i++)
					{
						if(board[newX-i][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return 0;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= QUEEN;
					return 1;
				}
				else if(x>newX && newY>y)
				{
					for(int i = 1; i<change; i++)
					{
						if(board[newX+i][newY-i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return 0;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= QUEEN;
					return 1;
				}
				else if(x>newX && y>newY)
				{
					for(int i = 1; i<change; i++)
					{
						if(board[newX+i][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return 0;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= QUEEN;
					return 1;
				}
				else
				{	
					printf("error #3");
				}
			}
			else
			{
				printf("Not a valid queen movement\n");
				return 0;
			}
			break;
		default:
			printf("Not inside board or friendly unit\n");
			return 0;
 	}
}
int moveWhiteQueen(int board[8][8], int x, int y)
{
	int newX;
	int newY;
	printf("new X:");
	scanf("%d",&newY);
	printf("new Y:");
	scanf("%d", &newX);
	newX--;
	newY--;
	if(newX==x && newY==y)
	{
		printf("You're already here\n");
		return 0;
	}
	if(moveWhiteQueenBishop(board,x,y,newX,newY))
	{
		return 1;
	}
	else if(moveWhiteQueenRook(board,x,y,newX,newY))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int moveWhiteKing(int board[8][8], int x, int y)
{
	int newX;
	int newY;
	printf("Choose new x:");
	scanf("%d", &newY);
	printf("Choose new y:");
	scanf("%d",&newX);
	newX--;
	newY--;
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
				/* if(check(board,newX,newY)
				 {
					printf("You'll be checked\n");
					return 0;
				*/
