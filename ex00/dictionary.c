#include "rush-01.h"


// Calcul la longueur de la chaine
static int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// Lit une ligne et extrait le nombre et le mot
static int parse_line(char *line, int *number, char **word)
{
	int i = 0;
	*number = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		*number = *number * 10 + (line[i] - '0');
		i++;
	}
	while (line[i] == ' ' || line[i] == ':')
		i++;
	int start = i;
	while (line[i] && line[i] != '\n')
		i++;
	int len = i - start;
	*word = (char*)malloc(len + 1);
	if (!*word) return 0;
	for (int j = 0; j < len; j++)
		(*word)[j] = line[start + j];
	(*word)[len] = '\0';
	return 1;
}

// Charge le dictionnaire depuis le fichier
// Retourne un tableau de t_dict_entry et la taille dans size
#include <fcntl.h>
#include <string.h>
t_dict_entry* load_dictionary(const char *filename, int *size)
{
	int fd = open(filename, O_RDONLY);
	if (fd < 0) return NULL;
	char buf[1024];
	int total = read(fd, buf, 1023);
	buf[total] = '\0';
	// Compte le nombre de lignes
	int lines = 0;
	for (int i = 0; buf[i]; i++)
		if (buf[i] == '\n') lines++;
	t_dict_entry *dict = malloc(sizeof(t_dict_entry) * lines);
	if (!dict) { close(fd); return NULL; }
	int idx = 0;
	char *line = strtok(buf, "\n");
	while (line && idx < lines)
	{
		int number;
		char *word;
		if (parse_line(line, &number, &word))
		{
			dict[idx].number = number;
			dict[idx].word = word;
			idx++;
		}
		line = strtok(NULL, "\n");
	}
	close(fd);
	*size = idx;
	return dict;
}

// Cherche le mot correspondant au nombre
const char* find_word(t_dict_entry *dict, int size, int number)
{
	for (int i = 0; i < size; i++)
		if (dict[i].number == number)
			return dict[i].word;
	return NULL;
}

// Libère la mémoire du dictionnaire
void free_dictionary(t_dict_entry *dict, int size)
{
	for (int i = 0; i < size; i++)
		free(dict[i].word);
	free(dict);
}

void ipssi_dictionary(void)
{
	int size;
	t_dict_entry *dict = load_dictionary("numbers.dict", &size);
	if (!dict) return;
	int test_number = 42;
	const char *word = find_word(dict, size, test_number);
	if (word)
		write(1, word, ft_strlen((char*)word));
	free_dictionary(dict, size);
}