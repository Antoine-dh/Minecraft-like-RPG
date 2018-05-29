/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#ifndef LIBLIST_LIST_H
#define LIBLIST_LIST_H

#include <stdlib.h>

typedef struct list {
	void *data;
	struct list *next;
	struct list *prev;
} list_t;

list_t *list_create_node(void *data);
void list_delete_node(list_t **begin, list_t *node, void (*del)());
void list_free(list_t **begin, void (*del)());
void list_concat(list_t **begin1, list_t **begin2);
list_t *list_append(list_t **begin, void *data);
list_t *list_push(list_t **begin, void *data);
void *list_pop(list_t **begin);
void list_sort(list_t **begin, int (*cmp)());
list_t *list_insert(list_t *prev, void *data);
list_t *list_getlast(list_t const *begin);
list_t *list_find_node(list_t const *list, const void *data, int (*cmp)());
list_t *list_add_sorted(list_t **begin, void *data, int (*cmp)());
void list_merge(list_t **begin1, list_t *begin2, int (*cmp)());
int list_size(list_t const *begin);
int list_apply_on_nodes(list_t *, int (*f)());
int list_delete_matching_nodes(list_t **begin, void *data, int (*cmp)(),
	void (*del)());
int list_apply_on_matching_nodes(list_t *, int (*f)(),
	void *, int (*cmp)());
void list_reverse(list_t *begin);
void list_swap_nodes(list_t *a, list_t *b);

#endif //LIBLIST_LIST_H
