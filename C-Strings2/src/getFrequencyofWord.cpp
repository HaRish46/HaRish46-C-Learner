/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int count_word_in_str_way_1(char *str, char *word) {
	int count = 0;
	int j = 0;
	for (int i = 0;str[i] != '\0';i++) {
		if (str[i] == word[j]) {
			j++;
		}
		else {
			if (word[j] == '\0') {
				count++;
				if (j>1)
					i -= (j);
				else i--;
			}
			j = 0;
		}
	}
	if (word[j] == '\0')
		count++;
	return count;
}

int count_word_int_str_way_2_recursion(char *str, char *word) {
	int i;
	if (strlen(word)>strlen(str))return 0;
	for (i = 0;word[i] != '\0';i++)
		if (word[i] != str[i])
			break;
	if (word[i] == '\0')
		return 1 + count_word_int_str_way_2_recursion((str + 1), word);
	return 0 + count_word_int_str_way_2_recursion((str +1), word);

}

