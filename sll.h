#ifndef _SLL_H_
#define _SLL_H_

typedef struct _sll
{
	int data;
	struct _sll *next;
} sll;

sll 	*sll_create(void);

int	sll_isempty(sll *l);

int 	sll_destroy(sll *l);

int 	sll_insert(sll *l, sll *position, int data);

int 	sll_insert_at_head(sll *l, int data);

int 	sll_insert_at_tail(sll *l, int data);

int 	sll_delete_by_data(sll *l, int data);

int 	sll_delete_at_head(sll *l);

int 	sll_delete_at_tail(sll *l);

sll 	*sll_find(sll *l, int data);

int 	sll_print(sll *l);

#endif
