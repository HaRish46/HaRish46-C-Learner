/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>
struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	if (head == NULL)return NULL;
	struct node *p1, *p2;
	p1 = p2 = head;
	int t,len = 0;
	int sublen;
	while (p1) { p1 = p1->next;len++; }
	while (len--) {
		p2 = head;
		sublen = len;
		while (sublen--) {
			if (p2->num > p2->next->num) {
				t = p2->num;
				p2->num= p2->next->num;
				p2->next->num = t;
			}p2 = p2->next;
		}
	}
	return head;
}