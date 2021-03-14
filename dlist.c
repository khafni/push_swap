/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:17:36 by khafni            #+#    #+#             */
/*   Updated: 2021/03/14 15:40:21 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlists.h"

void			dlist_print(t_dlist l, char *sep)
{
	t_dlist_cell	c;
	void			*value;

	if (l->printer == NULL)
		return ;
	printf("L: ("); 
	c = l->sentinel->n;
	while (c != l->sentinel)
	{
		value = c->value;
		(*(l->printer)) (value);
		c = c->n;
		if (c != l->sentinel)
			printf("%s", sep);	
	} 
	printf(")");
}

t_dlist			dlist_empty_create(t_destroy destroy_f, t_compare compare_f, t_printer print_f)
{
	t_dlist	l;

	l = malloc(sizeof(struct s_dlist));
	l->sentinel = malloc(sizeof(struct s_dlist_cell));
	l->sentinel->n = l->sentinel;
	l->sentinel->p = l->sentinel;
	l->cursor_n = l->sentinel;
	l->cursor_p = l->sentinel; 
	l->destroy = destroy_f;
	l->compare = compare_f;
	l->printer = print_f;
	l->len = 0;
	return (l);
}

void			dlist_destroy(t_dlist l_)
{
	t_dlist			l;
	t_dlist_cell	c;
	t_dlist_cell	next;
	
	l = l_;
	c = l->sentinel->n;
	while (c != l->sentinel)
	{
		next = c->n;
		if (l->destroy != NULL)
			(*(l->destroy)) (c->value);
		free(c);
		c = next;	
	}
	free(l);
}

void			dlist_insert_after_cursor(t_dlist l, void *value)
{
	t_dlist_cell	new;

	new = malloc(sizeof(struct s_dlist_cell));
	new->value = value;
	new->p = l->cursor_p;
	new->n = l->cursor_n;
	l->cursor_n->p = new;
	l->cursor_p->n = new;
	l->cursor_n = new;
	l->len++;
}
 
void			dlist_insert_before_cursor(t_dlist l, void *value)
{
	t_dlist_cell new;
	new->value = value;
	new->p = l->cursor_p;
	new->n = l->cursor_n;
	l->cursor_n->p = new;
	l->cursor_p->n = new;
	l->cursor_p = new;
	l->len++;
}

void			dlist_remove_after_cursor(t_dlist l, char delete)
{
	t_dlist_cell n;
	t_dlist_cell p;

	n = l->cursor_n;
	p = l->cursor_p;
	p->n = n->n;
	n->n->p = p;
	l->cursor_n = n->n;
	if (delete)
		(*(l->destroy)) ((n->value));
	free(n);
	l->len--;
}
void			dlist_remove_before_cursor(t_dlist l, char delete)
{
	t_dlist_cell n;
	t_dlist_cell p;

	n = l->cursor_n;
	p = l->cursor_p;
	n->p = p->p;
	p->p->n = n;	
	l->cursor_p = p->p;
	if (delete)
		(*(l->destroy))(p->value);
	free(p);
	l->len--;
}
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
	l->cursor_p = l->cursor_n;
	l->cursor_n = l->cursor_n->n;
}
void			dlist_move_cursor_to_previous(t_dlist l)
{
	l->cursor_n = l->cursor_p;
	l->cursor_p = l->cursor_p->p;
}

void			dlist_set_after_cursor(t_dlist l, void *value, char delete)
{
	t_dlist_cell c;

	c = l->cursor_n;
	if (delete)
		(*(l->destroy))(c->value);
	c->value = value;
}

void			dlist_set_before_cursor(t_dlist l, void *value, char delete)
{
	t_dlist_cell	c;

	c = l->cursor_p;
	if (delete)
		(*(l->destroy))(c->value);
	c->value = value;
}

void			*dlist_get_after_cursor(t_dlist l, void *value, char delete)
{
	return (l->cursor_n->value);
}

void			*dlist_get_before_cursor(t_dlist l, void *value, char delete)
{
	return (l->cursor_p->value);
}

void print_str(void *str)
{
	printf("%s", (char*)str);
}

int main(int argc, char *argv[])
{
	t_dlist dl;

	dl = dlist_empty_create(free, NULL, print_str);
	dlist_insert_after_cursor(dl, strdup("wooow"));
	dlist_insert_after_cursor(dl, strdup("loool"));
	dlist_insert_after_cursor(dl, strdup("weew"));
	dlist_print(dl, " : ");
	dlist_destroy(dl);
}