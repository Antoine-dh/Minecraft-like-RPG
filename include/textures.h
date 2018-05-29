/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_TEXTURES_H
#define MY_RPG_TEXTURES_H

#include "SFML/Graphics.h"
#include "list.h"

typedef struct texture {
	sfTexture *texture;
	char *name;
} texture_t;

texture_t *load_texture(const char *name);
int texture_cmp_by_name(texture_t *a, texture_t *b);
void free_texture(texture_t *texture);
sfTexture *get_texture(char *name, list_t *list);

#endif //MY_RPG_TEXTURES_H
