/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

int list_apply_on_matching_nodes(list_t *list, int (*f)(),
	void *data, int (*cmp)())
{
	int result = 0;

	while (list != NULL) {
		if (cmp(data, list->data) == 0)
			result += f(list->data);
		list = list->next;
	}
	return (result);
}
