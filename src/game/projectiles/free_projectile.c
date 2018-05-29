/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"

int is_projectile_alive(UNUSED projectile_t *a, projectile_t *b)
{
	if (b->time < 0)
		return (0);
	return (1);
}

void free_projectile(projectile_t *projectile)
{
	projectile->trails->sys_lifetime = 0;
	free(projectile);
}
