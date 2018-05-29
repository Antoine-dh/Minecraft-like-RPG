/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include "game.h"

void check_player_level(game_t *game)
{
	if (game->player->entity.health_point <= 0) {
		game->player->entity.health_point = 0;
		if (get_ui_by_name(game, DEATH_SCREEN)->draw == 0) {
			get_ui_by_name(game, DEATH_SCREEN)->draw = 1;
			switch_cursor_lock(game->cam);
			game->pause = 1;
		}
		return;
	}
	if (game->player->experience_actual >= game->player->experience_max) {
		if (game->player->level == 10)
			return;
		game->player->experience_max *= 2;
		game->player->experience_actual = 0;
		game->player->defense += 10;
		game->player->attack += 10;
		game->player->max_life += 20;
		game->player->entity.health_point = game->player->max_life;
		game->player->level++;
	}
}