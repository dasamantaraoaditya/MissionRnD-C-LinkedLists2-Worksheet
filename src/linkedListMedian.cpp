/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	struct node *twice, *once;
	twice = once = head;
	if (twice->next == NULL)
		return twice->num;

	if (twice->next->next == NULL)
		return (once->num + once->next->num) / 2.0;

	while (1)
	{

		twice = twice->next->next;
		if (twice == NULL)
		{
			return (once->num + once->next->num) / 2.0;
		}
		once = once->next;
		if (twice->next == NULL)
		{
			return once->num;
		}

	}
	return 0;
}

