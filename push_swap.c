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
	int		next;

	b_elems = 1;
	push(stack_a, stack_b, total, b_elems - 1);
	++b_elems;
	++b_elems;
	while (b_elems < total + 3)
	{
		int i = 0;
		while (i < total)
			printf("%d | ", stack_a[i++]);
		next = find(stack_a[total - b_elems], stack_a[total - b_elems - 1], stack_a[0], stack_b[b_elems - 1]);
		printf("\nNEXT: %d\n", next);
		if (next == stack_a[total - b_elems])
		{
			push(stack_a, stack_b, total, b_elems - 1);
			printf("\nPUSH: %d\n", stack_a[total - 1]);
		}
		else if (next == stack_a[total - b_elems - 1])
		{
			swap(stack_a, total);
			push(stack_a, stack_b, total, b_elems - 1);
			printf("\nSWAP: %d\n", stack_a[total - 1]);
		}
		else if (next == stack_a[0])
		{
			rotate(stack_a, total);
			push(stack_a, stack_b, total, b_elems - 1);
			printf("\nROTATE: %d\n", stack_a[total - 1]);
		}
		printf("\nb_elems = %d\n", b_elems);
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

int find(int move_a, int move_b, int move_c, int target)
{
	if (move_a < move_b && move_a < move_c && move_a > 0)
	{
		printf("move_a");
		return (move_a);
	}
	if (move_b < move_a && move_b < move_c && move_b > 0)
	{
		printf("move_b");
		return (move_b);
	}
	if (move_c < move_a && move_c < move_b && move_c > 0)
	{
		printf("move_c");
		return (move_c);
	}
	return (target);
} 

int	main(void)
{
	int stack_a[] = {4, 2, 3, 11, 6};
	int stack_b[5];

	int i = 0;
	while (i < 5)
		printf("%d   ", stack_a[i++]);
	printf("\n");
	i = 0;
	while (i < 1)
		printf("%d   ", stack_b[i++]);
	printf("\n");
	dance(stack_a, stack_b, 5);
	//push(stack_a, stack_b, 5, 0);
	printf("\n");
	i = 0;
	while (i < 5)
		printf("%d   ", stack_a[i++]);
	printf("\n");
	i = 0;
	while (i < 5)
		printf("%d   ", stack_b[i++]);
}
