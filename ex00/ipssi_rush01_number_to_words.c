#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

char *ipssi_rush01_number_to_words(int nbr)
{

	if (nbr == 0)
		return "zero";

	if (nbr < 0)
	{
		write (1, "error", 6);
		return "\0";
	}
	if (nbr >= 1000000000)
	{
		ipssi_rush01_number_to_words(nbr / 1000000000);
		write(1, " ", 1);
		write(1, billion, 7);
		if (nbr % 1000000000)
			write(1, " ", 1);
		nbr %= 1000000000;
	}
	if (nbr >= 1000000)
	{
		ipssi_rush01_number_to_words(nbr / 1000000);
		write(1, " ", 1);
		write(1, million, 7);
		if (nbr % 1000000)
			write(1, " ", 1);
		nbr %= 1000000;
	}
	if (nbr >= 1000)
	{
		ipssi_rush01_number_to_words(nbr / 1000);
		write(1, " ", 1);
		write(1, mille, 8);
		if (nbr % 1000)
			write(1, " ", 1);
		nbr %= 1000;
	}
	if (nbr >= 100)
	{
		ipssi_rush01_number_to_words(nbr / 100);
		write(1, " ", 1);
		write(1, centaine, 7);
		if (nbr % 100)
			write(1, " ", 1);
		nbr %= 100;
	}
	if (nbr >= 20)
	{
		write(1, dizaine[nbr / 10], strlen(dizaine[nbr / 10]));
		if (nbr % 10)
			write(1, " ", 1);
		nbr %= 10;
	}
	else if (nbr >= 10)
	{
		write(1, dizaine_speciale[nbr - 10], strlen(dizaine_speciale[nbr - 10]));
		nbr = 0;
	}
	if (nbr > 0)
	{
		write(1, unite[nbr], strlen(unite[nbr]));
	}
	return "\0";
}

size_t strlen(const char *str)
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

void write_number_in_words(int nbr)
{
	ipssi_rush01_number_to_words(nbr);
	write(1, "\n", 1);
}