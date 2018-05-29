/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_EVENTS_H
#define MY_RPG_EVENTS_H

#include <SFML/Graphics.h>

typedef struct game game_t;

void player_mouse_events(game_t *game, sfEvent *event);
void player_key_events(game_t *game, sfEvent *event);

void godmode_key_events(game_t *game, sfEvent *event);
void godmode_mouse_events(game_t *game, sfEvent *event);

#endif //MY_RPG_EVENTS_H
