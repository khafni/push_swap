#include "dlists.h"
#include <stdlib.h>
#include <string.h>

int main()
{
    t_dlist dl = dlist_empty_create(NULL, NULL, NULL);
    push_to_stack(dl, strdup("fuck"));
    printf("%s", (char*)pop_from_stack(dl)); 
    printf("%s", (char*)pop_from_stack(dl)); 
    printf("%s", (char*)pop_from_stack(dl)); 
    return (0);
}