#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

typedef struct _queue
{
	sll *l;
} queue;

queue *q_create()
{
	queue *q = malloc(sizeof(queue));
	if(!q)
		return NULL;
	q->l = sll_create();
	if(!q->l)
		return NULL;
	return q;
}

int q_destroy(queue *q)
{
	if(q->l)
		sll_destroy(q->l);	
	free(q);
	q = NULL;
	return 0;
}

int q_isempty(queue *q)
{
	return sll_isempty(q->l);	
}

int en_queue(queue *q, int data)
{
	return sll_insert_at_tail(q->l, data);	
}

int de_queue(queue *q, int *data)
{
	*data = q->l->next->data;	
	return sll_delete_at_head(q->l);
}

int main(void)
{
	queue *q;
	int a[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(a)/sizeof(int);

	q = q_create();
	
	int i;
	for(i=0; i<size; i++)
	{
		en_queue(q, a[i]);
	}

	int data;
	for(i=0; i< size; i++)
	{
		de_queue(q, &data);
		printf("%d ", data);
	}
	printf("\n");

	q_destroy(q);

	printf("queue is empty? %d\n", q_isempty(q));
}
