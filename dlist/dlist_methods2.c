/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_methods2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:06:00 by khafni            #+#    #+#             */
/*   Updated: 2021/05/22 18:45:01 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlists.h"

void			dlist_move_cursor_to_head(t_dlist l)
{
	l->cursor_p = l->sentinel;
	l->cursor_n = l->sentinel->n;
}

void			dlist_move_cursor_to_tail(t_dlist l)
{
	l->cursor_n = l->sentinel;
	l->cursor_p = l->sentinel->p;
}

void			dlist_move_cursor_to_next(t_dlist l)
{
	if (l->cursor_n != l->sentinel)
	{
		l->cursor_p = l->cursor_n;
		l->cursor_n = l->cursor_n->n;
	}
}

void			dlist_move_cursor_to_previous(t_dlist l)
{
	if (l->cursor_p != l->sentinel)
	{
		l->cursor_n = l->cursor_p;
		l->cursor_p = l->cursor_p->p;
	}
}