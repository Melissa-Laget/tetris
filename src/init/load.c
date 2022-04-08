/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-tetris-melissa.laget
** File description:
** load
*/

#include "local.h"

bool check_filename(char *file_path)
{
    int len = 0;

    if ((len = my_strlen(file_path)) > 10 && my_strcmp(&file_path[len - 10],
        ".tetrimino") == 0) {
        if (access(file_path, R_OK) != -1) {
            return true;
        }
        return false;
    }
    return false;
}

list_t *get_file_in_dir(char *path)
{
    DIR *dirs = opendir(path);
    struct dirent *dir;
    list_t *list = NULL;
    char *file_path = NULL;

    if (dirs == NULL) {
        return NULL;
    }
    while ((dir = readdir(dirs)) != NULL) {
        file_path = my_strcat("tetriminos/", dir->d_name);
        if (check_filename(file_path) == false) {
            free(file_path);
            continue;
        }
        list = list_append(list, file_path);
    }
    closedir(dirs);
    free(dir);
    return list;
}

tetrimino_t **load_tetrimino(game_t *game)
{
    struct stat pathstat;
    char *path = "tetriminos";
    list_t *list = NULL;
    tetrimino_t **tetriminos = NULL;
    int count = 0;

    if (stat(path, &(pathstat)) < 0)
        return NULL;
    if (S_ISDIR(pathstat.st_mode) == 0)
        return NULL;
    if ((list = get_file_in_dir(path)) == NULL)
        return NULL;
    list = debug_sort(list, game);
    tetriminos = my_calloc(sizeof(tetrimino_t) * list_get_size(list) + 1, NULL);
    for (list_t *tmplist = list; tmplist != NULL; tmplist = tmplist->next) {
        tetriminos[count] = init_tetrimino((char *)tmplist->data);
        count += display_debug((char *)tmplist->data, tetriminos[count], game);
    }
    list_free(list, true);
    return tetriminos;
}
