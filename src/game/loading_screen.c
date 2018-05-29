/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Created by lubas_ben,
*/

#include "game.h"
#include "ui.h"

void dispose_ui_elements(game_t *game)
{
	ui_t *toolbar = get_ui_by_name(game, TOOLBAR_NAME);
	ui_t *inventory = get_ui_by_name(game, INVENTORY_NAME);
	ui_t *stats = get_ui_by_name(game, STATS_SCREEN);
	sfVector2u win_size = sfRenderWindow_getSize(game->window);

	inventory->panel->draw_position.x = win_size.x -
		inventory->panel->template->size.x - 10;
	inventory->panel->draw_position.y = 50 +
		stats->panel->template->size.y + 5;
	toolbar->panel->draw_position = (sfVector2f){
		win_size.x / 2 - (4 * 64 + 32), win_size.y - 64};
	stats->panel->draw_position.x = win_size.x -
		stats->panel->template->size.x - 10;
	stats->panel->draw_position.y = 50;
}

void remove_loading_screen(game_t *game)
{
	get_ui_by_name(game, LOADING_SCREEN_NAME)->draw = 0;
	get_ui_by_name(game, CROSSBAR_NAME)->draw = 1;
	get_ui_by_name(game, TOOLBAR_NAME)->draw = 1;
	get_ui_by_name(game, LOADING_NEW_MAP_SCREEN)->draw = 0;
	get_ui_by_name(game, STATS_SCREEN)->draw = 1;
	get_ui_by_name(game, INVENTORY_NAME)->draw = 1;
	dispose_ui_elements(game);
	set_under_slot_image(game, 1, 2);
	game->player->level = BEGIN_LEVEL;
	game->player->attack = BEGIN_ATTACK;
	game->player->defense = BEGIN_DEFENSE;
	game->player->experience_actual = BEGIN_EXPERIENCE_ACTUAL;
	game->player->experience_max = BEGIN_EXPERIENCE_MAX;
	game->player->max_life = BEGIN_LIFE_MAX;
	game->player->entity.health_point = BEGIN_LIFE_ACTUAL;
	switch_cursor_lock(game->cam);
}

void initialize_loading_screen(game_t *game)
{
	switch_cursor_lock(game->cam);
	get_ui_by_name(game, CROSSBAR_NAME)->draw = 0;
	get_ui_by_name(game, TOOLBAR_NAME)->draw = 0;
	get_ui_by_name(game, LOADING_NEW_MAP_SCREEN)->draw = 0;
	get_ui_by_name(game, STATS_SCREEN)->draw = 0;
	get_ui_by_name(game, INVENTORY_NAME)->draw = 0;
	get_ui_by_name(game, PAUSE_SCREEN_NAME)->draw = 0;
	get_ui_by_name(game, LOADING_SCREEN_NAME)->draw = 1;
	game->pause = 0;
}