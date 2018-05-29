/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"

char *save_get_data(list_t *save, const char *name, size_t index)
{
	const save_t tmp = {.name = (char *)name};
	list_t *node = list_find_node(save, &tmp, save_cmp_name);
	save_t *data = node ? node->data : NULL;

	if (data == NULL || data->data == NULL ||
		my_array_len((void **)data->data) <= index)
		return (NULL);
	return (data->data[index]);
}

static sfVector3f load_vector_prefab(list_t *save, const char *name)
{
	float arr[3] = {0, 0, 0};
	sfVector3f vector;
	int tmp;
	char *data;

	for (size_t i = 0 ; i < 3 ; ++i) {
		data = save_get_data(save, name, i);
		if (data != NULL) {
			tmp = my_getnbr(data);
			arr[i] = *(float *)(&tmp);
		}
	}
	vector = (sfVector3f){arr[0], arr[1], arr[2]};
	return (vector);
}

void free_prefab(prefab_t *prefab)
{
	free(prefab->name);
	free(prefab->model);
	free(prefab->texture);
}

static int load_integer(list_t *save, const char *name)
{
	int i = 0;
	char *data;
	data = save_get_data(save, name, 0);
	i = my_getnbr(data);
	return (i);
}

prefab_t *load_prefab(const char *path)
{
	list_t *save = save_load(path);
	prefab_t *prefab = malloc(sizeof(prefab_t));

	if (prefab == NULL || save == NULL)
		return (NULL);
	prefab->scale = load_vector_prefab(save, "scale");
	if (!(prefab->name = my_strdup(save_get_data(save, "name", 0))) ||
		!(prefab->model = my_strdup(save_get_data(save, "model", 0))) ||
		!(prefab->texture = my_strdup(
			save_get_data(save, "texture", 0))) ||
		!(prefab->sound = my_strdup(save_get_data(save, "sound", 0))))
		return (NULL);
	prefab->life = load_integer(save, "life");
	list_free(&save, save_free);
	return (prefab);
}
