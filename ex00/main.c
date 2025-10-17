#include "rush01.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (0);
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	process_number(int num)
{
	char	*result;

	result = number_to_words(num);
	if (!result)
		return (1);
	write(1, result, ft_strlen(result));
	write(1, "\n", 1);
	free(result);
	return (0);
}

int	main(int argc, char **argv)
{
	int		num;

	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (1);
	}
	if (!is_valid_number(argv[1]))
	{
		write(1, "error\n", 6);
		return (1);
	}
	num = ipssi_atoi(argv[1]);
	if (num < 0)
	{
		write(1, "error\n", 6);
		return (1);
	}
	return (process_number(num));
}
