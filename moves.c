void	push(int *stack_a, int *stack_b, int size_a, int size_b)
{
	stack_b[size_b] = stack_a[size_a - 1];
}

void	swap(int *stack, int total)
{
	--total;
	stack[total] ^= stack[total - 1];
	stack[total - 1] ^= stack[total];
	stack[total] ^= stack[total - 1];
}

void	rotate(int *stack, int total)
{
	int i;
	int temp;

	i = 0;
	temp = stack[total - 1];
	while (++i < total)
		stack[total - i] = stack[total - i - 1];
	stack[0] = temp;
}

void	reverse_rotate(int *stack, int total)
{
	int i;
	int temp;

	i = -1;
	temp = stack[0];
	while (++i < total - 1)
		stack[i] = stack[i + 1];
	stack[total - 1] = temp;
}

int	is_sorted(int *stack, int total, int b_elems)
{
	int	i;

	if (b_elems != total)
		return (0);
	i = 0;
	while (++i < b_elems)
		if (stack[i - 1] > stack[i])
			return (0);
	return (1);
} 
