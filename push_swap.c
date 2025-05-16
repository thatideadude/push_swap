#include "push_swap.h"
#include <stdio.h>

void	rotate(int *stack, int total);
void	swap(int *stack, int total);
void	push(int *stack_a, int *stack_b, int size_a, int size_b);
int		find(int move_a, int move_b, int move_c, int target);
void	send_back(int *stack_a, int *stack_b, int total);

void	dance(int *stack_a, int *stack_b, int total)
{
	int		b_elems;
	int		move_a;
	int		move_b;
	int		move_c;
	int		next;

	total--;
	b_elems = 0;
	push(stack_a, stack_b, total, b_elems);
	++b_elems;
	while (b_elems < total)
	{
		move_a = stack_a[total - b_elems] - stack_b[b_elems];
		move_b = stack_a[total - b_elems - 1] - stack_b[b_elems];
		move_c = stack_a[0] - stack_b[b_elems];
		next = find(move_a, move_b, move_c, stack_b[b_elems]);
		if (next == move_a)
			push(stack_a, stack_b, total - b_elems, b_elems);
		if (next == move_b)
			swap(stack_a, total);
		if (next == move_c)
		{
			rotate(stack_a, total);
			push(stack_a, stack_b, total - b_elems, b_elems);
		}
		else
			rotate(stack_b, b_elems);
		++b_elems;
	}
	send_back(stack_a, stack_b, b_elems);
}

void	send_back(int *stack_a, int *stack_b, int total)
{
	int	moves;

	moves = 0;
	while (moves < total)
	{
		push(stack_b, stack_a, total - moves + 1, moves);
		++moves;
	}
}

int find(int move_a, int move_b, int move_c, int target)
{
	if (move_a < move_b && move_a < move_c && move_a > 0)
		return (move_a);
	if (move_b < move_a && move_b < move_c && move_b > 0)
		return (move_b);
	if (move_c < move_a && move_c < move_b && move_c > 0)
		return (move_c);
	return (target);
} 

void	push(int *stack_a, int *stack_b, int size_a, int size_b)
{
	stack_b[size_b] = stack_a[size_a];
}

void	swap(int *stack, int total)
{
	stack[total] ^= stack[total - 1];
	stack[total - 1] ^= stack[total];
	stack[total] ^= stack[total - 1];
}

void	rotate(int *stack, int total)
{
	int i;
	int temp;

	i = 0;
	temp = stack[total];
	while (++i < total)
		stack[total] = stack[total - i];
	stack[0] = temp;
}


int	main(void)
{
	int stack_a[] = {4, 2, 3, 11, 6};
	int stack_b[5];

	dance(stack_a, stack_b, 5);
	int i = 0;
	while (i < 5)
		printf("%d   ", stack_a[i++]);
}
