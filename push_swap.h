#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../bonus_printf/incs/ft_printf.h"

char	**ft_split(char *str);
void	push(int *stack_a, int *stack_b, int size_a, int size_b);
void	rotate(int *stack, int total);
void	reverse_rotate(int *stack, int total);
int		is_sorted(int *stack, int total, int b_elems);

#endif
