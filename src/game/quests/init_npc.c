/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"

char **array_dup(char **array)
{
	size_t len = my_array_len((void *)array);
	char **new_array = malloc(sizeof(char *) * len + 1);
	int i = 0;

	while (array[i]) {
		new_array[i] = my_strdup(array[i]);
		i++;
	}
	new_array[len] = NULL;
	return (new_array);
}

npc_t *sub_load_npc(save_t *save, npc_t *npc)
{
	if (my_strcmp(save->name, "dialog") == 0) {
		npc->dialog = array_dup(save->data);
	}
	if (my_strcmp(save->name, "position") == 0) {
		npc->pos.x = (float)my_getnbr(save->data[0]);
		npc->pos.y = (float)my_getnbr(save->data[1]);
		npc->pos.z = (float)my_getnbr(save->data[2]);
	}
	return (npc);
}

void *load_npc(const char *path)
{
	npc_t *npc = malloc(sizeof(npc_t));
	list_t *list = save_load(path);
	save_t *save;

	memset(npc, 0, sizeof(npc_t));
	for (list_t *tmp = list ; tmp ; tmp = tmp->next) {
		save = (save_t *)tmp->data;
		if (my_strcmp(save->name, "name") == 0)
			npc->name = my_strdup(save->data[0]);
		if (my_strcmp(save->name, "quest_id") == 0)
			npc->quest_id = my_getnbr(save->data[0]);
		npc = sub_load_npc(save, npc);
	}
	npc->texture = sfTexture_createFromFile(TEXTURES_DIR"/villager.png",
		NULL);
	npc->model = load_animation(MODELS_DIR"/villager");
	npc->rotation = (sfVector3f){0, 0, 0};
	npc->scale = (sfVector3f){1, 1, 1};
	return (npc);
}
