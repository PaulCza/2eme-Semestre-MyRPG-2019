/*
** EPITECH PROJECT, 2020
** MUL - my_rpg
** File description:
** Manage button
*/

#include <stdlib.h>
#include "my_rpg.h"

void click_event(window_t *window, button_t **buttons)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->window);
    sfIntRect rect;
    sfVector2f sprite_pos;
    sfVector2f scaling;

    for (int i = 0; buttons[i] != NULL; i++) {
        rect = sfSprite_getTextureRect(buttons[i]->sprite);
        sprite_pos = buttons[i]->position;
        scaling = sfSprite_getScale(buttons[i]->sprite);
        if (mouse_pos.x >= sprite_pos.x &&
        mouse_pos.x <= (sprite_pos.x + rect.width) &&
        mouse_pos.y >= sprite_pos.y &&
        mouse_pos.y <= (sprite_pos.y + rect.height))
            buttons[i]->on_click(window);
    }
}

button_t *create_button(char const *texture_path, sfVector2f position,
void *on_click(window_t *))
{
    button_t *button = malloc(sizeof(button_t));

    button->texture = sfTexture_createFromFile(texture_path, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setPosition(button->sprite, position);
    button->on_click = &(*on_click);
    return button;
}