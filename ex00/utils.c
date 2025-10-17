#include "rush01.h"

extern char	*g_units[];
extern char	*g_teens[];
extern char	*g_tens[];

void	write_str(char *str)
{
	write(1, str, ft_strlen(str));
}

void	handle_tens_units(int nbr, int *first)
{
	if (nbr >= 20)
	{
		if (*first)
			write(1, " ", 1);
		write_str(g_tens[nbr / 10]);
		*first = 1;
		nbr %= 10;
	}
	else if (nbr >= 10)
	{
		if (*first)
			write(1, " ", 1);
		write_str(g_teens[nbr - 10]);
		*first = 1;
		return ;
	}
	if (nbr > 0)
	{
		if (*first)
			write(1, " ", 1);
		write_str(g_units[nbr]);
		*first = 1;
	}
}
