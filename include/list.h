/*
** EPITECH PROJECT, 2022
** structure
** File description:
** struct
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#ifndef LIST_H
    #define LIST_H

typedef struct list_s {
    void *data;
    struct list_s *next;
    struct list_s *prev;
} list_t;

bool list_is_circ(list_t *list);
list_t *list_get_end(list_t *list);
list_t *list_get_start(list_t *list);
int list_get_size(list_t *list);
list_t *list_get_elem(list_t *list, int pos);
list_t *list_transform_stdr(list_t *list);
list_t *list_transform_circ(list_t *list);
list_t *list_init(void *data);
list_t *list_init_circ(void *data);
list_t *list_create(void *data, int size);
list_t *list_create_circ(void *data, int size);
list_t *list_append(list_t *list, void *data);
list_t *proccess_list_add_circ(list_t *start, list_t *end, void *data);
list_t *list_add(list_t *list, void *data, int pos);
list_t *list_nduplicate(list_t *list, int size);
list_t *list_duplicate(list_t *list);
list_t *list_del_current(list_t *list, bool free_data);
list_t *list_del(list_t *list, int pos, bool free_data);
list_t *list_pop(list_t *list, bool free_data);
int list_free_current(list_t *elem_to_free, bool free_data);
int list_free_elem(list_t *list, int pos, bool free_data);
int list_free(list_t *list, bool free_data);

#endif
