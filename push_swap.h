/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:02:26 by khafni            #+#    #+#             */
/*   Updated: 2021/05/27 18:23:35 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "dlist/dlists.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_two_stacks  *t_two_stacks;

struct s_two_stacks
{
	t_dlist a;
	t_dlist b;
	int args_number;
};

void			values_p_swap(void **v1_, void **v2_);

t_two_stacks	empty_two_stacks(void);
typedef void			(*t_operation) (t_two_stacks ts);
void			two_stacks_destroy(t_two_stacks ts);
void			sa(t_two_stacks ts);
void			sb(t_two_stacks ts);
void			ss(t_two_stacks ts);
void			pa(t_two_stacks ts);
void			pb(t_two_stacks ts);
void			ra(t_two_stacks ts);
void			rb(t_two_stacks ts);
void			rr(t_two_stacks ts);
void			rra(t_two_stacks ts);
void			rrb(t_two_stacks ts);
void			rrr(t_two_stacks ts);

int *intdub(int n);
int				is_dlist_sorted(t_dlist l);

typedef struct s_save t_save;

struct s_save
{
	int i;
	int k;
};

void positive_sort(t_two_stacks tstacks, t_save *save, int args_number);

#endif