/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "entity.h"
#include "game.h"

void set_entity(entity_t *entity, const prefab_t *prefab, const sfVector3f *pos)
{
	entity->position = *pos;
	entity->rotation = (sfVector3f){0, rand() % 360, 0};
	entity->scale = prefab->scale;
	entity->sound = prefab->sound;
	entity->health_point = prefab->life;
}

entity_t *instantiate_entity(game_t *game, const prefab_t *prefab,
	const sfVector3f *pos)
{
	entity_t *entity;
	const texture_t tmp_texture = {.name = prefab->texture};
	list_t *node = list_find_node(game->textures, &tmp_texture,
		texture_cmp_by_name);
	texture_t *texture = node ? node->data : NULL;
	const animodel_t tmp_model = {.name = prefab->model};
	animodel_t *model;

	node = list_find_node(game->models, &tmp_model, animodel_cmp_by_name);
	if (node == NULL || texture == NULL)
		return (NULL);
	model = node->data;
	entity = entity_create(model, texture->texture, &prefab->scale);
	if (entity != NULL) {
		set_entity(entity, prefab, pos);
		list_push(&game->entities, entity);
	}
	particle_sys_instantiate(&game->particle_systems, &PARTICLE_SPAWN, pos);
	return (entity);
}

int prefab_cmp(prefab_t *a, prefab_t *b)
{
	if (a->name == NULL || b->name == NULL)
		return ((int)(a - b));
	return (my_strcmp(a->name, b->name));
}

entity_t *instantiate_prefab(game_t *game, const char *name,
	const sfVector3f *pos)
{
	list_t *node;
	const prefab_t tmp = {.name = (char *)name};

	node = list_find_node(game->prefabs, &tmp, prefab_cmp);
	if (node == NULL)
		return (NULL);
	return (instantiate_entity(game, node->data, pos));
}
