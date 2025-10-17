#include "rush01.h"

char	*g_units[] = {"", "one", "two", "three", "four",
	"five", "six", "seven", "eight", "nine"};
char	*g_teens[] = {"ten", "eleven", "twelve", "thirteen",
	"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char	*g_tens[] = {"", "", "twenty", "thirty", "forty",
	"fifty", "sixty", "seventy", "eighty", "ninety"};

void	number_to_words_recursive(int nbr, int *first);

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
	handle_tens_units(nbr, first);
}

void	handle_large_numbers(int nbr, int *first, int divisor, char *word)
{
	number_to_words_recursive(nbr / divisor, first);
	write_str(word);
	*first = 1;
	if (nbr % divisor)
		number_to_words_recursive(nbr % divisor, first);
}

void	number_to_words_recursive(int nbr, int *first)
{
	if (nbr >= 1000000000)
	{
		handle_large_numbers(nbr, first, 1000000000, " billion");
		return ;
	}
	if (nbr >= 1000000)
	{
		handle_large_numbers(nbr, first, 1000000, " million");
		return ;
	}
	if (nbr >= 1000)
	{
		handle_large_numbers(nbr, first, 1000, " thousand");
		return ;
	}
	convert_hundreds(nbr, first);
}

void	number_to_words(int nbr)
{
	int	first;

	first = 0;
	if (nbr == 0)
	{
		write_str("zero");
		return ;
	}
	number_to_words_recursive(nbr, &first);
}
