/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com, Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.


Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied. Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above, underscores are acceptable.
e. Email length must be less than or equal to 254 characters.
(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>

int seperate(char *email, char *name, char *id) {
	int i = 0;
	int j = 0;
	name[0] = id[0] = '\0';
	while (email[j] == ' ')j++;
	while (email[j] != ' ')name[i++] = email[j++];
	name[i] = '\0';
	i = 0;
	while (email[j] == ' ')j++;
	while (email[j] != ' '&&i <= 253)id[i++] = email[j++];
	if (i >= 253)return 0;
	id[i] = '\0';
}
int isValidChar(char c) {
	if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z') || c == '-' || c == '_' || c == '.')return 1;
	return 0;
}
int isValid(char *id) {
	int i = 0;
	if ((!((id[0] >= 'a'&&id[0] <= 'z') || (id[0] >= 'A'&&id[0] <= 'Z'))) || id[0] == '\0')return 0;
	while (id[i] != '@') {

		if (isValidChar(id[i]) == 0 || i >= 253)return 0;
		i++;
	}
	i++;
	while (id[i] != '.') {
		if (isValidChar(id[i]))
			i++;
		else return 0;
	}
	i++;
	if (id[i] == 'c'&&id[i + 1] == 'o'&&id[i + 2] == 'm')return 1;
	if (id[i] == 'c'&&id[i + 1] == 'o'&&id[i + 2] == '.'&&id[i + 3] == 'i'&&id[i + 4] == 'n')return 1;
	return 0;
}

int sufix(char *name, char *id) {
	for (int i = 0;name[i] != '\0';i++) {
		if (name[i] != id[i] && name[i] - 32 != id[i] && name[i] + 32 != id[i]) {//printf("%c %c \n",name[i]+32,id[i]);
			return 0;
		}
	}return 1;
}
int prefix(char *name, char *id) {
	int i = 0, j = 0;
	while (name[i] != '\0')i++;
	i--;
	while (id[j] != '@')j++;
	j--;

	for (;i >= 0;i--, j--) {
		if (j < 0)return 0;
		if (name[i] != id[j] && name[i] - 32 != id[j] && name[i] + 32 != id[j])
			return 0;
	}return 1;
}
int isValidWord(char *name, char *id) {
	int a = sufix(name, id);
	int b = prefix(name, id);
	//printf("%d %d\n", a, b);
	if (a || b)return 1;
	return 0;
}
int isValidEmail(char *email)
{
	if (email == NULL)return 0;
	char *name = (char *)malloc(sizeof(char) * 256);
	char *id = (char *)malloc(sizeof(char) * 256);
	int a = seperate(email, name, id);
	if (a == 0)return 0;
	int x = isValid(id);
	if (x == 0)return 0;
	int y = isValidWord(name, id);

	return x + y;
}