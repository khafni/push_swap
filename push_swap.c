/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:36:23 by khafni            #+#    #+#             */
/*   Updated: 2021/03/28 17:38:58 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_int(void *num)
{
	printf("%d", *((int*)num));
}

t_two_stacks empty_two_stacks(void)
{
	t_two_stacks ts;

	ts = malloc(sizeof(struct s_two_stacks));
	ts->a = dlist_empty_create(free, NULL, print_int);
	ts->b = dlist_empty_create(free, NULL, print_int);
	return (ts);
}

void			two_stacks_destroy(t_two_stacks ts)
{
	dlist_destroy(ts->a);
	dlist_destroy(ts->b);
	free(ts);
}

void			values_p_swap(void **v1_, void **v2_)
{
	void *tmp;

	tmp = *v1_;
	*v1_ = *v2_;
	*v2_ = tmp;
}


void			sa(t_two_stacks ts)
{
	int a;
	int b;
	int tmp;
	if (ts->a->len < 2)
		return ;
	dlist_move_cursor_to_tail(ts->a);
	a = *(int*)(ts->a->cursor_p->value); 
	b = *(int*)(ts->a->cursor_p->p->value);
	values_p_swap(&ts->a->cursor_p->value,  &ts->a->cursor_p->p->value);
}

int *intdub(int n)
{
	int *int_ptr;
	
	int_ptr = malloc(sizeof(int));
	*int_ptr = n;
	return (int_ptr);
}

int main()
{
	t_two_stacks ts;

	ts = empty_two_stacks();
	dlist_pushback(ts->a, intdub(1));
	dlist_pushback(ts->a, intdub(2));
	dlist_print(ts->a, " , ");
	sa(ts);
	dlist_print(ts->a, " , ");	
	two_stacks_destroy(ts);
}