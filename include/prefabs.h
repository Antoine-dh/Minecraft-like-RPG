/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_PREFABS_H
#define MY_RPG_PREFABS_H

#include <SFML/Graphics.h>

typedef struct prefab {
	char *name;
	char *model;
	char *texture;
	char *sound;
	sfVector3f scale;
	int life;
} prefab_t;

static const prefab_t NPC_PREFAB = {
	name: "creeper",
	model: "creeper",
	texture: "creeper",
	scale: (sfVector3f){1.0f, 1.0f, 1.0f},
	life: 100,
};

prefab_t *load_prefab(const char *path);
void free_prefab(prefab_t *prefab);

#endif //MY_RPG_PREFABS_H
