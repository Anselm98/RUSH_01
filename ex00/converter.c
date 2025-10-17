#include "rush-01.h"

char *g_units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *g_teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *g_tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void	write_str(char *str)
{
	write(1, str, ft_strlen(str));
}

void	convert_hundreds(int nbr, int *first)
{
	if (nbr >= 100)
	{
		if (*first)
			write(1, " ", 1);
		write_str(g_units[nbr / 100]);
		write_str(" hundred");
		*first = 1;
		nbr %= 100;
	}
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

void	number_to_words_recursive(int nbr, int *first)
{
	if (nbr >= 1000000000)
	{
		number_to_words_recursive(nbr / 1000000000, first);
		write_str(" billion");
		*first = 1;
		if (nbr % 1000000000)
			number_to_words_recursive(nbr % 1000000000, first);
		return ;
	}
	if (nbr >= 1000000)
	{
		number_to_words_recursive(nbr / 1000000, first);
		write_str(" million");
		*first = 1;
		if (nbr % 1000000)
			number_to_words_recursive(nbr % 1000000, first);
		return ;
	}
	if (nbr >= 1000)
	{
		number_to_words_recursive(nbr / 1000, first);
		write_str(" thousand");
		*first = 1;
		if (nbr % 1000)
			number_to_words_recursive(nbr % 1000, first);
		return ;
	}
	convert_hundreds(nbr, first);
}

void	number_to_words(int nbr)
{
	int first;

	first = 0;
	if (nbr == 0)
	{
		write_str("zero");
		return ;
	}
	number_to_words_recursive(nbr, &first);
}
