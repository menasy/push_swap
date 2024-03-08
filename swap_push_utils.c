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

void	ft_swap_a(t_push_swap *ps)
{
	int	tmp;
	int	len;

	len = sizeof(ps->stack_a) / 4;
	if (len >= 2)
	{
		tmp = ps->stack_a[0];
		ps->stack_a[0] = ps->stack_a[1];
		ps->stack_a[1] = tmp;
	}
	else
		return ;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_push_swap *ps)
{
	int	tmp;
	int	len;

	len = sizeof(ps->stack_b) / 4;
	if (len >= 2)
	{
		tmp = ps->stack_b[0];
		ps->stack_b[0] = ps->stack_b[1];
		ps->stack_b[1] = tmp;
	}
	else
		return ;
	write(1, "sb\n", 3);
}

void	ft_swap_swap(t_push_swap *ps)
{
	int	tmp_a;
	int	len_a;
	int	tmp_b;
	int	len_b;

	len_a = sizeof(ps->stack_a) / 4;
	len_b = sizeof(ps->stack_b) / 4;
	if (len_a >= 2 && len_b >= 2)
	{
		tmp_b = ps->stack_b[0];
		ps->stack_b[0] = ps->stack_b[1];
		ps->stack_b[1] = tmp_b;
		tmp_a = ps->stack_a[0];
		ps->stack_a[0] = ps->stack_a[1];
		ps->stack_a[1] = tmp_a;
	}
	else
		return ;
	write(1, "ss\n", 3);
}

void	ft_push_a(t_push_swap *ps)
{
	int	len_a;
	int	i;

	len_a = ps->size_a++;
	if (ps->size_b >= 1)
	{
		len_a++;
		while (0 < --len_a)
			ps->stack_a[len_a] = ps->stack_a[len_a -1];
		ps->stack_a[0] = ps->stack_b[0];
		ps->stack_b[0] = -1;
		i = -1;
		while (++i < ps->size_b)
			ps->stack_b[i] = ps->stack_b[i + 1];
		ps->size_b--;
	}
	else
		return ;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_push_swap *ps)
{
	int	len_b;
	int	i;

	len_b = ps->size_b++;
	if (ps->size_a >= 1)
	{
		len_b++;
		while (0 < --len_b)
			ps->stack_b[len_b] = ps->stack_b[len_b -1];
		ps->stack_b[0] = ps->stack_a[0];
		ps->stack_a[0] = -1;
		i = -1;
		while (++i < ps->size_a)
			ps->stack_a[i] = ps->stack_a[i + 1];
		ps->size_a--;
	}
	else
		return ;
	write(1, "pb\n", 3);
}
