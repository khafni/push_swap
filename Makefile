SRCS1 = ./operations1.c ./operations3.c ./rstr_methods1.c  ./simplify_elems.c ./two_stacks.c ./operations2.c ./push_swap.c ./rstr.c ./rstr_methods2.c ./tools1.c ./radix_sort/radix_sort.c ./small_range_sort/3_random_nums_sort.c ./small_range_sort/5_random_nums_sort.c\
./dlist/dlist.c dlist/dlist_methods1.c dlist/dlist_methods2.c dlist/dlist_methods3.c dlist/dlist_methods4.c dlist/stack_methods1.c
BONUS_SRCS1 = ./checker_bonus/checker_bonus.c ./checker_bonus/checker_main_bonus.c ./checker_bonus/file_bonus.c

NAME1	=	push_swap 
NAME2	=	checker 
CC	 = gcc
CFLAGS	 = -Wall -Wextra -Werror

all:$(NAME1)
$(NAME1):
	@$(MAKE) -C CPCA
	@echo "\033[0;32mcompiling push_swap"	
	@gcc $(CFLAGS) CPCA/CPCA.a $(SRCS1) push_swap_main.c -o push_swap 

clean:
	@rm -f $(NAME1)
	@rm -f $(NAME2)
fclean: clean
	@$(MAKE) -C CPCA fclean
	@echo "\033[0;33meverything cleaned"

bonus: fclean
	@echo "\033[0;32mcompiling push_swap bonus"
	@$(MAKE) -C CPCA
	@gcc $(CFLAGS) CPCA/CPCA.a $(SRCS1) push_swap_main.c -o $(NAME1) 
	@gcc $(CFLAGS) CPCA/CPCA.a $(SRCS1) $(BONUS_SRCS1) -o $(NAME2) 

re : fclean all
.PHONY: all clean fclean bonus re
