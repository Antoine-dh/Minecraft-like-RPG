/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <dirent.h>
#include "game.h"

void my_perror(const char *name, const char *error)
{
	if (name) {
		my_putstr_err(name);
		my_putstr_err(": ");
	}
	my_putstr_err(error);
	my_putstr_err(".\n");
}

list_t *load_all_from_dir(const char *path, void *(*loader)(const char *))
{
	DIR *dirp = opendir(path);
	struct dirent *file = NULL;
	char *newpath;
	list_t *list = NULL;
	void *data;

	if (dirp == NULL)
		return (my_perror(path, "Could not load resource"), NULL);
	while ((file = readdir(dirp)) != NULL) {
		if (file->d_name[0] == '.' ||
			(file->d_type != DT_REG && file->d_type != DT_DIR))
			continue;
		newpath = my_strcat_dup(my_strcat_dup(my_strdup(path), ""),
			file->d_name);
		if (newpath != NULL && (data = loader(newpath)) != NULL)
			list_push(&list, data);
		free(newpath);
	}
	closedir(dirp);
	return (list);
}

int load_resources(game_t *game)
{
	char *directory = my_strcat_dup(my_strdup(NPC_DIR), game->map->name);
	char *npc_dir = my_strcat_dup(directory, "/");

	game->npc = load_all_from_dir(npc_dir, (void *)load_npc);
	game->sounds = load_all_from_dir(SOUNDS_DIR, (void *)load_sound);
	game->models = load_all_from_dir(MODELS_DIR, (void *)load_animation);
	game->textures = load_all_from_dir(TEXTURES_DIR, (void *)load_texture);
	game->prefabs = load_all_from_dir(PREFABS_DIR, (void *)load_prefab);
	free(npc_dir);
	return (TRUE);
}
