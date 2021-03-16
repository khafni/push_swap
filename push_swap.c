/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:36:23 by khafni            #+#    #+#             */
/*   Updated: 2021/03/16 12:40:31 by khafni           ###   ########.fr       */
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

	ts.a = dlist_empty_create(NULL, NULL, print_int);
	return (ts);
}

void			two_stacks_destroy(t_two_stacks *ts)
{
	dlist_destroy(ts->a);
	dlist_destroy(ts->b);
}

void			values_p_swap(void **v1_, void **v2_)
{
	void *tmp;

	tmp = *v1_;
	*v1_ = *v2_;
	*v2_ = tmp;
}

void			sa(t_two_stacks *ts)
{
	if (ts->a->len < 2)
		return ;
	dlist_move_cursor_to_tail(ts->a);
	dlist_move_cursor_to_previous(ts->a);
	values_p_swap(ts->a->cursor_n->value, ts->a->cursor_n->n->value);
}

int main()
{
	void *v1_ = malloc(sizeof(int));
	void *v2_ = malloc(sizeof(int));
	int *v1;
	int *v2;
	v1 = v1_;
	v2 = v2_;
	*v1 = 42;
	*v2 = 21;
	printf("%d %d\n", *v1, *v2);
	values_swap(&v1_, &v2_);
	v1 = v1_;
	v2 = v2_;
	printf("%d %d\n", *v1, *v2);
	values_swap(&v1_, &v2_);
	v1 = v1_;
	v2 = v2_;
	printf("%d %d", *v1, *v2);
}