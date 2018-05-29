/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

list_t *list_add_sorted(list_t **begin, void *data, int (*cmp)())
{
	if (*begin == NULL || cmp(data, (*begin)->data) <= 0)
		return (list_push(begin, data));
	for (list_t *tmp = (*begin)->next ; tmp != NULL ; tmp = tmp->next)
		if (cmp(data, tmp->data) <= 0)
			return (list_insert(tmp->prev, data));
	return (list_append(begin, data));
}
