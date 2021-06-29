#include "push_swap.h"

t_two_stacks	empty_two_stacks(void)
{
	t_two_stacks	ts;

	ts = malloc(sizeof(struct s_two_stacks));
	ts->a = dlist_empty_create(free, NULL, NULL);
	ts->b = dlist_empty_create(free, NULL, NULL);
	ts->args_number = 0;
	return (ts);
}

void	two_stacks_destroy(t_two_stacks ts)
{
	dlist_destroy(ts->a);
	dlist_destroy(ts->b);
	free(ts);
}

void	values_p_swap(void **v1_, void **v2_)
{
	void	*tmp;

	tmp = *v1_;
	*v1_ = *v2_;
	*v2_ = tmp;
}

int	*intdub(int n)
{
	int	*int_ptr;

	int_ptr = malloc(sizeof(int));
	*int_ptr = n;
	return (int_ptr);
}

t_two_stacks	get_arguments_(int argc, char **argv)
{
	t_two_stacks	ts;
	int				i;	

	ts = empty_two_stacks();
	ts->args_number = argc - 1;
	i = ts->args_number;
	while (i >= 1)
	{
		push_to_stack(ts->a, elem(atoi(argv[i]), 0));
		i--;
	}
	simplify(ts->a);
	return (ts);
}
