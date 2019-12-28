/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compareDates(char *d1, char *d2) {
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
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if(Arr==NULL||date==NULL)
	return -1;
	int ans = 0;
	for (int i = 0;i < len;i++) {
		if (compareDates(Arr[i].date, date))
			ans++;
	}
	return ans;
}
