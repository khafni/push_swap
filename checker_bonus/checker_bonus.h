#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "../push_swap.h"
# include <string.h>
# include "file_bonus.h"

t_operation	which_operation(char *line);
int			execute_operation(char *line, t_two_stacks ts);
#endif