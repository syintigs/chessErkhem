#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "CheckAndMate.h"
#include "Extern.h"
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
bool moveWhitePawn(int board[8][8], int x, int y);
bool moveWhiteRook(int board[8][8], int x, int y);
bool moveWhiteBishop(int board[8][8], int x, int y);
bool moveWhiteHorse(int board[8][8], int x, int y);
bool moveWhiteQueen(int board[8][8], int x, int y);
bool moveWhiteKing(int board[8][8], int x, int y);
bool moveWhiteQueenRook(int board[8][8], int x, int y, int newX, int newY);
bool moveWhiteQueenBishop(int board[8][8], int x, int y, int newX, int newY);


bool moveWhitePawn(int board[8][8], int x, int y)
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
				return true;
			}
	       	case EMPTY:
			if(newX==x-1 && newY==y)
			{
				board[x][y]=EMPTY;
				board[newX][newY]= PAWN;
				return true;
			}
	}
	printf("Choose new coordinates.\n");
	return false;

}
		
bool moveWhiteRook(int board[8][8], int x, int y)
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
		return false;
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
							return false;
						}
					}
					board[x][y] =EMPTY;
					board[newX][newY] = ROOK;
					return true;
				}
				else if(x>newX)
				{
					for(int i = 1; i<xChange; i++)
					{
						if(board[newX+i][newY] <EMPTY) //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return false;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY] = ROOK;
					return true;
				}	
				else
				{
					return false;
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
							return false;
						}
					}
					board[x][y] =EMPTY;
					board[newX][newY]=ROOK;
					return true;
				}	
				else if(y>newY)
				{
					for(int i = 1 ; i<yChange; i++)
					{
						if(board[newX][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return false;
						}
					}
					board[x][y] =EMPTY;
					board[newX][newY]=ROOK;
					return true;
				}
				else 
				{
					printf("error #4");
				}
			}
			else
			{
				printf("not a rook movement");
				return false;
			}	
			break;
		default:
			printf("Not inside board or friendly unit \n");
			return false;
	}
}

bool moveWhiteBishop(int board[8][8], int x, int y)
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
		return false;
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
							return false;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= BISHOP;
					return true;
				}
				else if(newX>x && y>newY)
				{
					for(int i = 1; i<change; i++)
					{
						if(board[newX-i][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return false;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= BISHOP;
					return true;
				}
				else if(x>newX && newY>y)
				{
					for(int i = 1; i<change; i++)
					{
						if(board[newX+i][newY-i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return false;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= BISHOP;
					return true;
				}
				else if(x>newX && y>newY)
				{
					for(int i = 1; i<change; i++)
					{
						if(board[newX+i][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return false;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= BISHOP;
					return true;
				}
				else
				{	
					printf("error #3");
				}
			}
			else
			{
				printf("Not a bishop movement\n");
				return false;
			}
			break;
		default:
			printf("Not inside board or friendly unit\n");
			return false;
 	}
}

bool moveWhiteHorse(int board[8][8], int x, int y)
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
		return false;
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
				return true;
			}
			printf("Not a valid horse movement\n");
			return false;
		default: 
			printf("Outside board or friendly unit\n");
			return false;
	}
}

bool moveWhiteQueenRook(int board[8][8], int x, int y, int newX, int newY)
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
							return false;
						}
					}
					board[x][y] =EMPTY;
					board[newX][newY] = QUEEN;
					return true;
				}
				else if(x>newX)
				{
					for(int i = 1; i<xChange; i++)
					{
						if(board[newX+i][newY] <EMPTY) //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return false;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY] = QUEEN;
					return true;
				}	
				else
				{
					return false;
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
							return false;
						}
					}
					board[x][y] =EMPTY;
					board[newX][newY]=QUEEN;
					return true;
				}	
				else if(y>newY)
				{
					for(int i = 1 ; i<yChange; i++)
					{
						if(board[newX][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return false;
						}
					}
					board[x][y] =EMPTY;
					board[newX][newY]=QUEEN;
					return true;
				}
				else 
				{
					printf("error #4");
				}
			}
			else
			{
				printf("not a valid queen movement\n");
				return false;
			}	
			break;
		default:
			printf("Not inside board or friendly unit \n");
			return false;
	}
}

bool moveWhiteQueenBishop(int board[8][8], int x, int y, int newX, int newY)
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
							return false;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= QUEEN;
					return true;
				}
				else if(newX>x && y>newY)
				{
					for(int i = 1; i<change; i++)
					{
						if(board[newX-i][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return false;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= QUEEN;
					return true;
				}
				else if(x>newX && newY>y)
				{
					for(int i = 1; i<change; i++)
					{
						if(board[newX+i][newY-i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return false;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= QUEEN;
					return true;
				}
				else if(x>newX && y>newY)
				{
					for(int i = 1; i<change; i++)
					{
						if(board[newX+i][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in between\n");
							return false;
						}
					}
					board[x][y] = EMPTY;
					board[newX][newY]= QUEEN;
					return true;
				}
				else
				{	
					printf("error #3");
				}
			}
			else
			{
				printf("Not a valid queen movement\n");
				return false;
			}
			break;
		default:
			printf("Not inside board or friendly unit\n");
			return false;
 	}
}
bool moveWhiteQueen(int board[8][8], int x, int y)
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
		return false;
	}
	if(moveWhiteQueenBishop(board,x,y,newX,newY))
	{
		return true;
	}
	else if(moveWhiteQueenRook(board,x,y,newX,newY))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool moveWhiteKing(int board[8][8], int x, int y)
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
				return true;
			}
			printf("Not a king movement\n");
			return false;
		default:
			printf("Not a enemy or empty space\n");
			return false;	
	}
}
				/* if(check(board,newX,newY)
				 {
					printf("You'll be checked\n");
					return false;
				*/
