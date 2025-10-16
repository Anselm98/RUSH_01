#ifndef RUSH_01_H
# define RUSH_01_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// Structure dictionnaire

// Une ligne du dictionnaire
typedef struct s_dict_entry
{
    int number;
    char *word;
} t_dict_entry;

