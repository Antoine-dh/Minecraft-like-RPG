/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"
#include "spawner.h"
#include "lightning.h"

void sub_update_game(game_t *game)
{
	check_player_level(game);
	update_teleporters(game);
	update_npc(game, game->npc);
	player_update(game, game->player);
	camera_update(game->cam);
	for (list_t *tmp = game->projectile ; tmp != NULL ; tmp = tmp->next)
		update_projectile(game, tmp->data);
	for (list_t *tmp = game->particle_systems ; tmp ; tmp = tmp->next)
		particle_sys_update(tmp->data, &game->particles, game->dt);
	for (list_t *tmp = game->active_quests ; tmp != NULL ; tmp = tmp->next)
		update_quest(game, tmp->data);
}

static void update_ai_entity(game_t *game, entity_t *entity)
{
	sfVector3f dir = vector_from_angle(
		&(sfVector2f){(entity)->rotation.y, (entity)->rotation.x});

	entity_lookat(entity, &game->cam->pos, &(sfVector3f){1, 1, 0});
	(entity)->force.x += dir.x * game->dt * 60.0f;
	(entity)->force.y += dir.y * game->dt * 60.0f;
	(entity)->force.z += dir.z * game->dt * 60.0f;
	entity_attack(game, entity);
	entity_update(game, entity);
}

void update_game(game_t *game)
{
	handle_mouse(game, game->cam, game->window);
	if (game->pause) {
		update_ui(game);
		return;
	}
	sub_update_game(game);
	for (list_t *tmp = game->entities ; tmp != NULL ; tmp = tmp->next)
		update_ai_entity(game, tmp->data);
	if (game->map->spawners != NULL &&
		list_size(game->map->spawners) < MAX_ENTITY &&
		!game->player->godmode)
		for (list_t *tmp = game->map->spawners ; tmp ; tmp = tmp->next)
			if (tmp->data != NULL)
				update_spawner(game, tmp->data);
	destroy_non_used(game);
	update_ui(game);
}

int run_game(game_t *game)
{
	sfEvent event;
	sfClock *dt_clock = sfClock_create();

	while (sfRenderWindow_isOpen(game->window)) {
		while (sfRenderWindow_pollEvent(game->window, &event))
			handle_events(game, &event);
		if (sfRenderWindow_hasFocus(game->window)) {
			update_game(game);
			draw_game(game);
		}
		game->dt = TO_SEC(sfClock_restart(dt_clock).microseconds);
		game->elapsed += game->dt;
		if (game->dt > 1.0f / 10.0f)
			game->dt = 1.0f / 10.0f;
	}
	sfClock_destroy(dt_clock);
	free_game(game);
	return (0);
}