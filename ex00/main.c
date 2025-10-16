#include <unistd.h>
#include <stdlib.h>
#include "rush-01.h"

// Fonction atoi
int ipssi_atoi(char *str);

int main (void)
{
	int size;
	// Charger le dictionnaire
	t_dict_entry *dict = load_dictionary("numbers.dict", &size);
	if (!dict) return 1;

	char *str = "42";
	int num = ipssi_atoi(str);
	const char *word = find_word(dict, size, num);
	if (word)
	{
		write(1, word, ft_strlen((char*)word));
		write(1, "\n", 1);
	}
	else
	{
		write(1, "Nombre inconnu\n", 16);
	}
	free_dictionary(dict, size);
	return 0;
}


// Fonction pour charger le dictionnaire
struct s_dict_entry;
struct s_dict_entry* load_dictionary(char *filename);

//Fonction pour convertir le nombre en mots
void .....()

// Fonction pour libérer la mémoire du dictionnaire
void...;

// Fonction pour ecrire le nombre en mots
void...;