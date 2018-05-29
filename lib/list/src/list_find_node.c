/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

list_t *list_find_node(list_t const *list, const void *data, int (*cmp)())
{
	for (list_t *tmp = (list_t *)list ; tmp != NULL ; tmp = tmp->next) {
		if (cmp(data, tmp->data) == 0)
			return (tmp);
	}
	return (NULL);
}
