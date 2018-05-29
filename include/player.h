/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#ifndef MY_RPG_PLAYER_H
#define MY_RPG_PLAYER_H

#include "camera.h"
#include "entity.h"

#define BEGIN_LIFE_ACTUAL 100
#define BEGIN_LIFE_MAX 100
#define BEGIN_DEFENSE 10
#define BEGIN_ATTACK 10
#define BEGIN_LEVEL 1
#define BEGIN_EXPERIENCE_ACTUAL 0
#define BEGIN_EXPERIENCE_MAX 200

typedef struct player {
	entity_t entity;
	camera_t *cam;
	sfBool godmode;
	int level;
	int selection;
	int attack;
	int defense;
	int max_life;
	int experience_actual;
	int experience_max;
	void (*click_handler)();
} player_t;

player_t *player_create(camera_t *cam, sfVector3f *pos);
void player_update(game_t *game, player_t *player);
void player_move(player_t *player, int key, float dt, sfVector3f *dir);
void attack_management(game_t *game);
void check_player_level(game_t *game);

static const float JUMP_FORCE = 11.0f;

static const sfKeyCode DIRECTION_KEYS[] = {
	sfKeyZ,
	sfKeyS,
	sfKeyQ,
	sfKeyD,
	sfKeySpace,
	sfKeyLShift
};

static const sfVector3f DIRECTION_VECTORS[] = {
	{1, 0, 1},
	{-1, 0, -1},
	{1, 0, 1},
	{-1, 0, -1},
	{0, 1, 0},
	{0, -1, 0},
};

#endif //MY_RPG_PLAYER_H
