/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget [WSL: Manjaro]
** File description:
** check_flags
*/

#include "local.h"

static const struct option long_options[] = {
    {"level", required_argument, NULL, 'L'},
    {"key-left", required_argument, NULL, 'l'},
    {"key-right", required_argument, NULL, 'r'},
    {"key-turn", required_argument, NULL, 't'},
    {"key-drop", required_argument, NULL, 'd'},
    {"key-quit", required_argument, NULL, 'q'},
    {"key-pause", required_argument, NULL, 'p'},
    {"key-next", required_argument, NULL, 'n'},
    {"map-size", required_argument, NULL, '\t'},
    {"without-next", no_argument, NULL, 'w'},
    {"debug", no_argument, NULL, 'D'},
    {"help", no_argument, NULL, 'h'},
    {NULL, 0, NULL, 0}
};

static void get_int(void *flags_tabl[], int i)
{
    int tmp = my_getnbr(optarg);

    if (tmp == 0) {
        if (str_with_str(optarg, "-+0") == 0) {
            *(int *)flags_tabl[i] = -1;
            return;
        }
    }
    *(int *)flags_tabl[i] = tmp;
}

static void get_bool(void *flags_tabl[], int i)
{
    *(bool *)flags_tabl[i] = true;
}

static void get_vector(void *flags_tabl[], int i)
{
    char **vector = NULL;

    vector = str_to_array(optarg, ",");
    if (vector == NULL)
        return;
    if (vector[0] == NULL || vector[1] == NULL || vector[2] != NULL)
        return;
    (*(vect_t *)flags_tabl[i]).y = my_getnbr(vector[0]);
    (*(vect_t *)flags_tabl[i]).x = my_getnbr(vector[1]);
    free_arr((void **)vector);
    return;
}

void get_flag(int opt, void *flags_tabl[])
{
    char flag_char[] = "Llrtdqpn\twDh";
    int nb_flags = 12;
    void (*flags_func[])(void *flags_tabl[], int i) = {
        &get_int, &get_int, &get_int, &get_int, &get_int, &get_int, &get_int,
        &get_int, &get_vector, &get_bool, &get_bool, &get_bool
    };

    for (int i = 0; i < nb_flags; i++) {
        if (opt == flag_char[i]) {
            flags_func[i](flags_tabl, i);
        }
    }
}

bool check_flags(int argc, char **argv, flags_t *flags)
{
    int opt = 0;
    int option_index = 0;
    void *flags_tabl[] = {
        &flags->level, &flags->key_left, &flags->key_right, &flags->key_turn,
        &flags->key_drop, &flags->key_quit, &flags->key_pause, &flags->key_next,
        &flags->map_size, &flags->without_next, &flags->debug, &flags->help
    };

    while ((opt = getopt_long(argc, argv, "L:l:r:t:d:q:p:n:wD\th", long_options,
        &option_index)) != -1) {
        get_flag(opt, flags_tabl);
    }
    if (check_nb(flags) == false)
        return false;
    if (flags->help == true)
        check_help(argv);
    return true;
}
