#include "push_swap.h"
#include <string.h>
#include <ctype.h>
#include "file.h"

int ft_is_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_operation which_operation(t_rstr rs)
{
	if (is_rstr_eq_cstr(rs, "sa"))
		return (sa);
	else if (is_rstr_eq_cstr(rs, "sb"))
		return (sb);
	else if (is_rstr_eq_cstr(rs, "ss"))
		return (ss);
	else if (is_rstr_eq_cstr(rs, "pa"))
		return (pa);
	else if (is_rstr_eq_cstr(rs, "pb"))
		return (pb);
	else if (is_rstr_eq_cstr(rs, "ra"))
		return (ra);
	else if (is_rstr_eq_cstr(rs, "rb"))
		return (rb);
	else if (is_rstr_eq_cstr(rs, "rr"))
		return (rr);
	else if (is_rstr_eq_cstr(rs, "rra"))
		return (rr);
	else if (is_rstr_eq_cstr(rs, "rrb"))
        return (rra);
	else if (is_rstr_eq_cstr(rs, "rrr"))
        return (rra);
	return (NULL);
}

t_two_stacks get_arguments(int argc, char **argv, int *e, int args_number)
{
	t_two_stacks	ts;
	int				i;

	ts = empty_two_stacks();
	i = 1;
	ts->args_number = args_number;
	while (i < argc)
	{
		if(!ft_is_num(argv[1]))
			*e = 1;
		dlist_move_cursor_to_tail(ts->a);
		dlist_insert_before_cursor(ts->a, intdub(atoi(argv[i])));
		i++;
	}
	return (ts);
}

void	get_apply_operations(t_two_stacks ts, int *e)
{
	t_file f;
	t_operation op;

	f = file(0);
	while (f->reading_state > 0)
	{
		file_read_line(f);
		op = which_operation(f->str_buff);
		if (op)
			(*op)(ts);
		else
			*e = 1;
	}
	file_destroy(f);
}
void positive_sort(t_dlist );
int main(int argc, char **argv)
{
	t_two_stacks ts;
	t_operation op;	
	int			e;

	if (argc < 2)
		return 1;
	e = 0;
	ts = get_arguments(argc, argv, &e);
	get_apply_operations(ts, &e);	
	if (e)
		printf("ERROR\n");
	else if (is_dlist_sorted(ts->a) && !ts->b->len)
		printf("OK\n");
	else
		printf("KO\n");	
	two_stacks_destroy(ts);
	return (0);
}