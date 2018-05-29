/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

list_t *list_push(list_t **begin, void *data)
{
	list_t *node = list_create_node(data);
	list_t *tmp = *begin;

	if (node == NULL)
		return (NULL);
	if (*begin != NULL) {
		tmp->prev = node;
		node->next = tmp;
	}
	*begin = node;
	return (node);
}