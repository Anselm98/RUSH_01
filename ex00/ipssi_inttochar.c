char* ipssi_dictionary(int nbr)
{

	if nbr == 0
		return ("0");
	
	if nbr < 0
		return (NULL);

	char unit[10][6] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char ten[10][7] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	char teen[10][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

	char *result = malloc(100 * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	ipssi_inttochar(nbr, "billion");
	
}

	
char *ipssi_inttochar(int nbr, char unit)
{	
	if (nbr >= 1000000000)
	{
		strcat(result, unit[nbr / 1000000000]);
		strcat(result, " billion ");
		nbr = nbr % 1000000000;
	}
	if (nbr >= 1000000)
	{
		strcat(result, unit[nbr / 1000000]);
		strcat(result, " million ");
		nbr = nbr % 1000000;
	}
	if (nbr >= 1000)
	{
		strcat(result, unit[nbr / 1000]);
		strcat(result, " thousand ");
		nbr = nbr % 1000;
	}
	if (nbr >= 100)
	{
		strcat(result, unit[nbr / 100]);
		strcat(result, " hundred ");
		nbr = nbr % 100;
	}
	if (nbr >= 20)
	{
		strcat(result, ten[nbr / 10]);
		strcat(result, " ");
		nbr = nbr % 10;
	}
	else if (nbr >= 10)
	{
		strcat(result, teen[nbr - 10]);
		strcat(result, " ");
		nbr = 0;
	}
	if (nbr > 0)
	{
		strcat(result, unit[nbr]);
		strcat(result, " ");
	}
	
}