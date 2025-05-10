#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	count_words(char *str)
{
	int	i;
	int	words;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			++i;
		if (str[i])
			++words;
		while (str[i] != ' ' && str[i])
			++i;
	}
	return (words);
}

char	*make_string(char *str)
{
	int	i;
	char *new;

	i = 0;
	while (str[i] != ' ' && str[i])
		++i;
	new = malloc(i + 1);
	if (!new)
		return (new);
	i = -1;
	while (str[++i] != ' ' && str[i])		
		new[i] = str[i];
	new[i] = 0;
	return (new);
}

char	**ft_split(char *str)
{
	char	**strings;
	int		i;
	int		j;

	strings = malloc(sizeof(char *) * count_words(str) + 1);
	if (!strings)
		return (strings);
	i = 0;
	j = 0;
	while (j < count_words(str) && str[i])
	{
		while (str[i] == ' ')
			++i;
		if (str[i])
			strings[j++] = make_string(&str[i]);
		while (str[i] && str[i] != ' ')
			++i;
	}
	strings[j] = 0;
	return (strings);
}

int	main(void)
{
	char **strings = ft_split("12 11 10 9");
	int i = 0;
 	while (strings[i])
		printf("%s\n", strings[i++]);
	free(strings);
	sleep(120);
	return (0);
}
