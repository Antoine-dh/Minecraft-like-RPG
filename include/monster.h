/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh, lucas_ben
*/

#ifndef MY_RPG_MONSTER_H
#define MY_RPG_MONSTER_H

#include "stats.h"

typedef struct {
	entity_t entity;
	stats_t stats;
} monster_t;

#endif //MY_RPG_MONSTER_H
