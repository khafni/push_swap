/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:02:26 by khafni            #+#    #+#             */
/*   Updated: 2021/06/27 19:17:09 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "dlist/dlists.h"
# include <unistd.h>
# include <fcntl.h>
# include "radix_sort/radix_sort.h"
# include "CPCA/generic_parrays/garrptr.h"



typedef struct s_two_stacks  *t_two_stacks;

struct s_two_stacks
{
	t_dlist a;
	t_dlist b;
	int args_number;
};

typedef struct s_elem *t_elem;
struct s_elem
{
	int value;
	int index;	
};

void			print_elem(void *e_);
t_elem elem(int value, int index);
void			values_p_swap(void **v1_, void **v2_);

t_two_stacks	empty_two_stacks(void);
typedef void			(*t_operation) (t_two_stacks ts);
void			two_stacks_destroy(t_two_stacks ts);
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
int *intdub(int n);
int				is_dlist_sorted(t_dlist l);
void			simplify(t_dlist stack_a);
void radix_sort(t_two_stacks ts);
void	_3random_nums_sort(t_two_stacks ts);
void _5random_nums_sort(t_two_stacks ts);

#endif