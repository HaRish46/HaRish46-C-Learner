/*
Some where in MissionRnD world ,there is a large plot of empty Rectangular land ,divided into Blocks of
equal size . A Land of N Blocks at length and M Blocks at Breadth will have total of N x M Blocks .

Each Block has a pillar of Height H .[0 <= H <=100000] .A Pillar is said to be a Leader if there are no more
neighbouring pillars (East ,West ,Noth and South) whose height is greater than current one .
And excatly opposite ,A pillar is said to be a Looser if there are no more neighbouring pillars
whose height is less than the current pillar height

If a block has 0 specified ,It has No pillar and No person can be on that block.In the below example
1,2,4... are heights of pillars at that block.Do not consider 0 while calculating Leaders or Loosers .
Example :

1 2 0 1 0
0 0 0 9 0
0 0 0 8 0
0 1 4 6 5
0 0 2 3 4

Here a[0][1] ie 2 ,and a[1][3] ie 9 are leaders ,as all their neighbouring elements are less or equal than it .
Here a[0][0] ie 1 ,and a[0][3] ie 1 and a[3][1] ie 1 and a[4][2] ie 2 are Loose Pillars ,as all their
neighbouring pillars height are greater or equal than it .

Now there is a child who likes to jump from one pillar to another ,He starts at a looser Pillar and jumps to
a nearby pillar (4 Directions) ,if the nearby pillar height is "strictly greater" than curernt pillar height .
So he can jump from 1 to 3 ,or 3 to 7 but not 4 to 1 and 5 to 5 .[all these are heights]
He continues jumping until he reaches a LeaderPillar .

As he likes jumping ,He would like to know the Path which starts at a Looser Pillar and ends at a Leader Pillar
that involves maximum jumps ,Can you help the child solve his Task ?

In the above example :
1-2 Path , requires only 1 jump
1-4-6-8-9 requires 4 jumps
2-3-4-5-6-8-9 requires 6 jumps
1-9 requires only 1 jump.
So in the above example you need to return [2,3,4,5,6,8,9] and copy 6 in jumps_count

Input :
A 2D Array (passed as Single pointer,First element Address) ,N (number of Cols), M(number of rows),
jumps_count (Pointer to an Integer)
Output :
Return the Max Jumps path  ,and copy number of max jumps into jumps_count .

Constraints :
0<=N<=10000
0<=M<=10000
Note : If there is no such path ,Copy 0 in jumps_count and return NULL,(Same for Invalid Inputs too)
Examples :
-----
2 1 7
3 0 4   ->Max Path : [1,2,3,5,6] ,jumps_count =4 [Here both 4's are looser elements]
5 6 4
--------
5 8 9 10
4 3 1 0
3 0 0 3   ->Max Path is [1,2,3,4,5,8,9,10] , jumps_count =8
2 1 1 1
---------
0 0 0
0 4 0  ->Max Path is [4] ,jumps_count=0;
0 0 0
Note : There will be only One Maximum Jumps path .[If there are multiple ,Return any 1 path]
*/
#include <stdlib.h>
#include <stdio.h>
int isMin(int *blocks, int i, int j, int n, int m) {
	if (blocks[i*n + j] == 0)return 0;
	if (i - 1 >= 0 && blocks[i*n + j] > blocks[(i - 1)*n + j] && blocks[(i - 1)*n + j] != 0)return 0;
	if (j - 1 >= 0 && blocks[i*n + j] > blocks[(i)*n + j - 1] && blocks[(i)*n + j - 1] != 0)return 0;
	if (j + 1 < m && blocks[i*n + j] > blocks[(i)*n + j + 1] && blocks[(i)*n + j + 1] != 0)return 0;
	if (i + 1 < n && blocks[i*n + j] > blocks[(i + 1)*n + j] && blocks[(i + 1)*n + j] != 0)return 0;
	return 1;
}
int isMax(int *blocks, int i, int j, int n, int m) {
	if (blocks[i*n + j] == 0)return 0;
	if (i - 1 >= 0 && blocks[i*n + j] < blocks[(i - 1)*n + j] && blocks[(i - 1)*n + j] != 0)return 0;
	if (j - 1 >= 0 && blocks[i*n + j] < blocks[(i)*n + j - 1] && blocks[(i)*n + j - 1] != 0)return 0;
	if (j + 1 < m && blocks[i*n + j] < blocks[(i)*n + j + 1] && blocks[(i)*n + j + 1] != 0)return 0;
	if (i + 1 < n && blocks[i*n + j] < blocks[(i + 1)*n + j] && blocks[(i + 1)*n + j] != 0)return 0;
	return 1;
}
int max = 0;
int pillars_max_jumpsUtil(int *blocks, int i, int j, int n, int m, int *path, int pos) {
	if (isMax(blocks, i, j, n, m)) {
		if (pos + 1>max) {
			path[pos + 1] = -1;
			path[pos] = blocks[i*n + j];
			max = pos;
			return 1;
		}
		return 0;

	}
	int size1, size2, size3, size4;
	size1 = size2 = size3 = size4 = 0;
	int *p1 = (int *)malloc(sizeof(int) * 10000);
	int *p2 = (int *)malloc(sizeof(int) * 10000);
	int *p3 = (int *)malloc(sizeof(int) * 10000);
	int *p4 = (int *)malloc(sizeof(int) * 10000);
	if (i - 1 >= 0 && blocks[i*n + j] < blocks[(i - 1)*n + j] && blocks[(i - 1)*n + j] != 0) {
		size1 = pillars_max_jumpsUtil(blocks, i - 1, j, n, m, path, pos + 1);
	}
	if (j - 1 >= 0 && blocks[i*n + j] < blocks[(i)*n + j - 1] && blocks[(i)*n + j - 1] != 0) {
		size2 = pillars_max_jumpsUtil(blocks, i, j - 1, n, m, path, pos + 1);

	}
	if (j + 1 < m && blocks[i*n + j] < blocks[(i)*n + j + 1] && blocks[(i)*n + j + 1] != 0) {
		size3 = pillars_max_jumpsUtil(blocks, i, j + 1, n, m, path, pos + 1);

	}
	if (i + 1 < n && blocks[i*n + j] < blocks[(i + 1)*n + j] && blocks[(i + 1)*n + j] != 0) {
		size4 = pillars_max_jumpsUtil(blocks, i + 1, j, n, m, path, pos + 1);

	}
	if (size1 || size2 || size3 || size4) {
		path[pos] = blocks[i*n + j];
		return 1;
	}
	return 0;
}
int * pillars_max_jumps(int *blocks, int n, int m, int *jumps_count) {
	
	int *path = (int *)malloc(sizeof(int) * 1000000);
	max = 0;
	int size = 0;
	path[0] = -1;
	if (blocks == NULL || n <= 0 || m <= 0)return NULL;
	*jumps_count = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (isMax(blocks, i, j, n, m));
			if (isMin(blocks, i, j, n, m)) {
				int x = pillars_max_jumpsUtil(blocks, i, j, n, m, path, 0);
			}
		}
	}
	*jumps_count = max;
	if (*jumps_count == 0)return NULL;
	return path;
}