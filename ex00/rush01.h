#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

int		ipssi_atoi(char *str);
int		is_valid_number(char *str);
void	number_to_words(int nbr);
int		ft_strlen(char *str);
void	write_str(char *str);
void	handle_tens_units(int nbr, int *first);

#endif
