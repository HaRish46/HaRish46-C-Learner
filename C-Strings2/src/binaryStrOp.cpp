/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"
 
Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int max(int a, int b) {
	return a - ((a - b)&(a - b) >> 31);
}
char* performOR(char *str1, char *str2,int n) {
	char *ans = (char *)malloc(sizeof(char)*(n+1));
	str1 = _strrev(str1);
	str2 = _strrev(str2);
	int i = 0,j=0;
	while (str1[j]!='\0'&&str2[j]!='\0') {
		ans[i++] = '0' + ((str1[j] - '0') | (str2[j] - '0'));
		j++;
	}
	while (str1[j] != '\0') {
		ans[i++] =str1[j] ;
		j++;
	}
	while (str2[j] != '\0') {
		ans[i++] = str2[j];
		j++;
	}
	ans[i] = '\0';
	ans = _strrev(ans);
	return ans;
}
char* performAND(char *str1, char *str2, int n) {
	char *ans = (char *)malloc(sizeof(char)*(n+1));
	str1 = _strrev(str1);
	str2 = _strrev(str2);
	int i = 0, j = 0;
	while (str1[j] != '\0'&&str2[j] != '\0') {
		ans[i++] = '0' + ((str1[j] - '0') & (str2[j] - '0'));
		j++;
	}
	while (str1[j] != '\0') {
		ans[i++] = '0';
		j++;
	}
	while (str2[j] != '\0') {
		ans[i++] = '0';
		j++;
	}
	ans[i] = '\0';
	ans = _strrev(ans);
	return ans;
}
char* performXOR(char *str1, char *str2, int n) {
	char *ans = (char *)malloc(sizeof(char)*n);
	str1 = _strrev(str1);
	str2 = _strrev(str2);
	int i = 0, j = 0;
	while (str1[j] != '\0'&&str2[j] != '\0') {
		ans[i++] = '0' + ((str1[j] - '0') ^ (str2[j] - '0'));
		j++;
	}
	while (str1[j] != '\0') {
		ans[i++] = str1[j];
		j++;
	}
	while (str2[j] != '\0') {
		ans[i++] = str2[j];
		j++;
	}
	ans[i] = '\0';
	ans = _strrev(ans);
	return ans;
}
char* performNOR(char *str1, char *str2, int n) {
	char *ans = (char *)malloc(sizeof(char)*n);
	str1 = _strrev(str1);
	str2 = _strrev(str2);
	int i = 0, j = 0;
	while (str1[j] != '\0'&&str2[j] != '\0') {
		ans[i++] = '0' + (!((str1[j] - '0') | (str2[j] - '0')));
		j++;
	}
	while (str1[j] != '\0') {
		ans[i++] = '0'+(!(str1[j]-'0'));
		j++;
	}
	while (str2[j] != '\0') {
		ans[i++] = '0'+(!(str2[j]-'0'));
		j++;
	}
	ans[i] = '\0';
	ans = _strrev(ans);
	return ans;
}
char *performOperation(char *str1, char *str2, char *operation){
	if (str1 == NULL || str2 == NULL || operation == NULL)return NULL;
	int n = max(strlen(str1) , strlen(str2));
	if (strcmp(operation, "OR") == 0)return performOR(str1, str2, n);
	else if (strcmp(operation, "AND") == 0)return performAND(str1, str2,n);
	else if (strcmp(operation, "XOR") == 0)return performXOR(str1, str2,n);
	else if (strcmp(operation, "NOR") == 0)return performNOR(str1, str2,n);
	return NULL;
}








