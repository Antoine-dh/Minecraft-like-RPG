/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_STATS_H
#define MY_RPG_STATS_H

typedef enum {
	ARCHER,
	MAGE,
	KNIGHT
} class_t;

typedef struct stats {
	int hp;
	int attack;
	int defense;
	float dmg_multiplier;
	float speed;
} stats_t;

#endif //MY_RPG_STATS_H
