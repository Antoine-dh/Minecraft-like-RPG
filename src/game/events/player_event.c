/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <SFML/Window.h>
#include "game.h"

void player_mouse_events(game_t *game, sfEvent *event)
{
	if (event->type == sfEvtMouseButtonPressed) {
		if (event->mouseButton.button == sfMouseLeft)
			instantiate_projectile(game, game->player);
	} else if (event->type == sfEvtMouseWheelScrolled)
		scroll_mouse_toolbar(game, (int)event->mouseWheelScroll.delta);
}

void player_key_events(UNUSED game_t *game, UNUSED sfEvent *event)
{
	ui_t *ui = get_ui_by_name(game, PAUSE_SCREEN_NAME);

	if (event->key.code == sfKeyEscape) {
		if (get_ui_by_name(game, LOADING_SCREEN_NAME)->draw == 0 &&
			get_ui_by_name(game, DEATH_SCREEN)->draw == 0) {
			ui->draw = (ui->draw == 0 ? 1 : 0);
			switch_cursor_lock(game->cam);
			game->pause = (game->pause == 0 ? 1 : 0);
		}
	}
}
