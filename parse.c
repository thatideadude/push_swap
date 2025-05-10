#include "push_swap.h"

int	is_valid_str(char *str)
{
	if (!str)
		return (0);
	if (!*str)
		return (0);
	while ((*str >= '0' && *str <= '9') || *str == ' ')
		++str;
	if (!*str)
		return (1);
	return (0);
}

long	ft_atoi(char *str)
{
	int		i;
	long	sign;
	long	sum;

	sign = 1;
	sum = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] < 13) || str[i] == ' ')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
		sum = sum * 10 + str[i] - '0';
	return (sum *= sing);
}

int	is_valid_array(int *values, int max) 
{
	int	i;

	i = -1;
	while (++i < value)
		if (values[i] > INT_MAX || values[i] < INT_MIN)
			return (0);
	return (1);
}

#include <stdio.h>

int main ()
{
	printf("%d\n", is_valid_str(""));
	printf("%d\n", is_valid_str(NULL));
}
