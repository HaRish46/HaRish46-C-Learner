/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int ap1, ap2, gp1;
void addApStart(int n, int *ans) {
	if (ans[1] == 0) {
		ap1 = 1;
		ans[1] = n;
	}
	else {
		ap2 = 1;
		ans[3] = n;
	}
}
int * find_sequences(int *arr, int len) {
	if (len<0 || arr == NULL)return NULL;
	int *ans = (int *)calloc(6, sizeof(int));
	int apLen, gpLen, d;
	float r;
	apLen = gpLen = d = r = ap1 = ap2 = gp1= 0;
	for (int i = 1;i < len;i++) {
		if (d == (arr[i] - arr[i - 1]))
			apLen++;
		else {
			d = arr[i] - arr[i - 1];
			if (apLen >= 2)
				addApStart(i - 1, ans);
			if (ap1 == 0)
				ans[0] = i - 1;
			else if (ap2 == 0)
				ans[2] = i - 1;
			apLen = 1;
		}
		if (ans[3] == 0 && apLen >= 2)
			ans[3] = len - 1;
		if (arr[i - 1] != 0 && r == (float)arr[i] / arr[i - 1])
			gpLen++;
		else if (arr[i - 1] == 0)
			gpLen = 0;
		else if(gp1==0){
			if(arr[i - 1] != 0)
			r = (float)arr[i] / arr[i - 1];
			if (gpLen >= 2) {
				ans[5] = i - 1;
				gp1 = 1;
			}
			else 
				ans[4] = i - 1;
			gpLen = 1;
		}
		if (ans[5] == 0 && gpLen >= 2) 
			ans[5] = len - 1;
	}
	return ans;
}