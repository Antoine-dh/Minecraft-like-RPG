/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

static void sort_swap(list_t *a, list_t *b, int (*cmp)())
{
	if (cmp(a->data, b->data) > 0)
		list_swap_nodes(a, b);
}

void list_sort(list_t **begin, int (*cmp)())
{
	int len = list_size(*begin);

	for (int i = 0 ; i < len ; i++)
		for (list_t *j = (*begin)->next ; j != NULL ; j = j->next)
			sort_swap(j->prev, j, cmp);
}
