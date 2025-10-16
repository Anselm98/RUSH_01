int	ipssi_isspace(char str)
{
	if (str == ' ' || str == '\n' || str == '\f')
		return (1);
	else if (str == '\v' || str == '\r' || str == '\t')
		return (1);
	else
		return (0);
}

int	ipssi_atoi(char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 0;
	result = 0;
	while (ipssi_isspace(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign += 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	if (sign % 2 == 1)
		result = -result;
	return (result);
}
