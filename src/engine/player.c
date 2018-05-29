/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"

void player_update(game_t *game, player_t *player)
{
	sfVector3f dir = vector3_sub(&player->cam->look_at, &player->cam->pos);

	for (size_t i = 0 ; i < LEN(DIRECTION_KEYS) ; ++i)
		if (sfKeyboard_isKeyPressed(DIRECTION_KEYS[i]))
			player_move(player, (int)i, game->dt, &dir);
	if (game->player->entity.grounded &&
		sfKeyboard_isKeyPressed(sfKeySpace))
		game->player->entity.force.y += JUMP_FORCE;
	player->cam->pos = player->entity.position;
	player->cam->pos.y += player->entity.hitbox.size.y - 0.15f;
	entity_update(game, &player->entity);
}

player_t *player_create(camera_t *cam, sfVector3f *pos)
{
	player_t *player = malloc(sizeof(player_t));

	if (player == NULL)
		return (NULL);
	memset(player, 0, sizeof(player_t));
	player->entity.scale = (sfVector3f){1, 1, 1};
	player->entity.hitbox = (hitbox_t){{-0.25f, 0, -0.25f},
		{0.5, 1.8, 0.5}};
	player->entity.position = *pos;
	player->entity.health_point = 100;
	player->entity.knockback_coefficient = (sfVector3f){0, 0, 0};
	player->cam = cam;
	player->attack = 4;
	player->selection = 1;
	return (player);
}

void player_move(player_t *player, int key, UNUSED float dt, sfVector3f *dir)
{
	const sfVector3f up = {0, 1, 0};
	sfVector3f new_dir = *dir;

	if (key == 0 || key == 1) {
		new_dir.y = 0;
		new_dir = vector3_normalize(&new_dir);
	} else if (key == 2 || key == 3) {
		new_dir = vector3_cross_product(&up, &new_dir);
		new_dir = vector3_normalize(&new_dir);
	} else
		new_dir.y = 1;
	player->entity.force.x += DIRECTION_VECTORS[key].x * new_dir.x * 4.5f;
	player->entity.force.z += DIRECTION_VECTORS[key].z * new_dir.z * 4.5f;
}
