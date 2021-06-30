/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:58:11 by khafni            #+#    #+#             */
/*   Updated: 2021/06/30 11:06:22 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSTR_H
# define RSTR_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
**	stupid one usage version implementation of realloc
*/
void			*ft_mem_grow(void *addr, size_t old_size, size_t new_size);
/*
**	a resizable string that can be appended to its end
**	(a char * on steroids)
*/
typedef struct s_rstr
{
	char		*data;
	int			alloc;
	int			len;
}	*t_rstr;
/*
**	rstr constructor
*/
t_rstr			rstr_create (int alloc);
/*
**	rstr destructor
*/
void			rstr_destroy (void *rs);
/*
**	rstr setter
*/
void			rstr_set (t_rstr rs, size_t index, char value);
/*
**	appending to the end of the rstr
*/
void			rstr_add (t_rstr rs, char value);
/*
**	clear rstr
*/
void			rstr_clear(t_rstr rs);

/*
**	convert str to c string
*/

char			*rstr_to_cstr(t_rstr rs);
char			rstr_get(t_rstr rs, int index);
t_rstr			cstr_to_rstr(char *cstr);
int				is_rstr_eq_cstr(t_rstr rs, char *cstr);
void			print_rstr(t_rstr rs);
#endif
