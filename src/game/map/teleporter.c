/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** teleporter
*/

#include "game.h"

void sub_load_teleporters(map_t *map, char **data)
{
	char **array;
	teleporter_t *teleporter;
	map->teleporters = NULL;

	for (int i = 0 ; data[i] ; i++) {
		teleporter = malloc(sizeof(teleporter_t));
		if (teleporter == NULL)
			return;
		array = my_str_split(data[i], ",");
		teleporter->position.x = my_getnbr(array[0]);
		teleporter->position.y = my_getnbr(array[1]);
		teleporter->position.z = my_getnbr(array[2]);
		teleporter->where = my_strdup(array[3]);
		list_push(&map->teleporters, teleporter);
	}
}

void load_teleporters(map_t *map, list_t *save)
{
	save_t *tmp_save;

	for (list_t *tmp = save ; tmp ; tmp = tmp->next) {
		tmp_save = (save_t *)tmp->data;
		if (my_strcmp(tmp_save->name, "teleporter") == 0)
			sub_load_teleporters(map, tmp_save->data);
		if (my_strcmp(tmp_save->name, "spawn") == 0) {
			map->spawn.x = my_getnbr(tmp_save->data[0]);
			map->spawn.y = my_getnbr(tmp_save->data[1]);
			map->spawn.z = my_getnbr(tmp_save->data[2]);
		}
		if (my_strcmp(tmp_save->name, "name") == 0)
			map->name = my_strdup(tmp_save->data[0]);
	}
}

void change_map(game_t *game, teleporter_t *teleporter)
{
	char *directory;
	char *npc_dir;

	free_map(game->map);
	game->map = map_load(teleporter->where);
	game->player->entity.position.x = (float)game->map->spawn.x;
	game->player->entity.position.y = (float)game->map->spawn.y;
	game->player->entity.position.z = (float)game->map->spawn.z;
	list_free(&game->npc, NULL);
	list_free(&game->entities, NULL);
	directory = my_strcat_dup(my_strdup(NPC_DIR), game->map->name);
	npc_dir = my_strcat_dup(directory, "/");
	game->npc = load_all_from_dir(npc_dir, (void *)load_npc);
}

void update_teleporters(game_t *game)
{
	teleporter_t *teleporter;

	for (list_t *tmp = game->map->teleporters ; tmp ; tmp = tmp->next) {
		teleporter = (teleporter_t *)tmp->data;
		if ((int)teleporter->position.x ==
			(int)game->player->entity.position.x &&
			(int)teleporter->position.z ==
				(int)game->player->entity.position.z) {
			change_map(game, teleporter);
		}
	}
}