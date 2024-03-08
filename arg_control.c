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

void	ft_arg_write(char **argv, t_push_swap *ps)
{
	if (ps->ac == 2)
	{
		ps->data = ft_split(argv[1], ' ');
		if (!ps->data[1])
		{
			ft_free_data(ps);
			free(ps);
			exit(0);
		}
	}
	else if (ps->ac > 2)
		ps->data = argv + 1;
	ft_data_check(ps);
}

void	ft_data_check(t_push_swap *ps)
{
	int	n;
	int	i;
	int	j;

	i = -1;
	while (ps->data[++i])
	{
		j = -1;
		while (ps->data[i][++j])
		{
			if (ps->data[i][j] == '-')
			{
				if (ps->data[i][j + 1] == '0')
					ft_error_1(ps);
				n = j;
				while (ps->data[i][++n])
					if (ft_isdigit(ps->data[i][n]) == 0)
						ft_error_1(ps);
			}
			else if (!(ps->data[i][j] >= '0'
				&& ps->data[i][j] <= '9'))
				ft_error_1(ps);
		}
	}
}

void	ft_data_to_int(t_push_swap *ps)
{
	int		i;
	long	tmp;

	ps->size_a = ft_double_strlen(ps->data);
	ps->buffer = malloc(sizeof(int) * ps->size_a);
	if (ps->buffer == NULL)
		ft_error_2(ps);
	i = -1;
	while (++i < ps->size_a)
	{
		tmp = ft_atoi(ps->data[i]);
		if ((tmp >= -2147483648 && tmp <= 2147483647))
			ps->buffer[i] = tmp;
		else
			ft_error_2(ps);
	}
	ft_repeat_sort_check(ps);
}

void	ft_repeat_sort_check(t_push_swap *ps)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ps->size_a)
	{
		j = i +1;
		while (j < ps->size_a)
			if (ps->buffer[i] == ps->buffer[j++])
				ft_error_2(ps);
	}
	if (ft_sort_check(ps->buffer, ps->size_a) == 1)
	{
		if (ps->ac == 2)
			ft_free_data(ps);
		free(ps->buffer);
		free(ps);
		exit(0);
	}
}

int	*ft_intcpy(int *src, int size)
{
	int	i;
	int	*dest;

	i = -1;
	dest = malloc(sizeof(int) * size);
	if (dest == NULL)
	{
		free(dest);
		return (0);
	}
	while (++i < size)
		dest[i] = src[i];
	return (dest);
}
