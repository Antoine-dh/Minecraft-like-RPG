/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

void list_concat(list_t **begin1, list_t **begin2)
{
	list_t *last = list_getlast(*begin1);

	last->next = *begin2;
	(*begin2)->prev = last;
}
