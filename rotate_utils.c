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

void	ft_rotate_a(t_push_swap *ps)
{
	int	tmp_a;
	int	i;

	i = -1;
	tmp_a = ps->stack_a[0];
	while (++i < ps->size_a -1)
		ps->stack_a[i] = ps->stack_a[i +1];
	ps->stack_a[ps->size_a -1] = tmp_a;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_push_swap *ps)
{
	int	tmp_b;
	int	i;

	i = -1;
	tmp_b = ps->stack_b[0];
	while (++i < ps->size_b -1)
		ps->stack_b[i] = ps->stack_b[i +1];
	ps->stack_b[ps->size_b -1] = tmp_b;
	write(1, "rb\n", 3);
}

void	ft_rotate_rotate(t_push_swap *ps)
{
	int	tmp_a;
	int	tmp_b;
	int	i;

	i = -1;
	tmp_a = ps->stack_a[0];
	while (++i < ps->size_a -1)
		ps->stack_a[i] = ps->stack_a[i +1];
	ps->stack_a[ps->size_a -1] = tmp_a;
	write(1, "ra\n", 4);
	i = -1;
	tmp_b = ps->stack_b[0];
	while (++i < ps->size_b -1)
		ps->stack_b[i] = ps->stack_b[i +1];
	ps->stack_b[ps->size_b -1] = tmp_b;
	write(1, "rb\n", 3);
}

void	ft_rev_rotate_a(t_push_swap *ps)
{
	int	tmp_a;
	int	i;

	i = ps->size_a;
	tmp_a = ps->stack_a[ps->size_a -1];
	while (--i > 0)
		ps->stack_a[i] = ps->stack_a[i -1];
	ps->stack_a[0] = tmp_a;
	write(1, "rra\n", 4);
}

void	ft_rev_rotate_b(t_push_swap *ps)
{
	int	tmp_b;
	int	i;

	i = ps->size_b;
	tmp_b = ps->stack_b[ps->size_b -1];
	while (--i > 0)
		ps->stack_b[i] = ps->stack_b[i -1];
	ps->stack_b[0] = tmp_b;
	write(1, "rrb\n", 4);
}
