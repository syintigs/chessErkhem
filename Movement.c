#include <stdio.h>
#include <stdbool.h>
#define ENEMYOREMPTY (EMPTY||PAWNB||ROOKB||BISHOPB||HORSEB||QUEENB)

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
	else if(board[x+xChange][y+yChange]==ENEMYOREMPTY)
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
	else if(board[x+movement][y+movement]==ENEMYOREMPTY)
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
	else if(board[newX][newY]==ENEMYOREMPTY)
	{
		if(board[newX][newY]==(board[x+1][y+2]||board[x+1][y-2]||board[x-1][y+2]||board[x-1][y-2]||board[x+2][y+1]||board[x+2][y-1]||board[x-2][y+1]||board[x-2][y-1]))
		{
			board[x][y]=EMPTY;
			board[newX][newY]=HORSE;
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
	if(board[newX][newY]==board[x][y+1]||board[newX][newY]==board[x][y-1]||board[newX][newY]==board[x-1][y+1]||board[newX][newY]==board[x-1][y-1]||board[newX][newY]==board[x-1][y]||board[newX][newY]==board[x+1][y+1]||board[newX][newY]==board[x+1][y-1]||board[newX][newY]==board[x+1][y])
	{
		if(check(board,x,y)
		{
			prinf("You'll be checked\n");
			return 0;
		}
		board[x][y]==EMPTY;
		board
	}
}
//CHANGE THIS FUNCTION UP. MOVE FUNCTIONS EXECUTE COMMANDS OTHER THAN JUST RETURNING
int check(int board[8][8], int x, int y)
{	
	if(moveQueenB(board,x,y)==1)
	{
		return 1;
	}
	else if(moveRookB(board,x,y)==1)
	{
		return 1;
	}
	else if(moveBishopB(board,x,y)==1)
	{
		return 1;
	}
	else if(moveHorseB(board,x,y)==1)
	{
		return 1;
	}
	else if(movePawnB(board,x,y)==1)
	{
		return 1;
	}
}
int movementAccessibility(int board[8][8], int x, y)
{
	return (check(board, x, y)&&(EMPTY|| 
}
int checkMate(int board[8][8], int x, int y)
{
	
}


		




