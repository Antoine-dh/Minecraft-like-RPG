/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

void list_swap_nodes(list_t *a, list_t *b)
{
	void *swap = a->data;

	a->data = b->data;
	b->data = swap;
}
