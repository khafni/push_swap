#include "push_swap.h"
#include <string.h>
#include <ctype.h>

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

int main(int argc, char **argv)
{
    t_two_stacks ts;
    int i;

    if (argc < 2)
        return 1;
    ts = empty_two_stacks();
    i = 1;
    while (i < argc)
    {
        if(!ft_is_num(argv[1]))
        {
            write (1, "ERROR", 6);
            return (1);
        }
        dlist_move_cursor_to_head(ts->a);
        dlist_insert_after_cursor(ts->a, intdub(atoi(argv[i])));
        i++;
    }
    dlist_print(ts->a, " , ");
    return (0);
}