/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	if (str == NULL)return NULL;
	int len = 0;
	while (str[len] != '\0')len++;
	len--;
	while (len>=0&&str[len] == ' ')len--;
	char *a= (char *)malloc(sizeof(char)*(1));
	a[0] = '\0';
	if (len < 0)return a;
	int i = len;
	while (i>=0&&str[i] != ' ')i--;
	i++;
	if (i < 0)i = 0;
	char *ans = (char *)malloc(sizeof(char)*(len - i));
	int j = 0;
	for (;i <= len;i++)
		ans[j++] = str[i];
	ans[j] = '\0';
	return ans;
}
