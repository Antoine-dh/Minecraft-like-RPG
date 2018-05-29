/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by antoine_dh,
*/

#include <SFML/Window.h>
#include "game.h"
#include "raycasting.h"
#include "events.h"

void godmode_events(game_t *game, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed)
		godmode_key_events(game, event);
	else if (event->type == sfEvtMouseWheelScrolled ||
		event->type == sfEvtMouseButtonPressed)
		godmode_mouse_events(game, event);
}

void player_events(game_t *game, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed)
		player_key_events(game, event);
	else if (event->type == sfEvtMouseWheelScrolled ||
		event->type == sfEvtMouseButtonPressed)
		player_mouse_events(game, event);
}

void handle_events(game_t *game, sfEvent *event)
{
	if (event->type == sfEvtClosed)
		sfRenderWindow_close(game->window);
	if (event->type == sfEvtLostFocus)
		sfRenderWindow_setFramerateLimit(game->window, 10);
	else if (event->type == sfEvtGainedFocus)
		sfRenderWindow_setFramerateLimit(game->window, 60);
	if (!game->player->cam->cursor_locked && event->key.code != sfKeyEscape)
		return;
	if (game->player->godmode)
		godmode_events(game, event);
	else
		player_events(game, event);
}
