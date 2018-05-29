/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

int list_apply_on_nodes(list_t *list, int (*f)())
{
	int result = 0;

	while (list != NULL) {
		result += f(list->data);
		list = list->next;
	}
	return (result);
}
