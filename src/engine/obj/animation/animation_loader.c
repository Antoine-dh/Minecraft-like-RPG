/*
** EPITECH PROJECT, 2018
** animation_loader
** File description:
** Created by lucas_ben,
*/

#include <dirent.h>
#include <model.h>
#include "game.h"

list_t *demerge_frames(list_t *reference, list_t *compressed)
{
	int i = 0;
	int line_id = 0;
	list_t *demerge = NULL;

	while (reference != NULL) {
		line_id = compressed ? my_getnbr((char *)compressed->data) : -1;
		if (line_id == i && compressed) {
			list_append(&demerge, my_strdup(
				&((char *)(compressed->data))[my_numlen(i, 10) +
					1]));
			compressed = compressed->next;
		} else
			list_append(&demerge, my_strdup(reference->data));
		i++;
		reference = reference->next;
	}
	return (demerge);
}

model_t *decompress_frame(char *path, list_t *reference, list_t *compressed)
{
	FILE *file = NULL;
	char *reference_path = get_full_path(my_strdup(path),
		(char *)reference->data);
	char *compressed_path = get_full_path(my_strdup(path),
		(char *)compressed->data);

	if (reference_path == NULL || compressed_path == NULL)
		return (NULL);
	file = fopen(compressed_path, "r");
	if (file == NULL)
		return (NULL);
	free(compressed->data);
	compressed->data = file_to_list(file);
	fclose(file);
	if (compressed->data != NULL)
		compressed->data = demerge_frames(reference->data,
			compressed->data);
	free(reference_path);
	free(compressed_path);
	raw_model_t *raw_model = get_raw_model(compressed->data);
	return (raw_model == NULL ? NULL : get_model_from_raw(raw_model));
}

list_t *get_animation_frames(char *path)
{
	DIR *directory;
	struct dirent *entry;
	list_t *frames = NULL;

	directory = opendir(path);
	if (directory == NULL)
		return (NULL);
	while ((entry = readdir(directory)) != NULL) {
		if (file_extension(entry->d_name, MODEL_FORMAT))
			list_add_sorted(&frames, my_strdup(entry->d_name),
				my_strcmp);
	}
	closedir(directory);
	return (frames);
}

int load_first_frame(animodel_t *animation, char *path, list_t *frames)
{
	FILE *file;
	char *pathname = get_full_path(my_strdup(path), (char *)frames->data);

	if (pathname == NULL)
		return (FALSE);
	file = fopen(pathname, "r");
	animation->frames[0] = load_model(pathname);
	free(pathname);
	if (animation->frames[0] == NULL)
		return (FALSE);
	free(frames->data);
	frames->data = file_to_list(file);
	fclose(file);
	return (frames->data ? TRUE : FALSE);
}

animodel_t *load_animation(char *path)
{
	int frame_index = 0;
	list_t *frames = get_animation_frames(path);
	animodel_t *animation = malloc(sizeof(animodel_t));

	if (animation == NULL || frames == NULL)
		return (NULL);
	animation->name = get_filename(path);
	animation->frames_count = list_size(frames);
	animation->frames = malloc(
		sizeof(model_t *) * (animation->frames_count + 1));
	if (animation->frames == NULL || animation->name == NULL ||
		!load_first_frame(animation, path, frames))
		return (NULL);
	frames = frames->next;
	while (frames != NULL) {
		animation->frames[++frame_index] = decompress_frame(path,
			frames->prev, frames);
		if (animation->frames[frame_index] == NULL)
			return (NULL);
		frames = frames->next;
	}
	return (animation);
}
