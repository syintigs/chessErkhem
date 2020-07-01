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
 *26 Black Pawn
 *69 Black Rook
 *94 Black Bishop
 *116 Black Horse
 *151 Black Queen
 *170 Black King
 */
int moveBlackPawn(int board[8][8], int x, int y)
{
	int newX;
       	int newY;
	printf("Choose new X:");	
	scanf("%d",&newY);
	printf("Choose new Y:");
	scanf("%d", &newX);
	newX--;
	newY--;
	switch(board[newX][newY])
	{
		case QUEEN:
	       	case PAWN:
	       	case HORSE:
	       	case BISHOP:
	       	case ROOK:
			if(newX==x+1&&
			(newY==y-1||newY==y+1))
			{
				board[x][y]= EMPTY;
				board[newX][newY] = PAWNB;
				return 1;
			}
	       	case EMPTY:
			if(newX==x+1 && newY==y)
			{
				board[x][y]=EMPTY;
				board[newX][newY]=PAWNB;
				return 1;
			}
	}	
	printf("Choose new coordinate\n");
	return 0;
}	

int moveBlackRook(int board[8][8], int x, int y)
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
		printf("Input other than where you are\n");
		return 0;
	}
	switch(board[newX][newY])
	{
		case QUEEN:
	       	case PAWN:
	       	case HORSE:
	       	case BISHOP:
	       	case ROOK:
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
					board[newX][newY] = ROOKB;
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
					board[newX][newY] = ROOKB;
					return 1;
				}	
				else
				{
					return 0;
				}
			}
			if(newX==x)
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
						board[x][y]=EMPTY;
						board[newX][newY]=ROOKB;
						return 1;
					}
				}
				if(y>newY)
				{
					for(int i = 1 ; i<yChange; i++)
					{
						if(board[newX][newY+i]<EMPTY) //Anything other than EMPTY
						{
							printf("There are things in the way\n");
							return 0;
						}
						board[x][y] =EMPTY;
						board[newX][newY]=ROOKB;
						return 1;
					}
				}
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

int moveBlackBishop(int board[8][8], int x, int y)
{
	int newX;
	int newY;
	printf("Choose a new X:");
	scanf("%d", &newY);
	printf("Choose a new Y:");
	scanf("%d", &newX);
	newX--;
	newY--;
	if(x==newX && y==newY)
	{
		printf("Input other than 0\n");
		return 0;
	}
	switch(board[newX][newY])
	{
		case QUEEN: 
		case PAWN:
	       	case HORSE:
		case BISHOP: 
		case ROOK:
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
						board[x][y] = EMPTY;
						board[newX][newY] = BISHOPB;	
						return 1;
					}
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
						board[x][y] = EMPTY;
						board[newX][newY] = BISHOPB;
						return 1;
					}
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
						board[x][y] = EMPTY;
						board[newX][newY] = BISHOPB;
						return 1;
					}
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
						board[x][y] = EMPTY;
						board[newX][newY]= BISHOPB;
						return 1;
					}
				}
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

int moveBlackHorse(int board[8][8], int x, int y)
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
		case QUEEN:
	       	case PAWN:
	       	case HORSE:
	       	case BISHOP: 
		case ROOK:
	       	case EMPTY:
			if((newX==x+1) && (newY==y+2 || newY==y-2)
			 ||(newX==x-1) && (newY==y+2 || newY==y-2)
			 ||(newX==x+2) && (newY==y+1 || newY==y-1)
			 ||(newX==x-2) && (newY==y+1 || newY==y-1))
			{
				board[x][y]=EMPTY;
				board[newX][newY]=HORSEB;
				return 1;
			}
			printf("Not a valid horse movement\n");
			return 0;
		default: 
			printf("Outside board or friendly unit\n");
			return 0;
	}
}

int moveBlackQueen(int board[8][8], int x, int y)
{
	int newX;
	int newY;
	printf("new X:");
	scanf("%d",&newY);
	printf("new Y:");
	scanf("%d",&newX);
	if(moveBlackRook(board,x,y))
	{
		return 1;
	}
	else if(moveBlackBishop(board,x,y))
	{
		return 1;
	}
	else
	{
		printf("Wrong input\n");
		return 0;
	}
}

int moveBlackKing(int board[8][8], int x, int y)
{
	int newX;
	int newY;
	printf("Choose new x:");
	scanf("%d",&newY);
	printf("Choose new y:");
	scanf("%d",&newX);
	newX--;
	newY--;
	switch(board[newX][newY])
	{
		case QUEEN:
	       	case PAWN:
	       	case HORSE:
	       	case BISHOP: 
		case ROOK:
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
				board[newX][newY]=KINGB;
				return 1;
			}
			printf("Not a king movement\n");
			return 0;
		default:
			printf("Not a enemy or empty space\n");
			return 0;	
	}
}
