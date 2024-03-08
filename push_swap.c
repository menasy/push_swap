/*
 ███▄ ▄███▓▓█████  ███▄    █  ▄▄▄        ██████▓██   ██▓
▓██▒▀█▀ ██▒▓█   ▀  ██ ▀█   █ ▒████▄    ▒██    ▒ ▒██  ██▒
▓██    ▓██░▒███   ▓██  ▀█ ██▒▒██  ▀█▄  ░ ▓██▄    ▒██ ██░
▒██    ▒██ ▒▓█  ▄ ▓██▒  ▐▌██▒░██▄▄▄▄██   ▒   ██▒ ░ ▐██▓░
▒██▒   ░██▒░▒████▒▒██░   ▓██░ ▓█   ▓██▒▒██████▒▒ ░ ██▒▓░
░ ▒░   ░  ░░░ ▒░ ░░ ▒░   ▒ ▒  ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░  ██▒▒▒
░  ░      ░ ░ ░  ░░ ░░   ░ ▒░  ▒   ▒▒ ░░ ░▒  ░ ░▓██ ░▒░
░      ░      ░      ░   ░ ░   ░   ▒   ░  ░  ░  ▒ ▒ ░░
       ░      ░  ░         ░       ░  ░      ░  ░ ░
                                                ░ ░*/

#include "push_swap.h"

void	ft_sort_handler(t_push_swap *ps)
{
	if (ps->size_a == 2)
		ft_swap_a(ps);
	else if (ps->size_a == 3)
		ft_sort_three(ps->stack_a, ps->size_a, ps);
	else if (ps->size_a <= 5)
		ft_sort_five(ps);
	else
	{
		ft_crate_index(ps->size_a, ps);
		ft_a_to_b(ps);
		ft_assigment_a(ps);
	}
}

int	main(int ac, char *argv[])
{
	t_push_swap	*ps;

	ps = malloc(sizeof(t_push_swap));
	if (ps == NULL)
		ft_error_0(ps);
	if (ac == 1)
		exit(1);
	ps->size_b = 0;
	ps->ac = ac;
	ft_arg_write(argv, ps);
	ft_data_to_int(ps);
	ft_memory(ps);
	ft_sort_handler(ps);
	ft_full_free(ps);
	return (0);
}
