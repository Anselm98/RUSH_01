#include "rush01.h"

extern char	*g_units[];
extern char	*g_teens[];
extern char	*g_tens[];

void	convert_recursive(int nbr, char *result, int *first);

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

void	handle_tens_units(int nbr, char *result, int *first)
{
	if (nbr >= 20)
	{
		if (*first)
			ft_strcat(result, " ");
		ft_strcat(result, g_tens[nbr / 10]);
		*first = 1;
		nbr %= 10;
	}
	else if (nbr >= 10)
	{
		if (*first)
			ft_strcat(result, " ");
		ft_strcat(result, g_teens[nbr - 10]);
		*first = 1;
		return ;
	}
	if (nbr > 0)
	{
		if (*first)
			ft_strcat(result, " ");
		ft_strcat(result, g_units[nbr]);
		*first = 1;
	}
}

void	convert_billions(int nbr, char *result, int *first)
{
	convert_recursive(nbr / 1000000000, result, first);
	ft_strcat(result, " billion");
	*first = 1;
	if (nbr % 1000000000)
		convert_recursive(nbr % 1000000000, result, first);
}

void	convert_millions(int nbr, char *result, int *first)
{
	convert_recursive(nbr / 1000000, result, first);
	ft_strcat(result, " million");
	*first = 1;
	if (nbr % 1000000)
		convert_recursive(nbr % 1000000, result, first);
}

void	convert_thousands(int nbr, char *result, int *first)
{
	convert_recursive(nbr / 1000, result, first);
	ft_strcat(result, " thousand");
	*first = 1;
	if (nbr % 1000)
		convert_recursive(nbr % 1000, result, first);
}
