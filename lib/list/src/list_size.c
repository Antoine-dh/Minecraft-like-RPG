/*
** EPITECH PROJECT, 2017
** liblist
** File description:
** Created by antoine_dh,
*/

#include "list.h"

int list_size(list_t const *begin)
{
	for (int i = 0 ; ; i++) {
		if (begin == NULL)
			return (i);
		begin = begin->next;
	}
}
