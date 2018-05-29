/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <fcntl.h>
#include "game.h"
#include "spawner.h"

static void generate_tile_uv(sfTexture *tileset, sfVector2f uv[MAX_TILES][4])
{
	const uint sqrtile = (uint)sqrtf(MAX_TILES);
	const sfVector2u size = sfTexture_getSize(tileset);
	const sfVector2u tile_size = {size.x / sqrtile, size.y / sqrtile};

	for (int i = 0 ; i < MAX_TILES ; ++i)
		for (int j = 0 ; j < 4 ; ++j)
			uv[i][j] = uv_sheet_split(tileset, &CUBE_UV[j],
				&tile_size, i);
}

vector3i_t load_vector(list_t *save, const char *name)
{
	vector3i_t vector;

	vector.x = my_getnbr(save_get_data(save, name, 0));
	vector.y = my_getnbr(save_get_data(save, name, 1));
	vector.z = my_getnbr(save_get_data(save, name, 2));
	return (vector);
}

static bool_t load_blocks(map_t *map, list_t *save)
{
	char **arr = NULL;

	for (size_t i = 0 ; save_get_data(save, "map", i) != NULL ; ++i) {
		arr = my_str_split(save_get_data(save, "map", i), ",");
		if (arr == NULL || my_array_len((void **)arr) != 4)
			continue;
		if (!CONTAINS(my_getnbr(arr[2]), 0, map->size.z - 1) ||
			!CONTAINS(my_getnbr(arr[1]), 0, map->size.y - 1) ||
			!CONTAINS(my_getnbr(arr[0]), 0, map->size.x - 1))
			continue;
		block_set_id(&map->blocks[my_getnbr(arr[2])][my_getnbr(
			arr[1])][my_getnbr(arr[0])], my_getnbr(arr[3]));
		my_free_array((void **)arr);
	}
	return (arr ? TRUE : FALSE);
}

static map_t *map_sub_load(map_t *map, list_t *save)
{
	char *tmp;

	tmp = my_strcat_dup(my_strdup(TEXTURES_DIR),
		save_get_data(save, "skybox", 0));
	map->skybox = sfTexture_createFromFile(tmp ? tmp : "", NULL);
	free(tmp);
	tmp = my_strcat_dup(my_strdup(MUSIC_DIR),
		save_get_data(save, "music", 0));
	map->music = sfMusic_createFromFile(tmp ? tmp : "");
	free(tmp);
	if (map->tileset != NULL)
		generate_tile_uv(map->tileset, map->uv);
	if (map->music != NULL) {
		sfMusic_play(map->music);
		sfMusic_setLoop(map->music, sfTrue);
	}
	if (!load_blocks(map, save))
		return (NULL);
	load_teleporters(map, save);
	list_free(&save, save_free);
	return (map);
}

map_t *map_load(const char *file)
{
	list_t *save = save_load(file);
	map_t *map = NULL;
	vector3i_t vector =
		save ? load_vector(save, "size") : (vector3i_t){0, 0, 0};
	int fd = open(file, O_RDONLY);
	char *tmp;

	if (fd == -1 || save == NULL)
		return (NULL);
	map = map_create(&vector);
	if (map == NULL)
		return (NULL);
	tmp = my_strcat_dup(my_strdup(TEXTURES_DIR),
		save_get_data(save, "tileset", 0));
	map->tileset = sfTexture_createFromFile(tmp ? tmp : "", NULL);
	free(tmp);
	map->spawners = load_spawners(save);
	return (map_sub_load(map, save));
}
