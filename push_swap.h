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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_push_swap
{
	int			*stack_a;
	int			*stack_b;
	int			*indexbuf;
	int			ac;
	int			size_a;
	int			size_b;
	int			*buffer;
	int			midval;
	int			minval;
	int			maxval;
	char		**data;
}	t_push_swap;

void	ft_arg_write(char **argv, t_push_swap *ps);
void	ft_repeat_sort_check(t_push_swap *ps);
void	ft_data_to_int(t_push_swap *ps);
void	ft_data_check(t_push_swap *ps);
int		*ft_intcpy(int *src, int size);
int		ft_double_strlen(char **str);
void	ft_free_data(t_push_swap *ps);
void	ft_full_free(t_push_swap *ps);
void	ft_memory(t_push_swap *ps);
void	ft_error_0(t_push_swap *ps);
void	ft_error_1(t_push_swap *ps);
void	ft_error_2(t_push_swap *ps);
void	ft_error_3(t_push_swap *ps);
void	ft_swap_a(t_push_swap *ps);
void	ft_swap_b(t_push_swap *ps);
void	ft_swap_swap(t_push_swap *ps);
void	ft_push_a(t_push_swap *ps);
void	ft_push_b(t_push_swap *ps);
void	ft_rotate_a(t_push_swap *ps);
void	ft_rotate_b(t_push_swap *ps);
void	ft_rotate_rotate(t_push_swap *ps);
void	ft_rev_rotate_a(t_push_swap *ps);
void	ft_rev_rotate_b(t_push_swap *ps);
void	ft_rev_rotate_rotate(t_push_swap *ps);
int		*ft_sort(int *arry, int size);
void	ft_max_min_mid_val(int *arry, int size, t_push_swap *ps);
int		ft_sort_check(int *arry, int size);
void	ft_sort_three(int *arry, int size, t_push_swap *ps);
void	ft_sort_five(t_push_swap *ps);
void	ft_crate_index(int size, t_push_swap *ps);
void	ft_a_to_b(t_push_swap *ps);
void	ft_b_to_a(int size_b, int maxbit, int index, t_push_swap *ps);
void	ft_sort_handler(t_push_swap *ps);
void	ft_assigment_a(t_push_swap *ps);
int		ft_bit_len(int nb);

#endif
