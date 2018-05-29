/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <game.h>
#include "saving.h"
#include "spawner.h"

spawner_t *init_spawner(const char *data)
{
	char **arr = my_str_split(data, ",");
	spawner_t *spawner = malloc(sizeof(spawner_t));
	int tmp;

	if (spawner == NULL || arr == NULL || my_array_len((void *)arr) != 8)
		return (NULL);
	spawner->position.x = my_getnbr(arr[0]);
	spawner->position.y = my_getnbr(arr[1]);
	spawner->position.z = my_getnbr(arr[2]);
	spawner->size.x = my_getnbr(arr[3]);
	spawner->size.y = my_getnbr(arr[4]);
	spawner->size.z = my_getnbr(arr[5]);
	tmp = my_getnbr(arr[6]);
	spawner->spawn_rate = *(float *)(&tmp);
	spawner->cooldown = spawner->spawn_rate;
	spawner->name = my_strdup(arr[7]);
	return (spawner);
}

void update_spawner(game_t *game, spawner_t *spawner)
{
	sfVector3f pos;

	spawner->cooldown -= game->dt;
	if (spawner->cooldown <= 0.0f) {
		spawner->cooldown = spawner->spawn_rate;
		pos.x = RANDF_RANGE(spawner->position.x,
			spawner->position.x + spawner->size.x);
		pos.y = RANDF_RANGE(spawner->position.y,
			spawner->position.y + spawner->size.y);
		pos.z = RANDF_RANGE(spawner->position.z,
			spawner->position.z + spawner->size.z);
		instantiate_prefab(game, spawner->name, &pos);
	}
}

list_t *load_spawners(list_t *save_list)
{
	list_t *node = list_find_node(save_list, &(save_t){.name = "spawners"},
		save_cmp_name);
	list_t *list = NULL;
	spawner_t *spawner;
	save_t *save;

	if (node == NULL)
		return (NULL);
	save = node->data;
	for (size_t i = 0 ; save->data[i] != NULL ; ++i) {
		spawner = init_spawner(save->data[i]);
		if (spawner != NULL)
			list_push(&list, spawner);
	}
	return (list);
}
