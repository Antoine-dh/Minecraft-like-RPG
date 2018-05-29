/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <sound.h>
#include "sound.h"
#include "file.h"
#include "my.h"

int sound_cmp_by_name(sound_t *a, sound_t *b)
{
	if (a->name == NULL || b->name == NULL)
		return ((int)(a->name - b->name));
	return (my_strcmp(a->name, b->name));
}

sound_t *load_sound(const char *path)
{
	sound_t *sound = malloc(sizeof(sound_t));

	if (sound == NULL)
		return (NULL);
	sound->name = get_filename(path);
	sound->sound = sfSound_create();
	sound->buffer = sfSoundBuffer_createFromFile(path);
	if (sound->buffer == NULL || sound->sound == NULL ||
		sound->name == NULL)
		return (NULL);
	sfSound_setBuffer(sound->sound, sound->buffer);
	return (sound);
}

void free_sound(sound_t *sound)
{
	sfSoundBuffer_destroy(sound->buffer);
	sfSound_destroy(sound->sound);
	free(sound->name);
	free(sound);
}

void sound_play(const char *name, list_t *sounds)
{
	sound_t tmp = {.name = (char *)name};
	sfSound *sound = NULL;
	list_t *node;

	node = list_find_node(sounds, &tmp, sound_cmp_by_name);
	if (node != NULL) {
		sound = ((sound_t *)(node->data))->sound;
		sfSound_play(sound);
	}
}
