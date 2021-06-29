#include "file.h"

int main()
{
    t_file f = file(0);
    while (f->reading_state > 0)
	{
		file_read_line(f);
        printf("|%s|\n", f->str_buff->data);
	}
    return(0);
}