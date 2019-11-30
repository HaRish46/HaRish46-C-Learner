/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void spiralUtil(int rows, int columns, int **input_array, int *ans, int x, int p) {
	if (rows <x || columns <x)return;
	printf(" er ");
	for (int i = x;i < columns;i++) {
		ans[p++] = input_array[x][i];
	}
	for (int i = x + 1;i < rows;i++) {
		ans[p++] = input_array[i][columns - 1];
	}
	for (int i = columns - 2;i >= x;i--) {
		ans[p++] = input_array[rows - 1][i];
	}
	for (int i = rows - 2;i >x;i--) {
		ans[p++] = input_array[i][x];
	}
	spiralUtil(rows - 1, columns - 1, input_array, ans, x + 1, p);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || input_array == NULL)return NULL;
	int *ans = (int *)malloc(sizeof(int) * 1000);
	spiralUtil(rows, columns, input_array, ans, 0, 0);
	return ans;
}
