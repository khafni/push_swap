/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_methods4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:07:41 by khafni            #+#    #+#             */
/*   Updated: 2021/03/31 13:48:25 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlists.h"

int		is_dlist_sorted(t_dlist l)
{
	int is_sort;
	int val1;
	int val2;

	is_sort = 1;
	dlist_move_cursor_to_head(l);
	while (l->cursor_n != l->sentinel)
	{
		val1 = *(int*)l->cursor_n->value;
		val2 = *(int*)l->cursor_n->n->value;
		if (val1 > val2)
			is_sort = 0;
		dlist_move_cursor_to_next(l);
	}
	return (is_sort);
}