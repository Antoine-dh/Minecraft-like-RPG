/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh, lucas_ben
*/

#ifndef MY_RPG_ENTITY_T_H
#define MY_RPG_ENTITY_T_H

#include "physics.h"
#include "my.h"
#include "model.h"

typedef struct game game_t;

typedef struct entity {
	sfVector3f position;
	sfVector3f scale;
	sfVector3f rotation;
	sfVector3f force;
	sfTexture *texture;
	int frame_index;
	animodel_t *model;
	hitbox_t hitbox;
	sfBool grounded;
	float health_point;
	sfVector3f knockback_coefficient;
	char *sound;
	int attack;
	float hit_rate;
	float cooldown;
} entity_t;

entity_t *entity_create(animodel_t *anim, sfTexture *texture,
	const sfVector3f *scale);
int entity_draw(entity_t *entity);
void entity_update(game_t *game, entity_t *entity);
void player_entity_update(game_t *game, entity_t *entity);
int no_hp(void *data, void *current);
void entity_hit(game_t *game, entity_t *entity);
void draw_face(face_t *face, bool_t texture);
void entity_attack(game_t *game, entity_t *entity);

#endif //MY_RPG_ENTITY_T_H