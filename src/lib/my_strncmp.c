/*
** EPITECH PROJECT, 2020
** My library
** File description:
** my_strncmp
*/

#include "my_rpg.h"

int my_strncmp(char const *src, char const *str, int n)
{
    for (int i = 0; i < n && (src[i] != '\0' || str[i] != '\0'); i++) {
        if (src[i] != str[i])
            return src[i] - str[i];
    }
    return 0;
}