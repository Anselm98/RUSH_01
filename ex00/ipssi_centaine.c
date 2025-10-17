char	*ipssi_centaine(int nbr)
{
	char unit[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char ten[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	char teen[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *result;
	
	if (nbr < 0 || nbr > 999)
		return (NULL);

	if (result == NULL)
		return (NULL);
	result[0] = '\0';

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
	return (result);
}