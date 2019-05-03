#include <stdio.h>
#include <stdlib.h>

#include "sll.h"

//#define TEST


/*
* create head node
*/
sll * sll_create(void)
{
	sll *header;
	header = malloc(sizeof(sll));
	if(!header)
		return NULL;
	header->data = 0; //unused
	header->next = NULL;
	return header;
}

/*
* destory sll
*/
int sll_destroy(sll *l)
{
	sll *dell = l;
	while(dell != NULL)
	{
		sll *tmpl = dell;
		dell = tmpl->next;
		free(dell);
	}
	l = NULL;
	return 0;
}

int sll_isempty(sll *l)
{
	return (l == NULL || l->next == NULL);
}
/*
* insert after position
*/
int sll_insert(sll *l, sll *position, int data)
{
	if(0)
		l = l; //unused
	sll *newcell = malloc(sizeof(sll));
	if(!newcell)
		return -1;
	newcell->data = data;
	newcell->next = position->next;
	position->next = newcell;
	return 0;
}

int sll_insert_at_head(sll *l, int data)
{
	return sll_insert(l, l, data);	
}

int sll_insert_at_tail(sll *l, int data)
{
	sll *tmpl = l;
	while(tmpl->next != NULL)
		tmpl = tmpl->next;
	return sll_insert(l, tmpl, data);	
}

int sll_delete_by_data(sll *l, int data)
{
	sll *tmpl = l;
	while(tmpl->next != NULL && tmpl->next->data != data)
		tmpl = tmpl->next;
	if(tmpl->next->data == data)// find it
	{
		sll *dell = tmpl->next;
		tmpl->next = tmpl->next->next;
		free(dell);
		return 0;
	}
	return -1;
}

int sll_delete_at_head(sll *l)
{
	sll *dell = l->next;
	if(dell != NULL)
	{
		sll *tmpl = dell;
		l->next = tmpl->next;
		free(dell);
		return 0;
	}
	return -1;
}

int sll_delete_at_tail(sll *l)
{
	sll *dell = l->next;
	if(dell != NULL)
	{
		if(dell->next == NULL)
			return sll_delete_at_head(dell);
		else
		{
			sll *before = l;
			sll *current = l->next;
			sll *next = l->next->next;
			while(next != NULL)
			{
				before = current;
				current = next;
				next = next->next;
			}
			before->next = next;
			free(current);
			return 0;
		}	
	}
	return -1;
}

sll *sll_find(sll *l, int data)
{
	sll *tmpl = l->next;
	while(tmpl != NULL && tmpl->data != data)
		tmpl = tmpl->next;
	return tmpl;
}

int sll_print(sll *l)
{
	printf("header");
	sll *tmpl = l->next;
	while(tmpl != NULL)
	{
		printf("->%d", tmpl->data);
		tmpl = tmpl->next;
	}
	printf("\n");
	return 0;
}

#ifdef TEST
int main(void)
{
	sll *l = sll_create();
	
	int i;
	for(i=3; i<7; i++)
		sll_insert_at_tail(l, i);
	sll_print(l);

	sll_insert_at_head(l, 2);
	sll_print(l);

	sll_insert_at_tail(l, 7);
	sll_print(l);
	
	sll_delete_at_head(l);
	sll_print(l);
	
	sll_delete_at_tail(l);
	sll_print(l);
	
	sll_delete_by_data(l, 4);
	sll_print(l);
	
	sll_destroy(l);
}
#endif
