/*
** EPITECH PROJECT, 2020
** Minishell
** File description:
** PSU C Year 2019
*/

static int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

int my_strcmp(char const *str1, char const *str2)
{
    int b = 0;
    int i = 0;
    int j = my_strlen(str2);

    for (; str1[i] != '\0'; i++) {
        if (str1[i] == str2[i])
            b += 1;
    }
    if (b == j && my_strlen(str1) == j)
        return (1);
    else
        return (0);
}