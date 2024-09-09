/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Day04 C Pool 2019
*/

#include "my_rpg.h"

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int h = 0;
    while (str[h] != '\0')
    {
        my_putchar(str[h]);
        h = h + 1;
    }
    return (0);
}