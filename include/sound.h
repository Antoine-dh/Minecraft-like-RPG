/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_SOUND_H
#define MY_RPG_SOUND_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "list.h"

typedef struct {
	char *name;
	sfSound *sound;
	sfSoundBuffer *buffer;
} sound_t;

sound_t *load_sound(const char *name);
int sound_cmp_by_name(sound_t *a, sound_t *b);
void free_sound(sound_t *sound);
void sound_play(const char *name, list_t *sounds);

#endif //MY_RPG_SOUND_H
