/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *ans_head = NULL, *head = NULL;

	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	if (head1->num < head2->num){
		ans_head = head = head1;
		head1 = head1->next;
	}
	else
	{
		ans_head = head = head2;
		head2 = head2->next;
	}
	while (head1 != NULL&&head2 != NULL){
		if (head1->num < head2->num){
			ans_head->next = head1;
			ans_head = ans_head->next;
			head1 = head1->next;
		}
		else
		{
			ans_head->next = head2;
			ans_head = head2;
			head2 = head2->next;
		}
	}
	if (head1 != NULL){
		ans_head->next = head1;
	}
	if (head2 != NULL){
		ans_head->next = head2;
	}
	return head;
}
