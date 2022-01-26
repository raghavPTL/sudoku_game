#include <stdio.h>
#include <math.h>
#define N 4
/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$ */
int is_possible(int r,int c, int n, int sudoku[N][N])
{
//row
for(int x=0; x<N; x++)
{
if(sudoku[r][x]==n)
{
return 0;
} }
//collum?
for (int x=0; x<N; x++)
{
if(sudoku[x][c] == n)
{
return 0;
} }
//box
int row_start = r - r%(int)sqrt(N); int col_start = c - c%(int)sqrt(N); for (int a=0; a<(int)sqrt(N); a++) {
for(int b=0; b<(int)sqrt(N); b++)
{
if(sudoku[a+row_start][b+col_start]==n)
{
return 0;
} }
}
return 1; }
/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ $$$$$$$$$$$$$$$$$$$$$$$$$ */
int solve(int sudoku[N][N], int r, int c)
{
if (r == N-1 && c == N) return 1;
if(c==N)
{
r++;
c=0; }
if (sudoku[r][c] != 0)
return solve(sudoku,r,c+1);
for (int n=1; n<=N; n++)
{
if(is_possible(r,c,n,sudoku)==1)
{
sudoku[r][c] = n;
 if(solve(sudoku,r,c+1)==1) return 1;
}
sudoku[r][c] = 0; }
return 0; }
/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$ */
void print(int sudoku[N][N])
{
for(int i=0; i<N; i++)
{
for(int j=0; j<N; j++)
{
printf("%d ",sudoku[i][j]);
}
printf("\n"); }
}
/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ */ void main()
{
//for 4x4
int sudoku[4][4]= {{0, 2, 3, 0}, {0, 0, 0, 1}, {0, 1, 0, 0}, {2, 4, 1, 0}};
//for 9x9
/*
int sudoku[9][9] = {{5,3,0,0,7,0,0,0,0},
*/
{6,0,0,1,9,5,0,0,0}, {0,9,8,0,0,0,0,6,0}, {8,0,0,0,6,0,0,0,3}, {4,0,0,8,0,3,0,0,1}, {7,0,0,0,2,0,0,0,6}, {0,6,0,0,0,0,2,8,0}, {0,0,0,4,1,9,0,0,5}, {0,0,0,0,8,0,0,7,9}};
printf("the question of sudoku is:\n"); print(sudoku);
printf("the answer of the sudoku is: \n"); if (solve(sudoku,0,0)==1)
{
print(sudoku);
} else
{
printf("not exist");
} printf("\n");
//file
FILE *fp;
char name[80];
fp = fopen("our_name.txt","r");

char x = fgetc(fp); while (x != '\n')
{
printf("%c",x);
x = fgetc(fp); }
}