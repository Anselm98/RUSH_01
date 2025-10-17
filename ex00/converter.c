#include "rush01.h"

char	*g_units[] = {"", "one", "two", "three", "four",
	"five", "six", "seven", "eight", "nine"};
char	*g_teens[] = {"ten", "eleven", "twelve", "thirteen",
	"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char	*g_tens[] = {"", "", "twenty", "thirty", "forty",
	"fifty", "sixty", "seventy", "eighty", "ninety"};

void	convert_hundreds(int nbr, char *result, int *first)
{
	if (nbr >= 100)
	{
		if (*first)
			ft_strcat(result, " ");
		ft_strcat(result, g_units[nbr / 100]);
		ft_strcat(result, " hundred");
		*first = 1;
		nbr %= 100;
	}
	handle_tens_units(nbr, result, first);
}

void	convert_recursive(int nbr, char *result, int *first)
{
	if (nbr >= 1000000000)
		convert_billions(nbr, result, first);
	else if (nbr >= 1000000)
		convert_millions(nbr, result, first);
	else if (nbr >= 1000)
		convert_thousands(nbr, result, first);
	else
		convert_hundreds(nbr, result, first);
}

char	*number_to_words(int nbr)
{
	char	*result;
	int		first;

	result = malloc(1000 * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	first = 0;
	if (nbr == 0)
	{
		ft_strcat(result, "zero");
		return (result);
	}
	convert_recursive(nbr, result, &first);
	return (result);
}
