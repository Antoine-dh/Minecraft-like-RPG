/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include "game.h"

void godmode_mouse_events(game_t *game, sfEvent *event)
{
	if (event->type == sfEvtMouseButtonPressed) {
		if (event->mouseButton.button == sfMouseLeft)
			break_block(game);
		if (event->mouseButton.button == sfMouseRight)
			place_block(game, game->map);
	} else if (event->type == sfEvtMouseWheelScrolled) {
		game->player->selection += event->mouseWheelScroll.delta;
		game->player->selection = CLAMP(game->player->selection, 1,
			LEN(BLOCKS) - 1);
	}
}

void godmode_key_events(game_t *game, sfEvent *event)
{
	ui_t *ui = get_ui_by_name(game, PAUSE_SCREEN_NAME);

	if (event->key.code == sfKeyEscape) {
		if (get_ui_by_name(game, LOADING_SCREEN_NAME)->draw == 0 &&
			get_ui_by_name(game, DEATH_SCREEN)->draw == 0) {
			ui->draw = (ui->draw == 0 ? 1 : 0);
			switch_cursor_lock(game->cam);
		}
	}
	if (event->key.code == sfKeyF1)
		save_map(game->map, "out.map");
	if (event->key.code == sfKeyF2)
		game->player->entity.position.y += 10.0f;
}
