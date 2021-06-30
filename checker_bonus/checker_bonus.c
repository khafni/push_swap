#include "checker_bonus.h"

t_operation	which_operation(char *line)
{
	if (!ft_strcmp(line, "sa"))
		return (sa);
	else if (!ft_strcmp(line, "sb"))
		return (sb);
	else if (!ft_strcmp(line, "ss"))
		return (ss);
	else if (!ft_strcmp(line, "pa"))
		return (pa);
	else if (!ft_strcmp(line, "pb"))
		return (pb);
	else if (!ft_strcmp(line, "ra"))
		return (ra);
	else if (!ft_strcmp(line, "rb"))
		return (rb);
	else if (!ft_strcmp(line, "rr"))
		return (rr);
	else if (!ft_strcmp(line, "rra"))
		return (rra);
	else if (!ft_strcmp(line, "rrr"))
		return (rrr);
	else
		return (NULL);
}

int	execute_operation(char *line, t_two_stacks ts)
{
	t_operation	op;
	t_file		f;

	f = file(0);
	if (!f->str_buff->len)
		return (1);
	op = which_operation(line);
	if (!op)
	{
		write(1, "Erroroo\n", 6);
		two_stacks_destroy(ts);
		file_destroy(f);
		return (0);
	}
	op(ts, 0);
	return (1);
}
