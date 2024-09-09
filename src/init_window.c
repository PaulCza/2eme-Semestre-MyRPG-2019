/*
** EPITECH PROJECT, 2020
** MUL - my_rpg
** File description:
** Initialize windows
*/

#include "my_rpg.h"

void init_window(window_t *window)
{
    window->video_mode.bitsPerPixel = 32;
    window->video_mode.height = 1080;
    window->video_mode.width = 1920;
    window->window = sfRenderWindow_create(window->video_mode, "My RPG",
    sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window->window, 60);
}