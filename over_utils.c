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

void	ft_memory(t_push_swap *ps)
{
	int	i;

	ps->stack_a = malloc(sizeof(int) * ps->size_a +1);
	ps->stack_b = malloc(sizeof(int) * (ps->size_a +1));
	if (ps->stack_b == NULL || ps->stack_a == NULL)
		ft_error_3(ps);
	i = -1;
	while (++i < ps->size_a)
		ps->stack_a[i] = ps->buffer[i];
}

int	ft_bit_len(int nb)
{
	int	bit_len;

	nb >>= 1;
	bit_len = 1;
	while (nb)
	{
		nb >>= 1;
		bit_len++;
	}
	return (bit_len);
}

int	ft_double_strlen(char **str)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (str[++i])
		len++;
	return (len);
}

void	ft_free_data(t_push_swap *ps)
{
	int	i;

	i = -1;
	while (ps->data[++i])
		free(ps->data[i]);
	free(ps->data);
}
