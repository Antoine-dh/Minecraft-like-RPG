/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

void *list_pop(list_t **begin)
{
	list_t *last = list_getlast(*begin);
	void *data;

	if (last == NULL)
		return (NULL);
	data = last->data;
	if (last->prev != NULL)
		last->prev->next = NULL;
	else
		*begin = NULL;
	free(last);
	return (data);
}
