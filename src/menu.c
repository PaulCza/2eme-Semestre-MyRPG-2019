/*
** EPITECH PROJECT, 2020
** MUL - my_rpg
** File description:
** Display menu
*/

#include <stdlib.h>
#include "my_rpg.h"

static sfMusic *setup_music(void)
{
    sfMusic *music = sfMusic_createFromFile("./assets/music/title_screen.ogg");

    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return music;
}

static void quit(window_t *window)
{
    sfRenderWindow_close(window->window);
}

static void play(window_t *window)
{
    my_putstr("ahhh\n");
}

static button_t **menu_button(void)
{
    button_t **buttons = malloc(sizeof(button_t) * 3);
    sfVector2f pos = {675, 325};

    buttons[0] = create_button("./assets/picture/blueSheet.png", pos, &play);
    pos.y = 725;
    buttons[1] = create_button("./assets/picture/redSheet.png", pos, &quit);
    buttons[2] = NULL;
    sfSprite_setTextureRect(buttons[0]->sprite, (sfIntRect) {0, 0, 190, 49});
    sfSprite_setTextureRect(buttons[1]->sprite, (sfIntRect) {190, 0, 190, 49});
    sfSprite_scale(buttons[0]->sprite, (sfVector2f) {3, 3});
    sfSprite_scale(buttons[1]->sprite, (sfVector2f) {3, 3});
    return buttons;
}

void main_menu(window_t *window)
{
    sfTexture *back_text = sfTexture_createFromFile("./assets/picture/main.jpg",
    NULL);
    sfSprite *back_sprite = sfSprite_create();
    sfMusic *music = setup_music();
    button_t **buttons = menu_button();

    sfSprite_setTexture(back_sprite, back_text, sfTrue);
    while (sfRenderWindow_isOpen(window->window)) {
        sfRenderWindow_drawSprite(window->window, back_sprite, NULL);
        for (int i = 0; buttons[i] != NULL; i++)
            sfRenderWindow_drawSprite(window->window, buttons[i]->sprite, NULL);
        sfRenderWindow_display(window->window);
        if (sfRenderWindow_pollEvent(window->window, &window->event)) {
            if (window->event.type == sfEvtClosed)
                sfRenderWindow_close(window->window);
            if (window->event.type == sfEvtMouseButtonPressed)
                click_event(&(*window), buttons);
        }
    }
}