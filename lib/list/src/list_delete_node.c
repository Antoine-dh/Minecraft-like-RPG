/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

static void free_node(list_t *node, void (*del)())
{
	if (del == NULL)
		free(node->data);
	else
		del(node->data);
	node->data = NULL;
	free(node);
}

void list_delete_node(list_t **begin, list_t *node, void (*del)())
{
	list_t *prev = node->prev;
	list_t *next = node->next;

	if (prev != NULL)
		prev->next = next;
	else
		*begin = next;
	if (next != NULL)
		next->prev = prev;
	free_node(node, del);
}
