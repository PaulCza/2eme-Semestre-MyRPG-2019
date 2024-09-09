/*
** EPITECH PROJECT, 2020
** My_rpg
** File description:
** .h for my_rpg
*/

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 84
#endif

#ifndef MY_RPG
#define MY_RPG

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <unistd.h>
#include <stdio.h>

int my_strcmp(char const *str1, char const *str2);
void destroy_sprite(sfTexture *text, sfSprite *sprite);
int my_putstr(char const *str);

typedef struct {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode video_mode;
} window_t;

struct main_menu_s
{
    sfTexture *back_texture;
    sfSprite *back_sprite;
    sfMusic *music;
};

typedef struct button_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    void (*on_click)(window_t*);
} button_t;

void button_gestion(struct main_menu_s menu, sfVector2i mouse);
void display_button_play(struct main_menu_s *menu);
void display_button_quit(struct main_menu_s menu);
void destroy_menu(struct main_menu_s menu);
void init_window(window_t *window);
int can_be_open(char const *envp[]);
void main_menu(window_t *window);
button_t *create_button(char const *texture_path, sfVector2f position,
void *on_click(window_t*));
void click_event(window_t *window, button_t **buttons);
int my_strncmp(char const *src, char const *str, int n);

#endif