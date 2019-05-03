#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"


//#define ARRAY_STACK


#ifdef ARRAY_STACK
typedef struct _stack
{
	int current_index;
	int *data;
	int size;
} stack;

stack *stack_create(int size)
{
	stack *header;
	header = malloc(sizeof(stack));
	if(!header)  
		return NULL;
	header->current_index = 0;
	header->size = size;
	header->data = malloc(sizeof(int)*size);
	if(!(header->data))
		return NULL;
	memset(header->data, 0, sizeof(int)*size);
	return header;
}

int stack_destroy(stack *s)
{
	if(s->data)
		free(s->data);
	free(s);
	return 0;
}

int stack_isempty(stack *s)
{
	return s->current_index == 0;
}

int stack_isfull(stack *s)
{
	return s->current_index == s->size;// - 1;
}

int stack_push(stack *s, int data)
{
	if(stack_isfull(s))
		return -1;
	s->data[ s->current_index ] = data;
	s->current_index ++ ;
	return 0;
}

int stack_pop(stack *s, int *data)
{
	if(stack_isempty(s))
	{
		*data = 0;
		return -1;
	}
	s->current_index -- ;
	*data = s->data[ s->current_index ];
	return 0;
}

int stack_top(stack *s, int *data)
{
	if(stack_isempty(s))
	{
		*data = 0;
		return -1;
	}
	*data = s->data[ s->current_index - 1 ];
	return 0;
}

#else
typedef struct _stack
{
	sll *l;
} stack;

stack *stack_create(void)
{
	stack *s = malloc(sizeof(stack));
	if(!s)
		return NULL;
	s->l = sll_create();
	return s;
}

int stack_destroy(stack *s)
{
	if(s->l)
		sll_destroy(s->l);
	free(s);
	return 0;
}

int stack_isempty(stack *s)
{
	return s->l->next == NULL;
}

int stack_push(stack *s, int data)
{
	return sll_insert_at_head(s->l, data);
}

int stack_pop(stack *s, int *data)
{
	if(stack_isempty(s))
		return -1;
	*data = s->l->next->data;
	return sll_delete_at_head(s->l);
}

int stack_top(stack *s, int *data)
{
	if(stack_isempty(s))
		return -1;
	*data = s->l->next->data;
	return 0;
}


#endif

int main(int argc, char *argv[])
{
	int test_array[] = {1,3,5,7,9,11};
	int size = sizeof(test_array)/sizeof(int);

	#ifdef ARRAY_STACK
	stack *s = stack_create(size);
	#else
	stack *s = stack_create();
	#endif

	int i;
	for(i=0; i<size; i++)
		stack_push(s, test_array[i]);

	int data;
	stack_top(s, &data);
	printf("stack top data: %d\n", data);

	for(i=0; i<size; i++)
	{
		int data;
		stack_pop(s, &data);
		printf("stack[%d]: %d\n", size - 1 - i, data);
	}
	
	stack_destroy(s);

	return 0;
}
