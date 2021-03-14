/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlists.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 09:23:10 by khafni            #+#    #+#             */
/*   Updated: 2021/03/14 17:31:48 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/*
** circular doubly linked list module
*/

/*
** function pointer to abstract the node's content distructor
** if are an allocated object at the heap
*/

typedef void	(*t_destroy)(void *obj);

/*
** function pointer to abstract the  node's content print
** to console function to 
*/

typedef void	(*t_printer)(void *obj);

/*
** function pointer to abstract
*/

typedef int		(*t_compare)(void *obj);

typedef struct s_dlist_cell *t_dlist_cell;

struct	s_dlist_cell
{
	void			*value;
	t_dlist_cell	p;	
	t_dlist_cell	n;
};

typedef struct s_dlist	*t_dlist;

struct s_dlist
{
	t_dlist_cell	sentinel;
	t_dlist_cell	cursor_p;
	t_dlist_cell	cursor_n;
	t_destroy		destroy;
	t_printer		printer;
	t_compare		compare;
	size_t			len;
};

t_dlist			dlist_empty_create(t_destroy destroy, t_compare compare, t_printer printer);
void			dlist_destroy(t_dlist l);
void			dlist_insert_after_cursor(t_dlist l, void *value);
void			dlist_insert_before_cursor(t_dlist l, void *value);

/*
**	delete is a boolean set as 0 to not remove the content of the element after cursor
**	or set to 1 to remove it
*/

void			dlist_remove_after_cursor(t_dlist l, char delete);
void			dlist_remove_before_cursor(t_dlist l, char delete);
void			dlist_print(t_dlist l, char *sep);
void			dlist_move_cursor_to_head(t_dlist l);
void			dlist_move_cursor_to_tail(t_dlist l);
void			dlist_move_cursor_to_next(t_dlist l);
void			dlist_move_cursor_to_previous(t_dlist l);
void			dlist_set_after_cursor(t_dlist l, void *value, char delete);
void			dlist_set_before_cursor(t_dlist l, void *value, char delete);
void			*dlist_get_after_cursor(t_dlist l, char delete);
void			*dlist_get_before_cursor(t_dlist l, char delete);
char			is_empty_dlist(t_dlist l);
void			dlist_pushback(t_dlist l, void *value);

#endif