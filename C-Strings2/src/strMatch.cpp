/*
ProblemCode : STRMATCH
Marks : 10
Difficulty :Easy.

A String(which only has small case a-z letters) is said to be corrupted if some of the charecters are removed and replaced by the number of characters removed .
Like : apple can be converted into a3e (ppl removed), or a4 (pple removed),ap2e (pl removed) .

helloworld can be modified as hello5 , h9 , 9d , etc , There is no limit on the number of characters that can be removed , or number of different times they can be
removed .

Some more examples are ,abcdefghijkl can be modified as a2d2g4l , a10l .
If 2 or more numbers occured consecutively , you should consider them as a whole , like a23re , is not a "2Chars removed" "3Chars Removed" re ,
it is a "23 Chars removed" re .

Your Task is , Given two corrupted Strings , you need to find whether a common word can be formed from those both corrupted strings
, If Yes ,return 1 , If no word can formed return 0 , -1 For invalid inputs .

Ex Input : s1= "a3e" and s2="4e" , Example Output : 1 .

This is because , apple word can be formed from both .

Ex Input 2 : s1= "k2e2f" and s2="k1fr3" , Returns 0 . No common word can be formed from those both Strings .
Ex Input 3: "5e3" and "abcdeej2" returns 1 , where as if s1 is 5e3i and s2 is abcdeekoll returns 0

Constraints :
A String will only have letters from "a-z and 0-9" ;
0<=Len Of Str1,Str2 <=10000
Numbers occuring in the String can be anything from 1 till 999 .

You can implement the helper functions ,if you want ,Although its optional .Dont worry about space for this question .

Note : Only 25% of Cases ,will have numbers >9 in the Strings .
*/
#include <stddef.h>
#include <stdlib.h>
#include<stdio.h>
int getValue(char *str, int *x) {
	int i = 0;
	int ans = 0;
	for (i = 0;str[i] <= '9'&&str[i] >= '0';i++) {
		ans *= 10;
		ans += str[i] - '0';
	}
	*x = i;
	return ans;
}
int isSTRMatchedUtil(char *str1, char *str2, int n1, int n2) {

	if (str1 == NULL || str2 == NULL)return 1;
	if (*str1 == '\0'&&*str2 == '\0') {
		printf(" 0 %s @%d %s @%d\n", str1, n1, str2, n2);
		if (n1 == n2)return 1;
		else return 0;
	}
	else if ((*str1 == '\0'&&n1 == 0) || (*str2 == '\0'&&n2 == 0))return 0;
	int x = 0;
	if (*str1>'0'&&*str1 <= '9') {
		n1 = getValue(str1, &x);
		str1 += x;
	}
	if (*str2>'0'&&*str2 <= '9') {
		n2 = getValue(str2, &x);
		str2 += x;
	}
	if (n1 != 0 && n2 != 0) {
		if (n1 != 0)n1--;
		if (n2 != 0)n2--;
		return isSTRMatchedUtil(str1, str2, n1, n2);
	}
	else if (n1 != 0) {
		n1--;
		return isSTRMatchedUtil(str1, str2 + 1, n1, n2);
	}
	else if (n2 != 0) {
		n2--;
		return isSTRMatchedUtil(str1 + 1, str2, n1, n2);
	}
	if (*str1 >= 'a'&&*str1 <= 'z'&&*str2 >= 'a'&&*str2 <= 'z') {
		if (*str1 != *str2)return 0;
		else return isSTRMatchedUtil(str1 + 1, str2 + 1, 0, 0);
	}
	return 1;
}
int isSTRMatched(char *str1, char *str2) {
	return isSTRMatchedUtil(str1, str2, 0, 0);
}
