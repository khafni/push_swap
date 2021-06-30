#ifndef CHECKER_H
# define CHECKER_H
# include "../push_swap.h"
# include <string.h>

t_operation	which_operation(char *line);
void		execute_operation(char *line, t_two_stacks ts);
#endif