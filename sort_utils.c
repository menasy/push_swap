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

int	*ft_sort(int *arry, int size)
{
	int	tmp;
	int	*cpyarry;
	int	i;
	int	j;

	i = 0;
	cpyarry = ft_intcpy(arry, size);
	while (i < size)
	{
		j = i;
		while (++j < size)
		{
			if (cpyarry[i] > cpyarry[j])
			{
				tmp = cpyarry[j];
				cpyarry[j] = cpyarry[i];
				cpyarry[i] = tmp;
			}
		}
		i++;
	}
	return (cpyarry);
}

int	ft_sort_check(int *arry, int size)
{
	int	check;
	int	i;
	int	j;

	check = 0;
	i = -1;
	while ((++i < size) && check == 0)
	{
		j = i + 1;
		while (j < size)
		{
			if (arry[i] < arry[j])
				j++;
			else
			{
				check = 1;
				break ;
			}
		}
	}
	if (check == 1)
		return (0);
	return (1);
}

void	ft_max_min_mid_val(int *arry, int size, t_push_swap *ps)
{
	int	*cpyarry;

	cpyarry = ft_sort(arry, size);
	ps->midval = cpyarry[size / 2];
	ps->minval = cpyarry[0];
	ps->maxval = cpyarry[size -1];
	free(cpyarry);
}

void	ft_crate_index(int size, t_push_swap *ps)
{
	int	i;
	int	j;
	int	k;

	ps->indexbuf = malloc(sizeof(int) * size);
	if (ps->indexbuf == NULL)
		return ;
	i = -1;
	while (++i < size)
	{
		j = -1;
		k = 0;
		while (++j < size)
			if (ps->stack_a[i] > ps->stack_a[j])
				k++;
		ps->indexbuf[i] = k;
	}
	while (size--)
		ps->stack_a[size] = ps->indexbuf[size];
}

void	ft_rev_rotate_rotate(t_push_swap *ps)
{
	int	tmp_a;
	int	tmp_b;
	int	i;

	i = ps->size_a;
	tmp_a = ps->stack_a[ps->size_a -1];
	while (--i > 0)
		ps->stack_a[i] = ps->stack_a[i -1];
	ps->stack_a[0] = tmp_a;
	i = ps->size_b;
	tmp_b = ps->stack_b[ps->size_b -1];
	while (--i > 0)
		ps->stack_b[i] = ps->stack_b[i -1];
	ps->stack_b[0] = tmp_b;
	write(1, "rrr\n", 4);
}
