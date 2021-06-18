#include "dlists.h"


void push_to_stack(t_dlist stack, void *data)
{
    if (!data)
        return ;
    dlist_move_cursor_to_tail(stack);
    dlist_insert_after_cursor(stack, data); 
}

void *pop_from_stack(t_dlist stack)
{
    void *val;

    val = NULL;
    if (stack->len)
    {
        dlist_move_cursor_to_tail(stack);
        val = stack->cursor_p->value;
        dlist_remove_before_cursor(stack, 0);
        return (val);
    }
    return (val);
}

void print_stack(t_dlist l, char *sep)
{
    t_dlist_cell	c;
	void			*value;

	if (l->printer == NULL)
		return ;
	printf("L: (");
	c = l->sentinel->p;
	while (c != l->sentinel)
	{
		value = c->value;
		(*(l->printer)) (value);
		c = c->p;
		if (c != l->sentinel)
			printf("%s", sep);	
	} 
	printf(")");
}