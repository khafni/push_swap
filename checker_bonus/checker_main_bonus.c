#include "file_bonus.h"
#include "checker_bonus.h"

int	main(int argc, char *argv[])
{
	t_file			f;
	t_two_stacks	ts;

	if (argc < 3)
		return (0);
	if (check_if_duplicates(argc, argv) || !check_if_nums(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	f = file(0);
	ts = get_arguments_(argc, argv);
	while (f->reading_state > 0)
	{
		file_read_line(f);
		if (!execute_operation(f->str_buff->data, ts))
			return (0);
	}
	if (is_dlist_sorted(ts->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	two_stacks_destroy(ts);
	return (0);
}
