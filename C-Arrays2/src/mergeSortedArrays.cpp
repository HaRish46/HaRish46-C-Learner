/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compareDate(char *d1, char *d2) {
	char c1[2], c2[2];
	if (atoi(d1 + 6) > atoi(d2 + 6))
		return 1;
	else if (atoi(d1 + 6) == atoi(d2 + 6)) {

		c1[0] = d1[3];
		c1[1] = d1[4];
		c2[0] = d2[3];
		c2[1] = d2[4];
		if (atoi(c1) > atoi(c2))return 1;
		else if (atoi(c1) == atoi(c2)) {
			c1[0] = d1[0];
			c1[1] = d1[1];
			c2[0] = d2[0];
			c2[1] = d2[1];
			if (atoi(c1) > atoi(c2))return 1;
		}
	}
	return 0;
}
void copy(struct transaction *a, struct transaction *b) {
	a[0].amount = b[0].amount;
	strcpy_s(a[0].date, b[0].date);
	strcpy_s(a[0].description, b[0].description);
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if(A==NULL||B==NULL||ALen<0||BLen<0)return NULL;
	struct transaction *ans = (struct transaction *)malloc(sizeof(struct transaction)*(ALen+BLen));
	int i, j, k;
	i = j = k = 0;
	while (i < ALen&&j < BLen) {
		if (!compareDate(B[j].date, A[i].date)) {
			copy(ans+k++, B+j++);
		}
		else {
			copy(ans+k++, A+i++);
		}
	}
	while (i < ALen) {
		copy(ans + k++, A + i++);
	}
	while (j < BLen) {
		copy(ans + k++, B + j++);
	}
	return ans;
}