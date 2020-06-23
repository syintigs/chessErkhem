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
bool movementAccessibility(int board[8][8], int x, y)
{
	return (check(board, x, y)&&(EMPTY|| 
}
bool checkMate(int board[8][8], int x, int y)
{

	
}


		




