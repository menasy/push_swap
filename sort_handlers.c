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

void	ft_a_to_b(t_push_swap *ps)
{
	int	i;
	int	maxbit;
	int	size;

	ft_max_min_mid_val(ps->stack_a, ps->size_a, ps);
	maxbit = ft_bit_len(ps->maxval);
	i = -1;
	while (++i <= maxbit)
	{
		size = ps->size_a;
		while (size-- && !ft_sort_check(ps->stack_a, ps->size_a))
		{
			if (((ps->stack_a[0] >> i) & 1) == 0)
				ft_push_b(ps);
			else
				ft_rotate_a(ps);
		}
		ft_b_to_a(ps->size_b, maxbit, i +1, ps);
	}
	while (ps->size_b != 0)
		ft_push_a(ps);
}

void	ft_b_to_a(int size_b, int maxbit, int index, t_push_swap *ps)
{
	int	j;

	j = -1;
	while (++j < size_b && index <= maxbit
		&& !ft_sort_check(ps->stack_a, ps->size_a))
	{
		if (((ps->stack_b[0] >> index) & 1) == 1)
			ft_push_a(ps);
		else
			ft_rotate_b(ps);
	}
	if (ft_sort_check(ps->stack_a, ps->size_a))
		while (ps->size_b != 0)
			ft_push_a(ps);
}

void	ft_sort_three(int *arry, int size, t_push_swap *ps)
{
	ft_max_min_mid_val(arry, size, ps);
	if (arry[0] == ps->minval && arry[1] == ps->maxval)
	{
		ft_rev_rotate_a(ps);
		ft_swap_a(ps);
	}
	else if (arry[1] == ps->minval && arry[2] == ps->maxval)
		ft_swap_a(ps);
	else if (arry[1] == ps->minval && arry[0] == ps->maxval)
		ft_rotate_a(ps);
	else if (arry[2] == ps->minval && arry[0] == ps->maxval)
	{
		ft_rotate_a(ps);
		ft_swap_a(ps);
	}
	else if (arry[2] == ps->minval && arry[1] == ps->maxval)
		ft_rev_rotate_a(ps);
	else
		return ;
}

void	ft_sort_five(t_push_swap *ps)
{
	while (ps->size_a > 3)
	{
		ft_max_min_mid_val(ps->stack_a, ps->size_a, ps);
		if (ps->stack_a[0] == ps->minval)
			ft_push_b(ps);
		else
			ft_rotate_a(ps);
	}
	ft_sort_three(ps->stack_a, ps->size_a, ps);
	while (ps->size_b != 0)
		ft_push_a(ps);
}

void	ft_assigment_a(t_push_swap *ps)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ps->size_a)
	{
		j = -1;
		while (++j < ps->size_a)
		{
			if (ps->stack_a[i] == ps->indexbuf[j])
			{
				ps->stack_a[i] = ps->buffer[j];
				break ;
			}
		}
	}
}
