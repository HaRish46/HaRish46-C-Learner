/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include<stdio.h>
#include <stdlib.h>


int findSingleOccurenceNumber(int *A, int len) {
	if(A==NULL||len<0)return -1;
	int arr[32] = { 0 };
	long a = 1;
	for (int j = 0;j < 16;j++) {
		for (int i = 0;i < len;i++) {
			if (A[i] & a)arr[j]++;
		}a *= 2;
	}
	for (int i = 0;i < 16;i++)arr[i] %= 3;
	int ans = 0;
	a = 1;
	for (int i = 0;i < 16;i++) {
		if (arr[i] == 1)ans += a;
		a *= 2;
	}
	return ans;
}