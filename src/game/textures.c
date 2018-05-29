/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "textures.h"
#include "file.h"
#include "my.h"

sfTexture *get_texture(char *name, list_t *list)
{
	sfTexture *texture = NULL;
	list_t *node;
	texture_t tmp = {.name = name};

	node = list_find_node(list, &tmp, texture_cmp_by_name);
	if (node)
		texture = ((texture_t *)(node->data))->texture;
	return (texture);
}

int texture_cmp_by_name(texture_t *a, texture_t *b)
{
	if (a->name == NULL || b->name == NULL)
		return ((int)(a->name - b->name));
	return (my_strcmp(a->name, b->name));
}

texture_t *load_texture(const char *path)
{
	texture_t *texture = malloc(sizeof(texture_t));

	if (texture == NULL)
		return (NULL);
	texture->name = get_filename(path);
	texture->texture = sfTexture_createFromFile(path, NULL);
	if (texture->texture == NULL || texture->name == NULL)
		return (NULL);
	return (texture);
}

void free_texture(texture_t *texture)
{
	free(texture->name);
	sfTexture_destroy(texture->texture);
	free(texture);
}
