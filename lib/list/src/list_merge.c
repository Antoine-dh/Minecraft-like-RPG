/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

void list_merge(list_t **begin1, list_t *begin2, int (*cmp)())
{
	list_concat(begin1, &begin2);
	list_sort(begin1, cmp);
}
