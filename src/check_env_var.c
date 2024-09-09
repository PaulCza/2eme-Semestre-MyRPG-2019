/*
** EPITECH PROJECT, 2020
** MUL - My rpg
** File description:
** Check env var
*/

#include "my_rpg.h"

int can_be_open(char const *envp[])
{
    for (int i = 0; envp[i] != NULL; i++) {
        if (my_strncmp(envp[i], "DISPLAY", 7) == 0)
            return 1;
    }
    return 0;
}