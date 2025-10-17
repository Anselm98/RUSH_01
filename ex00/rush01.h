#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

int		ipssi_atoi(char *str);
int		is_valid_number(char *str);
char	*number_to_words(int nbr);
int		ft_strlen(char *str);
void	ft_strcat(char *dest, char *src);
void	handle_tens_units(int nbr, char *result, int *first);
void	convert_billions(int nbr, char *result, int *first);
void	convert_millions(int nbr, char *result, int *first);
void	convert_thousands(int nbr, char *result, int *first);

#endif
