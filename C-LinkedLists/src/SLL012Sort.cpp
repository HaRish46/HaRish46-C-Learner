/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){

}

/*
This is the actual function. You are supposed to change only the links.
*/
void setNodes(struct node **head,struct node* head0, struct node *head1, struct node *head2, struct node *head0end, struct node *head1end, struct node *head2end) {
	if (head0 == NULL) {
		if (head1 == NULL)
			if (head2 == NULL)
				*head = NULL;
			else
				*head = head2;
		else {
			*head = head1;
			if (head2 != NULL)
				head1end->next = head2;
		}
	}
	else {
		*head = head0;
		if (head1 != NULL) {
			head0end->next = head1;
			if (head2 != NULL)
				head1end->next = head2;
		}
		else {
			if (head2 != NULL)
				head1end->next = head2;
		}
	}
}
void sll_012_sort(struct node **head){
	//if (*head == NULL)return NULL;
	struct node* head0, *head1, *head2, *head0end, *head1end, *head2end,*p;
	head0 = head1 = head2 = head0end = head2end = head1end = NULL;
	p = *head;
	while (p) {
		if (p->data == 0) {
			if (head0 == NULL) {
				head0 =head0end= p;
				p = p->next;
				head0->next =head0end->next= NULL;
			}
			else {
				head0end->next = p;
				head0end = head0end->next;
				p = p->next;
				head0end->next = NULL;
			}
		}
		else if (p->data == 1) {
			if (head1 == NULL) {
				head1 = head1end = p;
				p = p->next;
				head1->next = head1end->next = NULL;
			}
			else {
				head1end->next = p;
				head1end = head1end->next;
				p = p->next;
				head1end->next = NULL;
			}
		}
		else {
			if (head2 == NULL) {
				head2 = head2end = p;
				p = p->next;
				head2->next = head2end->next = NULL;
			}
			else {
				head2end->next = p;
				head2end = head2end->next;
				p = p->next;
				head2end->next = NULL;
			}
		}
	}
	setNodes(head, head0, head1, head2, head0end, head1end, head2end);
}

