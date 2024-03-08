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

void	ft_error_0(t_push_swap *ps)
{
	free(ps);
	write (2, "Error\n", 6);
	exit(1);
}

void	ft_error_1(t_push_swap *ps)
{
	if (ps->ac == 2)
		ft_free_data(ps);
	free(ps);
	write (2, "Error\n", 6);
	exit(1);
}

void	ft_error_2(t_push_swap *ps)
{
	if (ps->ac == 2)
		ft_free_data(ps);
	free(ps->buffer);
	free(ps);
	write (2, "Error\n", 6);
	exit(1);
}

void	ft_error_3(t_push_swap *ps)
{
	if (ps->ac == 2)
		ft_free_data(ps);
	free(ps->buffer);
	free(ps->stack_a);
	free(ps->stack_b);
	free(ps);
	write (2, "Error\n", 6);
	exit(1);
}

void	ft_full_free(t_push_swap *ps)
{
	if (ps->ac == 2)
		ft_free_data(ps);
	if (ps->size_a > 5)
		free(ps->indexbuf);
	free(ps->buffer);
	free(ps->stack_a);
	free(ps->stack_b);
	free(ps);
	exit(0);
}
