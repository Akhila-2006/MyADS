#include<stdio.h>
#define Max 20
int board[Max][Max];
int N;
int totalsol=0;
int i,j,row;
void Printsol()
{
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(board[i][j]==1)
			{
				printf("Q ");
			}
			else
			printf(". ");
		}
		printf("\n");
	}
	printf("\n");
}
void NQueens(int row)
{
	int col;
	if(row>N)
	{
		totalsol++;
		Printsol();
		return;
	}
	for(col=1;col<=N;col++)
	{
		if(isSafePlace(row,col))
		{
			board[row][col]=1;
			NQueens(row+1);
			board[row][col]=0;
		}
	}
}
int isSafePlace(int row,int col)
{
	int i,j;
	for(i=1;i<=row;i++)
	{
		if(board[i][col]==1)
		return 0;
	}
	for(i=row-1,j=col-1;i>0&&j>0;i--,j--)
	{
		if(board[i][j]==1)
		return 0;
	}
	for(i=row-1,j=col+1;i>0&&j<=N;i--,j++)
	{
		if(board[i][j]==1)
		return 0;
	}
	return 1;
}

int main()
{
	printf("Enter the size of board: ");
	scanf("%d",&N);
	//printf("solutions for the board : \n",N);
	NQueens(1);
	printf("Total solutions: %d\n",totalsol);
	return 0;
	
}
