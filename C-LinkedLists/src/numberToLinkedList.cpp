/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
int reverse(int n) {
	if (n < 0)n = -n;
	int rev = 0;
	while (n) {
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev;
}
struct node *newnode() {
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->num = 0;
	head->next = NULL;
	return head;
}
struct node * numberToLinkedList(int N) {
	struct node *head,*p;
	N = reverse(N);
	head = newnode();
	p = head;
	while (N) {
		p->num = N % 10;
		N /= 10;
		if (N)p->next = newnode();
		p = p->next;
	}
	return head;
}