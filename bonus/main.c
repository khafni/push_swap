#include "file.h"
#include "checker.h"

int main(int argc, char *argv[])
{
    t_file f = file(0);
    t_two_stacks ts;

    f = file(0);
    ts = get_arguments_(argc, argv);
    while (f->reading_state > 0)
	{
		file_read_line(f);
        execute_operation(f->str_buff->data, ts); 
	}
    if (is_dlist_sorted(ts->a))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    two_stacks_destroy(ts);
    return(0);
}