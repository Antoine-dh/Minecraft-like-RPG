/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

void list_reverse(list_t *begin)
{
	list_t *last = list_getlast(begin);
	int size = list_size(begin);

	if (last == NULL)
		return;
	for (int i = 0 ; i < size / 2 ; i++) {
		list_swap_nodes(begin, last);
		begin = begin->next;
		last = last->prev;
	}
}