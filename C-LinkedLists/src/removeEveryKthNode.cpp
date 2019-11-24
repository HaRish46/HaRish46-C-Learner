/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (head == NULL||K<=0)return NULL;
	if (K == 1)return NULL;
	struct node *p = head;
	int i = 1;
	while (p) {
		if ((i+1)%K == 0) {
			if(p->next)
			p->next=p->next->next;
		}
		else
			p = p->next;
		i++;
	}
	return head;
}