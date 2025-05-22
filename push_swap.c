#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	rotate(int *stack, int total);
void	swap(int *stack, int total);
void	push(int *stack_a, int *stack_b, int size_a, int size_b);
void	send_back(int *stack_a, int *stack_b, int total);
int		find(int *stack, int size, int target);

void	dance(int *stack_a, int *stack_b, int total)
{
	int b_elems;
	int next;
	int current;

	b_elems = 1;
	push(stack_a, stack_b, total - b_elems, 0);
	ft_printf("FIRST PUSH %d\n", stack_a[total - b_elems]);
	while (b_elems < total)
	{
		write(1, "\n", 1);
		int i = 0;
		ft_printf("S T A C K _ A:    ");
		while (i < total - b_elems)
			ft_printf("%d  ", stack_a[i++]);
		write(1, "\n", 1);
		i = 0;
		ft_printf("S T A C K _ B:    ");
		while (i < total)
			ft_printf("%d  ", stack_b[i++]);

		next = find(stack_a, total - b_elems, stack_b[b_elems - 1]);
		if (total - b_elems < 1)
			next = 0;
		if (next < stack_a[total - b_elems])
		{
			next = stack_a[next];
			while (stack_a[total - b_elems] != next)
			{
		//		ft_printf("current = %d |||| next = %d\n", current, next);
				ft_printf("...rotating\n");
				rotate(stack_a, total - b_elems + 1);
			}
		}
		else
		{
			next = stack_a[next];
			while (stack_a[total - b_elems] != next)
			{
		//		ft_printf("current = %d |||| next = %d\n", current, next);
				ft_printf("...reverse rotating\n");
				reverse_rotate(stack_a, total - b_elems + 1);
			}
		}
		ft_printf("PUSHING %d\n", stack_a[total - b_elems]);
		push(stack_a, stack_b, total - b_elems, b_elems);
		++b_elems;
	}
}

void	send_back(int *stack_a, int *stack_b, int total)
{
	int	moves;

	moves = 0;
	while (moves < total)
	{
		push(stack_b, stack_a, total - moves, moves);
		++moves;
	}
}

int find(int *stack, int size, int target)
{
	int i;
	int	temp;

	i = 1;
	temp = 0;
	while (i < size)
	{
		if (stack[i] - target > 0 && stack[i] - target < stack[temp] - target)
		{	
			ft_printf("-----------------------------------------------------");
			temp = i;
		}
		++i;
	}
	ft_printf("\nINPUT = %d", target);
	ft_printf("\nRETURNING %d at position %d of %d\n", stack[temp], temp, size);
	return (temp);
} 

int	main(void)
{
	int size = 10;
	int stack_a[] = {31, 2, 223, -111, 222, -6, 22, -9, 23, -8};
	int stack_b[10] = {0, 0, 0, 0, 0, 0};

	int i = 0;
	while (i < size)
		ft_printf("%d   ", stack_a[i++]);
	ft_printf("\n");
	i = 0;
	while (i < 1)
		ft_printf("%d   ", stack_b[i++]);
	ft_printf("\n");
	dance(stack_a, stack_b, size);
	ft_printf("\n");
	i = 0;
	while (i < size)
		ft_printf("%d   ", stack_a[i++]);
	ft_printf("\n");
	i = 0;
	while (i < size)
		ft_printf("%d   ", stack_b[i++]);
}
