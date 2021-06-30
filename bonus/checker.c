#include "checker.h"

t_operation	which_operation(char *line)
{
	if (!strcmp(line, "sa"))	
		return (sa);
	else if (!strcmp(line, "sb"))	
		return (sb);
	else if (!strcmp(line, "ss"))	
		return (ss);
	else if (!strcmp(line, "pa"))	
		return (pa);
	else if (!strcmp(line, "pb"))	
		return (pb);
	else if (!strcmp(line, "ra"))	
		return (ra);
	else if (!strcmp(line, "rb"))	
		return (rb);
	else if (!strcmp(line, "rr"))	
		return (rr);
	else if (!strcmp(line, "rra"))	
		return (rra);
	else if (!strcmp(line, "rrr"))	
		return (rrr);
	else
		return (NULL);
}

void		execute_operation(char *line, t_two_stacks ts)
{
	t_operation op;

	op = which_operation(line);
	op(ts, 0);
}
