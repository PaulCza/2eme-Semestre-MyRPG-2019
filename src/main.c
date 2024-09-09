/*
** EPITECH PROJECT, 2020
** My_rpg
** File description:
** Main with usage
*/

#include "my_rpg.h"

static void usage(void)
{
    my_putstr("./my_rpg\nPlay an RPG\n");
}

int main(int argc, char const *argv[], char const *envp[])
{
    window_t window;

    if (argc > 1) {
        usage();
        if (my_strcmp(argv[1], "-h") == 1) {
            return EXIT_SUCCESS;
        }
        return EXIT_FAILURE;
    }
    if (!can_be_open(envp)) {
        my_putstr("You can't run this application in a TTY\n");
        return EXIT_FAILURE;
    }
    init_window(&window);
    main_menu(&window);
    return EXIT_SUCCESS;
}
