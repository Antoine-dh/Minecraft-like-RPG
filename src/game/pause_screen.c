/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include "ui.h"
#include "game.h"

void exit_pause(game_t *game)
{
	get_ui_by_name(game, PAUSE_SCREEN_NAME)->draw = 0;
	switch_cursor_lock(game->cam);
	game->pause = 0;
}

void goto_menu(game_t *game)
{
	initialize_loading_screen(game);
	switch_cursor_lock(game->cam);
	get_ui_by_name(game, DEATH_SCREEN)->draw = 0;
	game->player->entity.health_point = BEGIN_LIFE_MAX;
	game->player->entity.position.x = game->map->spawn.x;
	game->player->entity.position.y = game->map->spawn.y;
	game->player->entity.position.z = game->map->spawn.z;
}