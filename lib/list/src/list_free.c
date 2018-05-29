/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

void list_free(list_t **begin, void (*del)())
{
	while (*begin != NULL)
		list_delete_node(begin, *begin, del);
}
