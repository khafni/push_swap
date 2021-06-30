/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:02:26 by khafni            #+#    #+#             */
/*   Updated: 2021/06/30 11:25:28 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "dlist/dlists.h"
# include <unistd.h>
# include <fcntl.h>
# include "radix_sort/radix_sort.h"
# include "CPCA/generic_parrays/garrptr.h"
# define RRA 0
# define RA 1
typedef struct s_two_stacks
{
	t_dlist	a;
	t_dlist	b;
	int		args_number;
}	*t_two_stacks;

typedef struct s_elem
{
	int	value;
	int	index;	
}	*t_elem;

void			print_elem(void *e_);
t_elem			elem(int value, int index);
void			values_p_swap(void **v1_, void **v2_);
t_two_stacks	empty_two_stacks(void);
typedef void	(*t_operation)(t_two_stacks ts, int is_printable);
void			two_stacks_destroy(t_two_stacks ts);
t_two_stacks	get_arguments_(int argc, char **argv);
void			sa(t_two_stacks ts, int is_printable);
void			sb(t_two_stacks ts, int is_printable);
void			ss(t_two_stacks ts, int is_printable);
void			pa(t_two_stacks ts, int is_printable);
void			pb(t_two_stacks ts, int is_printable);
void			ra(t_two_stacks ts, int is_printable);
void			rb(t_two_stacks ts, int is_printable);
void			rr(t_two_stacks ts, int is_printable);
void			rra(t_two_stacks ts, int is_printable);
void			rrb(t_two_stacks ts, int is_printable);
void			rrr(t_two_stacks ts, int is_printable);
int				*intdub(int n);
int				is_dlist_sorted(t_dlist l);
void			simplify(t_dlist stack_a);
void			radix_sort(t_two_stacks ts);
void			_3random_nums_sort(t_two_stacks ts);
void			_5random_nums_sort(t_two_stacks ts);
void			*dlist_get_last_elem(t_dlist dl);
int				check_if_duplicates(int argc, char *argv[]);
int				check_if_nums(char *argv[]);
int				ft_strcmp(const char *s1, const char *s2);
#endif